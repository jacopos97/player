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

bool Playlist::isLoop() const {
    return loop;
}


bool Playlist::isShuffle() const {
    return shuffle;
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

std::list<AudioTrack*>::iterator Playlist::getAudioTrack(int pos) {
    auto it = audioTracks.begin();
    int i = 0;
    while (i != pos ) {
        it++;
        i++;
    }
    return it;
}

unsigned long Playlist::getSize() const {
    return audioTracks.size();
}

void Playlist::changeName(wxString n) {
    name = n;
}

wxArrayString Playlist::getArrayString() {
    return audioTracksTitles;
}

int Playlist::checkAudioTrackPresence(wxString audioTrackTitle) {
    if(getBeginIterator() != getEndIterator()) {
        auto it = getBeginIterator();
        auto endIterator = getEndIterator();
        int temp = static_cast<int>(getSize());
        for(int index = 0; index < getSize(); index++) {
            if ((*it)->getFileName() == audioTrackTitle)
                temp = index;
            it++;
        }
        return temp;
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

int Playlist::getRandomAudioTrack(std::list<AudioTrack*>::iterator au) {
    int minNumbAudioTrack = 1;
    if (audioTracks.size() == minNumbAudioTrack) {
        minNumbAudioTrack--;
        return minNumbAudioTrack;
    }
    else {
        srand(time(NULL));
        int randValue = static_cast<int>(rand() % audioTracks.size());
        if (getAudioTrack(randValue) == au) {
            //randValue = getRandomAudioTrack(au);
            randValue++;
            if (randValue == audioTracks.size())
                randValue = 0;
        }
        return randValue;
    }
}







