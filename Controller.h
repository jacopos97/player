//
// Created by jacopo on 04/11/18.
//

#ifndef MP3_CONTROLLER_H
#define MP3_CONTROLLER_H


class Controller {
public:
    virtual void playAudioTrack() = 0;
    virtual void restart() = 0;
    virtual void pause() =  0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void move() = 0;
};

#endif //MP3_CONTROLLER_H
