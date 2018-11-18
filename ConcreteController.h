//
// Created by jacopo on 07/11/18.
//

#ifndef MP3_CONCRETECONTROLLER_H
#define MP3_CONCRETECONTROLLER_H

#include "Controller.h"

template <typename T>
class ConcreteController : public Controller {
public:
    void playAudioTrack() override;
    void restart() override;
    void pause() override;
    void add() override;
    void remove() override;
    void move() override;

private:
    T* object;
};


#endif //MP3_CONCRETECONTROLLER_H
