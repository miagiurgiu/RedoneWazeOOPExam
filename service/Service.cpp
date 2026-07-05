//
// Created by Maria on 05/07/2026.
//

#include "Service.h"

Service::Service(Repository &repo):repo{repo} {
}

std::vector<Driver> Service::getDrivers() const {
    return repo.getDrivers();
}

std::vector<Report> Service::getReports() const {
    return repo.getReports();
}

std::vector<Report> Service::getReportsForRegion(const Driver &d,int radius) const {
    int driverLatitude=d.getLatitude();
    int driverLongitude=d.getLongitude();
    std::vector<Report> result;
    for (const auto& r:repo.getReports()) {
        int reportLatitude=r.getLatitude();
        int reportLongitude=r.getLongitude();
        double distance=sqrt((reportLatitude-driverLatitude)*(reportLatitude-driverLatitude) + (reportLongitude-driverLongitude)*(reportLongitude-driverLongitude));
        if (distance<=radius) {
            result.push_back(r);
        }
    }
    return result;
}

void Service::addReport(const std::string &description, const Driver& driver, int latitude, int longitude,
    bool validationStatus) {
    if (description.empty())
        throw std::runtime_error("description is empty");
    int driverLatitude=driver.getLatitude();
    int driverLongitude=driver.getLongitude();
    double distance=sqrt((latitude-driverLatitude)*(latitude-driverLatitude) + (longitude-driverLongitude)*(longitude-driverLongitude));
    if (distance>=20.0)
        throw std::runtime_error("more than 20 units away");
    repo.addReport(description,driver.getName(),latitude,longitude,validationStatus);
    notify();
}

void Service::validateReport(const std::string &report, const Driver &driver) {
    for (const auto& r:repo.getReports()) {
        if (r.toString()==report) {
            if (r.getValidationStatus()==true)
                throw std::runtime_error("already validated");
        }
    }
    repo.validateReport(report,driver);
    notify();
}

void Service::moveDriver(const Driver &driver, int latitude, int longitude) {
    repo.moveDriver(driver,latitude,longitude);
    notify();
}
