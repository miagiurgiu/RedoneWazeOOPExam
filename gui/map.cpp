//
// Created by Maria on 05/07/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Map.h" resolved

#include "map.h"
#include "ui_Map.h"
#include <QPainter>

Map::Map(Service& service,QWidget *parent) :
    QWidget(parent), ui(new Ui::Map),service{service} {
    ui->setupUi(this);
    service.registerObserver(this);
    Map::update();
}

Map::~Map() {
    service.unregisterObserver(this);
    delete ui;
}

void Map::update() {
    repaint();
}

void Map::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawRect(10,10,280,280);
    int x=10;
    int y=10;
    for (const auto& d:service.getDrivers()) {
        int latitude=d.getLatitude();
        int longitude=d.getLongitude();
        painter.drawText(x+10*latitude,y+10*longitude,QString::fromStdString(d.getName()));
        painter.drawText(x+10*latitude,y+10*longitude+11,"("+QString::number(d.getLatitude())+","+QString::number(d.getLongitude())+")");
    }
}
