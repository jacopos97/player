//
// Created by jacopo on 08/11/18.
//
#ifndef MP3_AUDIOTRACKOBSERVER_H
#define MP3_AUDIOTRACKOBSERVER_H

#include <wx/string.h>
#include <wx/gdicmn.h>
#include "Observer.h"
#include "AudioTrack.h"



class AudioTrackObserver : public Observer {
public:
    AudioTrackObserver(AudioTrack* au);

   // void update() override;
    void display();
    ~AudioTrackObserver() override = default ;

private:
    AudioTrack* audioTrack;

   // int audioTrackTime;
    //int currentAudioTrackTime;
    //std::string audioTrackTitle;
    //std::string audioTrackAuthor;
    //std::string audioTrackImage;



};

#endif //MP3_AUDIOTRACKOBSERVER_H
