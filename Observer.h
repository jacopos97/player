//
// Created by jacopo on 03/11/18.
//

#ifndef MP3_OBSERVER_H
#define MP3_OBSERVER_H

class Observer {
public:
    //Observer() = default;
    virtual void update() = 0;

protected:
    virtual ~Observer() {} ;
};

#endif //MP3_OBSERVER_H
