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
