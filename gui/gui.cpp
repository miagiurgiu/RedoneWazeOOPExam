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
    populateList();
}

void GUI::connectSignalsAndSlots() {
    connect(ui->addButton,&QPushButton::clicked,this,&GUI::addReport);
}

void GUI::populateList() {
    ui->reportsListWidget->clear();
    auto reports=service.getReportsForRegion(driver);
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
