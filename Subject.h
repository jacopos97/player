//
// Created by jacopo on 03/11/18.
//

#ifndef MP3_SUBJECT_H
#define MP3_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver (Observer* o) ;
    virtual void removeObserver (Observer* o) ;
    virtual void notifyObserver(Observer* o) const ;

protected:
    virtual ~Subject() = 0 {};
};




#endif //MP3_SUBJECT_H
