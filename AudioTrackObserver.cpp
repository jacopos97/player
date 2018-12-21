//
// Created by jacopo on 08/11/18.
//

#include "AudioTrackObserver.h"


void AudioTrackObserver::update() {
    currentAudioTrackTime = audioTrack->getCurrentTime();
    display();
}


void AudioTrackObserver::display() {

}

