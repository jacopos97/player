//
// Created by jacopo on 03/11/18.
//

#ifndef MP3_OBSERVER_H
#define MP3_OBSERVER_H

#include "Controller.h"

class Observer {
public:
    virtual void update() = 0;// lista di parametri??

protected:
    virtual ~Observer() = default;
};

#endif //MP3_OBSERVER_H
