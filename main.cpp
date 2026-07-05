//
// Created by Maria on 05/07/2026.
//
#include <QApplication>

#include "gui/gui.h"
#include "repo/Repository.h"
#include "service/Service.h"

int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    Repository repo{"../drivers.txt","../reports.txt"};
    Service service{repo};
    std::vector<GUI*> windows;
    for (const auto& d:service.getDrivers()) {
        GUI* gui=new GUI{service,d};
        gui->show();
        windows.push_back(gui);
    }
    return app.exec();
}
