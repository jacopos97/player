//
// Created by jacopo on 08/11/18.
//
#ifndef MP3_AUDIOTRACKOBSERVER_H
#define MP3_AUDIOTRACKOBSERVER_H

#include <wx/string.h>
#include <wx/gdicmn.h>
#include "Observer.h"
#include "DisplayElements.h"
#include "AudioTrack.h"



class AudioTrackObserver : public Observer, public DisplayElements {
public:
    explicit AudioTrackObserver(AudioTrack *au) : audioTrack(au), audioTrackTime(au->getAudioTrackTime()), currentAudioTrackTime(au->getCurrentTime()), audioTrackAuthor(au->getAuthor()), audioTrackImage(au->getImage()), audioTrackTitle(au->getTitle()) {};
    void update() override;
    void display() override;
    ~AudioTrackObserver() override = default ;

private:
    AudioTrack* audioTrack;

    const int audioTrackTime;
    int currentAudioTrackTime;
    const std::string audioTrackTitle;

    const std::string audioTrackAuthor;
    const std::string audioTrackImage;



};

#endif //MP3_AUDIOTRACKOBSERVER_H
