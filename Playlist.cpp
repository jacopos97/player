//
// Created by jacopo on 21/10/18.
//

#include "Playlist.h"


void Playlist::addTrack(AudioTrack audioTrack) {
    audioTracks.push_back(audioTrack);
}


void Playlist::removeTrack(AudioTrack audioTrack) {
    audioTracks.remove(audioTrack);
}



void Playlist::moveTrack(std::list<AudioTrack>::iterator selectedAudioTrack, std::list<AudioTrack>::iterator desiredPosition) {
    auto it = selectedAudioTrack;
    it--;
    std::next(it,1) = std::next(it,2);
    std::next(selectedAudioTrack,1) = std::next(desiredPosition,1);
    std::next(desiredPosition,1) = selectedAudioTrack;
}




void Playlist::playAudioTrack(AudioTrack audioTrack) {
    auto desiredAudioTrackIterator = audioTracks.begin();
    while (*desiredAudioTrackIterator == audioTrack || desiredAudioTrackIterator != audioTracks.end())
        desiredAudioTrackIterator++;
    if (desiredAudioTrackIterator != audioTracks.end()){
        if (!shuffle){
            auto it = desiredAudioTrackIterator;
            while (it != audioTracks.end()) {
                it->playAudioTrack();
                it++;
            }
        }
        else {
            std::list <AudioTrack> copyAudioTracks;
            auto copyIterator = audioTracks.begin();
            std::list<AudioTrack>::iterator copyDesiredAudioTrackIterator;
            while (copyIterator != audioTracks.end()) {
                copyAudioTracks.push_back(*copyIterator);
                if (copyIterator == desiredAudioTrackIterator){
                    copyDesiredAudioTrackIterator = copyAudioTracks.end();
                    copyDesiredAudioTrackIterator--;
                }
                copyIterator++;
            }
            copyDesiredAudioTrackIterator->playAudioTrack();
            copyAudioTracks.erase(copyDesiredAudioTrackIterator);
            srand(time(NULL));
            unsigned long randValue;
            while (copyAudioTracks.begin() != copyAudioTracks.end()){
                randValue = rand()%copyAudioTracks.size() + 1;
                auto it = copyAudioTracks.begin();
                unsigned long i = 1;
                while (i != randValue) {
                    it++;
                    i++;
                }
                it->playAudioTrack();
                copyAudioTracks.erase(it);
            }
        }
        if (loop)
            this->play();
    }
}




void Playlist::play() {
    auto it = audioTracks.begin();
    if (!shuffle){
        while (it != audioTracks.end()){
            it->playAudioTrack();
            it++;
        }
    }
    else{
        std::list <AudioTrack> copyAudioTracks;
        auto copyIterator = audioTracks.begin();
        while (copyIterator != audioTracks.end()) {
            copyAudioTracks.push_back(*copyIterator);
            copyIterator++;
        }
        srand(time(NULL));
        unsigned long randValue;
        while (copyAudioTracks.begin() != copyAudioTracks.end()){
            randValue = rand()%copyAudioTracks.size() + 1;
            auto it1 = copyAudioTracks.begin();
            unsigned long i = 1;
            while (i != randValue) {
                it1++;
                i++;
            }
            it1->playAudioTrack();
            copyAudioTracks.erase(it1);
        }
    }
    if (loop)
        this->play();
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

AudioTrack Playlist::getAudioTrack(unsigned long pos) {
    auto it = audioTracks.begin();
    unsigned long i = 1;
    while (i != pos ) {
        it++;
        i++;
    }
    return *it;
}

unsigned long Playlist::getSize() const {
    return audioTracks.size();
}

void Playlist::registerObserver(Observer *o) {
    observers.push_back(o);
}

void Playlist::removeObserver(Observer *o) {
    observers.remove(o);
}

void Playlist::notifyObserver() {
    auto it = observers.begin();
    while (it != observers.end()) {
        (*it)->update();
        it++;
    }
}

void Playlist::changeName(std::string n) {
    name = std::move(n);
}







