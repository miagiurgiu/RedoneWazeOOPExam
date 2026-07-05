//
// Created by Maria on 05/07/2026.
//

#include "Repository.h"
#include <fstream>
#include <sstream>


Repository::Repository(const std::string &driversFile, const std::string &reportsFile):driversFile{driversFile},reportsFile{reportsFile} {
    loadDrivers();
    loadReports();
}

std::vector<Driver> Repository::getDrivers() const {
    return drivers;
}

std::vector<Report> Repository::getReports() const {
    return reports;
}

void Repository::loadDrivers() {
    std::ifstream fin(driversFile);
    if (!fin.is_open())
        throw std::runtime_error("coudl not open");
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);
        std::string name,status,latitudeString,longitudeString,scoreString;
        std::getline(ss,name,',');
        std::getline(ss,status,',');
        std::getline(ss,latitudeString,',');
        std::getline(ss,longitudeString,',');
        std::getline(ss,scoreString);

        int latitude=std::stoi(latitudeString);
        int longitude=std::stoi(longitudeString);
        int score=std::stoi(scoreString);

        drivers.emplace_back(name,status,latitude,longitude,score);
    }
    fin.close();
}

void Repository::loadReports() {
    std::ifstream fin(reportsFile);
    if (!fin.is_open())
        throw std::runtime_error("could not open");
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);
        std::string description,reporter,latitudeString,longitudeString,validationString;
        std::getline(ss,description,',');
        std::getline(ss,reporter,',');
        std::getline(ss,latitudeString,',');
        std::getline(ss,longitudeString,',');
        std::getline(ss,validationString);

        int latitude=std::stoi(latitudeString);
        int longitude=std::stoi(longitudeString);
        bool validation;
        if (validationString=="true")
            validation=true;
        else
            validation=false;
        reports.emplace_back(description,reporter,latitude,longitude,validation);
    }
    fin.close();
}

void Repository::saveDrivers() {
    std::ofstream fout(driversFile);
    for (const auto& d:drivers) {
        fout<<d.toString()<<"\n";
    }
    fout.close();
}

void Repository::saveReports() {
    std::ofstream fout(reportsFile);
    for (const auto& r:reports) {
        fout<<r.toString()<<"\n";
    }
    fout.close();
}

void Repository::addReport(const std::string &description, const std::string &reporter, int latitude, int longitude,
    bool validationStatus) {
    Report newReport{description,reporter,latitude,longitude,validationStatus};
    reports.push_back(newReport);
    saveReports();
}
