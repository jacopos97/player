//
// Created by jacopo on 18/11/18.
//

#ifndef MP3_SUBJECT_H
#define MP3_SUBJECT_H


#include <list>
#include "Observer.h"


class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void notifyObserver() = 0;
protected:
    virtual ~Subject() {};
};



#endif //MP3_SUBJECT_H
