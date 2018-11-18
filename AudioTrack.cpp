//
// Created by jacopo on 19/10/18.
//

#include "AudioTrack.h"

void AudioTrack::playAudioTrack() {

}



void AudioTrack::restart() {
    currentTime = 0;
    this->playAudioTrack();
}



void AudioTrack::pause() {

}

AudioTrack::~AudioTrack() {

}

bool AudioTrack::operator==(const AudioTrack a) {
    return (audioTrackTime == a.audioTrackTime && author == a.author && title == a.title && image == a.image);
}

bool AudioTrack::operator!=(const AudioTrack a) {
    return (audioTrackTime != a.audioTrackTime || author != a.author || title != a.title || image != a.image);
}

double AudioTrack::getCurrentTime() const {
    return currentTime;
}

double AudioTrack::getAudioTrackTime() const {
    return audioTrackTime;
}

const std::string &AudioTrack::getTitle() const {
    return title;
}

const std::string &AudioTrack::getFileName() const {
    return fileName;
}

const std::string &AudioTrack::getAuthor() const {
    return author;
}


