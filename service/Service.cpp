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

std::vector<Report> Service::getReportsForRegion(const Driver &d) const {
    int driverLatitude=d.getLatitude();
    int driverLongitude=d.getLongitude();
    std::vector<Report> result;
    for (const auto& r:repo.getReports()) {
        int reportLatitude=r.getLatitude();
        int reportLongitude=r.getLongitude();
        double distance=sqrt((reportLatitude-driverLatitude)*(reportLatitude-driverLatitude) + (reportLongitude-driverLongitude)*(reportLongitude-driverLongitude));
        if (distance<=10.0) {
            result.push_back(r);
        }
    }
    return result;
}
