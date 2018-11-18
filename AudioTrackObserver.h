//
// Created by jacopo on 08/11/18.
//

#ifndef MP3_AUDIOTRACKOBSERVER_H
#define MP3_AUDIOTRACKOBSERVER_H

#include "Observer.h"
#include "DisplayElements.h"
#include "AudioTrack.h"


class AudioTrackObserver : public Observer, public DisplayElements {
public:
    void update() override;
    void display();

private:
    AudioTrack* audioTrack;
};


#endif //MP3_AUDIOTRACKOBSERVER_H
