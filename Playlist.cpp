//
// Created by jacopo on 21/10/18.
//

#include "Playlist.h"


void Playlist::addTrack(AudioTrack audioTrack) {
    audioTracks.push_back(audioTrack);
}


void Playlist::removeTrack(AudioTrack audioTrack) {
    auto it = audioTracks.begin();
    while (*it != audioTrack && it != audioTracks.end())
        it++;
    if (*it == audioTrack)
        audioTracks.erase(it);
}



void Playlist::moveTrack(std::list<AudioTrack>::iterator selectedAudioTrack, std::list<AudioTrack>::iterator desiredPosition) {
    auto it = selectedAudioTrack;
    it--;
    std::next(it,1) = std::next(it,2);
    std::next(selectedAudioTrack,1) = std::next(desiredPosition,1);
    std::next(desiredPosition,1) = selectedAudioTrack;
}




void Playlist::playAudioTrack(AudioTrack audioTrack) {
    auto it = audioTracks.begin();
    while (*it == audioTrack || it != audioTracks.end())
        it++;
    if (it != audioTracks.end()){
        if (!shuffle){
            while (it != audioTracks.end()) {
                it->playAudioTrack();
                it++;
            }
            if (loop)
                this->play();
        }
        else {//TODO: implement playAudioTrack() with shuffle
        }
    }
}




void Playlist::play() {
    auto it = audioTracks.begin();
    if (!shuffle){
        while (it != audioTracks.end()){
            it->playAudioTrack();
            it++;
        }
        if (loop)
            this->play();
    }
    else{//TODO: implement playAudioTrack() with shuffle
    }
}




bool Playlist::isLoop() const {
    return loop;
}




void Playlist::setLoop(bool loop) {
    Playlist::loop = loop;
}





bool Playlist::isShuffle() const {
    return shuffle;
}



void Playlist::setShuffle(bool shuffle) {
    Playlist::shuffle = shuffle;
}

Playlist::~Playlist() {

}

bool Playlist::operator==(const Playlist p) {
    if (name == p.name){
        auto it1 = audioTracks.begin();
        auto it2 = p.audioTracks.begin();
        while (it1 == it2 && it1 != audioTracks.end() && it2 != p.audioTracks.end()) {
            it1++;
            it2++;
        }
        if (it1 == audioTracks.end() && it2 == p.audioTracks.end())
            return true;
    }
    return false;
}

bool Playlist::operator!=(const Playlist p) {
    if (name == p.name){
        auto it1 = audioTracks.begin();
        auto it2 = p.audioTracks.begin();
        while (it1 == it2 && it1 != audioTracks.end() && it2 != p.audioTracks.end()) {
            it1++;
            it2++;
        }
        if (it1 == audioTracks.end() && it2 == p.audioTracks.end())
            return false;
    }
    return true;
}

const std::string &Playlist::getName() const {
    return name;
}

std::list<AudioTrack>::iterator Playlist::getBeginIterator() {
    return audioTracks.begin();
}

std::list<AudioTrack>::iterator Playlist::getEndIterator() {
    return audioTracks.end();
}




