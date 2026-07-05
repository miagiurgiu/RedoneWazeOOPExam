//
// Created by Maria on 05/07/2026.
//

#ifndef REDONEWAZEOOPEXAM_SERVICE_H
#define REDONEWAZEOOPEXAM_SERVICE_H
#include "domain/Subject.h"
#include "repo/Repository.h"


class Service:public Subject {
private:
    Repository& repo;
public:
    Service(Repository& repo);
    std::vector<Driver> getDrivers() const;
    std::vector<Report> getReports() const;
    std::vector<Report> getReportsForRegion(const Driver& d,int radius) const;
    void addReport(const std::string& description,const Driver& driver,int latitude,int longitude,bool validationStatus);
    void validateReport(const std::string& report,const Driver& driver);
    void moveDriver(const Driver& driver,int latitude,int longitude);
};



#endif //REDONEWAZEOOPEXAM_SERVICE_H
