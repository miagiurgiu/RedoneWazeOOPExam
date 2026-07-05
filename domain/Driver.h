//
// Created by Maria on 05/07/2026.
//

#ifndef REDONEWAZEOOPEXAM_DRIVER_H
#define REDONEWAZEOOPEXAM_DRIVER_H
#include <string>


class Driver {
private:
    std::string name;
    std::string status;
    int latitude;
    int longitude;
    int score;
public:
    Driver(const std::string& name,const std::string& status,int latitude,int longitude,int score);
    std::string getName() const;
    std::string getStatus() const;
    int getLatitude() const;
    int getLongitude() const;
    int getScore() const;
    std::string toString() const;
    void setScore();
    void setStatus(const std::string& status);
    void setLatitude(int newLat);
    void setLongitude(int newLong);
};



#endif //REDONEWAZEOOPEXAM_DRIVER_H
