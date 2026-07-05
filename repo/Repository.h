//
// Created by Maria on 05/07/2026.
//

#ifndef REDONEWAZEOOPEXAM_REPOSITORY_H
#define REDONEWAZEOOPEXAM_REPOSITORY_H
#include <string>
#include <vector>

#include "domain/Driver.h"
#include "domain/Report.h"


class Repository {
private:
    std::string driversFile;
    std::string reportsFile;
    std::vector<Driver> drivers;
    std::vector<Report> reports;
public:
    Repository(const std::string& driversFile,const std::string& reportsFile);
    std::vector<Driver> getDrivers() const;
    std::vector<Report> getReports() const;
    void loadDrivers();
    void loadReports();
    void saveDrivers();
    void saveReports();
};



#endif //REDONEWAZEOOPEXAM_REPOSITORY_H
