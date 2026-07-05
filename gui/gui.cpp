//
// Created by Maria on 05/07/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QMessageBox>
#include <QPushButton>

GUI::GUI(Service& service, const Driver& driver,QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI),service{service},driver{driver} {
    ui->setupUi(this);
    service.registerObserver(this);
    this->setWindowTitle(QString::fromStdString(driver.getName()));
    ui->statusLabel->setText(QString::number(driver.getLatitude())+","+ QString::number(driver.getLongitude()) + "," + QString::fromStdString(driver.getStatus()));
    connectSignalsAndSlots();
    GUI::update();
}

GUI::~GUI() {
    service.unregisterObserver(this);
    delete ui;
}

void GUI::update() {
    // refresh the copy because we update stuff
    for (const auto& d:service.getDrivers()) {
        if (d.getName()==driver.getName()) {
            driver=d; // update the driver
            break;
        }
    }
    //(labels with coordinates/status should change)
    ui->statusLabel->setText(QString::number(driver.getLatitude())+","+ QString::number(driver.getLongitude()) + "," + QString::fromStdString(driver.getStatus()));
    populateList();
}

void GUI::connectSignalsAndSlots() {
    connect(ui->addButton,&QPushButton::clicked,this,&GUI::addReport);
    connect(ui->validateButton,&QPushButton::clicked,this,&GUI::validateReport);
    //connect(ui->reportsListWidget,&QListWidget::itemSelectionChanged,this,&GUI::validateReport);
    connect(ui->horizontalSlider,&QSlider::valueChanged,this,&GUI::radiusChanged);
    connect(ui->northButton,&QPushButton::clicked,this,&GUI::moveNorth);
    connect(ui->southButton,&QPushButton::clicked,this,&GUI::moveSouth);
    connect(ui->eastButton,&QPushButton::clicked,this,&GUI::moveEast);
    connect(ui->westButton,&QPushButton::clicked,this,&GUI::moveWest);
}

void GUI::populateList() {
    ui->reportsListWidget->clear();
    auto reports=service.getReportsForRegion(driver,radius);
    for (const auto& r:reports) {
        ui->reportsListWidget->addItem(QString::fromStdString(r.toString()));
    }
}

void GUI::addReport() {
    std::string description=ui->descriptionLineEdit->text().toStdString();
    int latitude=ui->latitudeLineEdit->text().toInt();
    int longitude=ui->longitudeLineEdit->text().toInt();
    try {
        service.addReport(description,driver,latitude,longitude,false);
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this,"ERROR",e.what());
    }
}

void GUI::validateReport() {
    auto selection=ui->reportsListWidget->selectedItems();
    if (selection.empty())
        return;
    std::string report=selection[0]->text().toStdString();
    try {
        service.validateReport(report,driver);
    }
    catch (const std::exception &e) {
        QMessageBox::critical(this,"ERROR",e.what());
    }
}

void GUI::radiusChanged(int value) {
    radius=value;
    populateList();
}

void GUI::moveNorth() {
    service.moveDriver(driver,1,0);
}

void GUI::moveSouth() {
    service.moveDriver(driver,-1,0);
}

void GUI::moveEast() {
    service.moveDriver(driver,0,1);
}

void GUI::moveWest() {
    service.moveDriver(driver,0,-1);
}
