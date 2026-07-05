//
// Created by Maria on 05/07/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


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
    return;
}

void GUI::populateList() {
    ui->reportsListWidget->clear();
    auto reports=service.getReportsForRegion(driver);
    for (const auto& r:reports) {
        ui->reportsListWidget->addItem(QString::fromStdString(r.toString()));
    }
}
