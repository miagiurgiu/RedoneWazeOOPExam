//
// Created by Maria on 05/07/2026.
//

#ifndef REDONEWAZEOOPEXAM_REPORT_H
#define REDONEWAZEOOPEXAM_REPORT_H

#include <string>

class Report {
private:
    std::string description;
    std::string reporter;
    int latitude;
    int longitude;
    bool validationStatus;
public:
    Report(const std::string& description,const std::string& reporter,int latitude,int longitude,bool validationStatus);
    std::string getDescription() const;
    std::string getReporter() const;
    int getLatitude() const;
    int getLongitude() const;
    bool getValidationStatus() const;
    std::string toString() const;
};



#endif //REDONEWAZEOOPEXAM_REPORT_H
