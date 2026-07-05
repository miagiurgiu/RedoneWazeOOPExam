//
// Created by Maria on 05/07/2026.
//

#ifndef REDONEWAZEOOPEXAM_MAP_H
#define REDONEWAZEOOPEXAM_MAP_H

#include <QWidget>

#include "domain/Observer.h"
#include "service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Map; }
QT_END_NAMESPACE

class Map : public QWidget,public Observer {
Q_OBJECT

public:
    explicit Map(Service& service,QWidget *parent = nullptr);
    ~Map() override;
    void update() override;
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::Map *ui;
    Service& service;
};


#endif //REDONEWAZEOOPEXAM_MAP_H
