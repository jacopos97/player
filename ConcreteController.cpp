//
// Created by jacopo on 07/11/18.
//

#include "ConcreteController.h"

void ConcreteController::playAudioTrack() {
    object->playAudioTrack;
}

void ConcreteController::restart() {
    object->restart();
}

void ConcreteController::pause() {
    object->pause();
}

void ConcreteController::move() {
    object->move();
}

void ConcreteController::add() {
    object->add();
}

void ConcreteController::remove() {
    object->remove();
}
