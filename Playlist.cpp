//
// Created by jacopo on 21/10/18.
//

#include "Playlist.h"


void Playlist::addTrack(AudioTrack* audioTrack) {
    auto au = new AudioTrack(*audioTrack);
    audioTracks.push_back(au);
    audioTracksTitles.Add((*au).getFileName());
}


void Playlist::removeTrack(int pos) {
    auto audioTrack = getBeginIterator();
    for (int index = 0; index < pos; index++)
        audioTrack++;

    delete *audioTrack;
    audioTracks.erase(audioTrack);
    audioTracksTitles.RemoveAt(static_cast<size_t>(pos));
}


/*
void Playlist::moveTrack(std::list<AudioTrack>::iterator selectedAudioTrackIterator, std::list<AudioTrack>::iterator desiredPositionIterator) {
    if (selectedAudioTrackIterator != desiredPositionIterator) {
        auto it1 = audioTracks.begin();
        int selectedAudioTrackPosition = 1;
        while (it1 == selectedAudioTrackIterator) {
            it1++;
            selectedAudioTrackPosition++;
        }
        auto it2 = audioTracks.begin();
        int desiredPosition = 1;
        while (it2 == desiredPositionIterator) {
            it2++;
            desiredPosition++;
        }
        auto it = selectedAudioTrackIterator;
        auto nextIt = std::next(selectedAudioTrackIterator);
        if (selectedAudioTrackPosition < desiredPosition) {
            std::next(selectedAudioTrackIterator) = std::next(desiredPositionIterator);
            std::next(desiredPositionIterator) = selectedAudioTrackIterator;
            if (selectedAudioTrackPosition > 1) {
                it--;
                std::next(it) = nextIt;
            }
        }
        else {
            it--;
            auto prevIt = it;
            std::next(it) = nextIt;
            std::next(selectedAudioTrackIterator) = desiredPositionIterator;
            if (desiredPosition > 1)
                std::next(prevIt) = selectedAudioTrackIterator;
        }

    }

}

*/


void Playlist::playAudioTrack(AudioTrack* audioTrack) {
    auto desiredAudioTrackIterator = audioTracks.begin();
    while (*desiredAudioTrackIterator == audioTrack || desiredAudioTrackIterator != audioTracks.end())
        desiredAudioTrackIterator++;
    if (desiredAudioTrackIterator != audioTracks.end()){
        if (!shuffle){
            auto it = desiredAudioTrackIterator;
            while (it != audioTracks.end()) {
                (*it)->playAudioTrack();
                it++;
            }
        }
        else {
            std::list <AudioTrack*> copyAudioTracks;
            auto copyIterator = audioTracks.begin();
            std::list<AudioTrack*>::iterator copyDesiredAudioTrackIterator;
            while (copyIterator != audioTracks.end()) {
                copyAudioTracks.push_back(*copyIterator);
                if (copyIterator == desiredAudioTrackIterator){
                    copyDesiredAudioTrackIterator = copyAudioTracks.end();
                    copyDesiredAudioTrackIterator--;
                }
                copyIterator++;
            }
            (*copyDesiredAudioTrackIterator)->playAudioTrack();
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
                (*it)->playAudioTrack();
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
            (*it)->playAudioTrack();
            it++;
        }
    }
    else{
        std::list <AudioTrack*> copyAudioTracks;
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
            (*it1)->playAudioTrack();
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


bool Playlist::operator==(const Playlist& p) const {
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

bool Playlist::operator!=(const Playlist& p) const {
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

const wxString &Playlist::getName() const {
    return name;
}

std::list<AudioTrack*>::iterator Playlist::getBeginIterator() {
    return audioTracks.begin();
}

std::list<AudioTrack*>::iterator Playlist::getEndIterator() {
    return audioTracks.end();
}

AudioTrack* Playlist::getAudioTrack(unsigned long pos) {
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

void Playlist::changeName(wxString n) {
    name = n;
}

wxArrayString Playlist::getArrayString() {
    return audioTracksTitles;
}

int Playlist::checkAudioTrackPresence(wxString audioTrackTitle) {
    if(getBeginIterator() != getEndIterator()) {
        //int index = 0;
        auto it = getBeginIterator();
        auto endIterator = getEndIterator();
        int temp = static_cast<int>(getSize());

        for(int index = 0; index < getSize(); index++) {
            if ((*it)->getFileName() == audioTrackTitle)
                temp = index;
            it++;
        }
        return temp;
        //int size = static_cast<int>(getSize());
        /*
        while ((*it)->getFileName() != audioTrackTitle && it != endIterator) {
            it++;
            index++;
        }
        if (it == endIterator)
            return static_cast<int>(getSize());
        else
            return index;
            */
    }
    else
        return static_cast<int>(getSize());
}

bool Playlist::checkPossibleDuplicateTrack(wxString audioTrackTitle) {
    bool duplicate = false;
    auto it = getBeginIterator();
    while (duplicate == false && it != getEndIterator()) {
        if ((*it)->getFileName() == audioTrackTitle)
            duplicate = true;
        it++;
    }
    return duplicate;
}







