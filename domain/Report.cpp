//
// Created by Maria on 05/07/2026.
//

#include "Report.h"


Report::Report(const std::string& description,const std::string& reporter,int latitude,int longitude,bool validationStatus):description{description},reporter{reporter},latitude{latitude},longitude{longitude},validationStatus{validationStatus}{
}
std::string Report::getDescription() const {
    return description;
}
std::string Report::getReporter() const {
    return reporter;
}
int Report::getLatitude() const {
    return latitude;
}
int Report::getLongitude() const {
    return longitude;
}
bool Report::getValidationStatus() const {
    return validationStatus;
}

std::string Report::toString() const {
    return description+","+reporter+","+std::to_string(latitude)+","+std::to_string(longitude)+","+std::to_string(validationStatus);
}
