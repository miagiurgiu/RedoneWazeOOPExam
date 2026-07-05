//
// Created by Maria on 05/07/2026.
//

#ifndef REDONEWAZEOOPEXAM_SUBJECT_H
#define REDONEWAZEOOPEXAM_SUBJECT_H
#include <vector>

#include "Observer.h"


class Subject {
private:
    std::vector<Observer*> observers;
public:
    Subject()=default;
    void registerObserver(Observer* obs);
    void unregisterObserver(Observer* obs);
    void notify();
};



#endif //REDONEWAZEOOPEXAM_SUBJECT_H
