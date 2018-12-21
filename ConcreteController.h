//
// Created by jacopo on 07/11/18.
//

#ifndef MP3_CONCRETECONTROLLER_H
#define MP3_CONCRETECONTROLLER_H

#include "Controller.h"

template <typename T>
class ConcreteController : public Controller {
public:
    explicit ConcreteController(T* obj) : object(obj) {};
    void playAudioTrack() override {
        object->playAudioTrack;
    }
    void restart() override {
        object->restart();
    }
    void pause() override {
        object->pause();
    }
    void add() override {
        object->add();
    }
    void remove() override {
        object->remove();
    }
    void move() override {
        object->move();
    }
    ~ConcreteController() override = default ;

private:
    T* object;
};


#endif //MP3_CONCRETECONTROLLER_H
