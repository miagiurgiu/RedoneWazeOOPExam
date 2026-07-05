//
// Created by Maria on 05/07/2026.
//

#ifndef REDONEWAZEOOPEXAM_GUI_H
#define REDONEWAZEOOPEXAM_GUI_H

#include <QWidget>

#include "domain/Observer.h"
#include "service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget,public Observer {
Q_OBJECT

public:
    explicit GUI(Service& service, const Driver& driver,QWidget *parent = nullptr);
    ~GUI() override;
    void update() override;

private:
    Ui::GUI *ui;
    Service& service;
    Driver driver;
    void connectSignalsAndSlots();
};


#endif //REDONEWAZEOOPEXAM_GUI_H
