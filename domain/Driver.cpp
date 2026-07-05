//
// Created by Maria on 05/07/2026.
//

#include "Driver.h"

Driver::Driver(const std::string &name, const std::string &status, int latitude, int longitude, int score):name{name},status{status},latitude{latitude},longitude{longitude},score{score} {
}

std::string Driver::getName() const {
    return name;
}

std::string Driver::getStatus() const {
    return status;
}

int Driver::getLatitude() const {
    return latitude;
}

int Driver::getLongitude() const {
    return longitude;
}

int Driver::getScore() const {
    return score;
}

std::string Driver::toString() const {
    return name+","+status+","+std::to_string(latitude)+","+std::to_string(longitude)+","+std::to_string(score);
}

void Driver::setScore() {
    this->score=this->score +1;
}

void Driver::setStatus(const std::string &status) {
    this->status=status;
}

void Driver::setLatitude(int newLat) {
    this->latitude=newLat;
}

void Driver::setLongitude(int newLong) {
    this->longitude=newLong;
}
