//
// Created by jacopo on 22/10/18.
//

#include "MusicLibrary.h"

void MusicLibrary::newPlaylist(wxString playlistName) {
    //Playlist playlist(playlistName);
    auto playlist = new Playlist(playlistName);
    playlists.push_back(playlist);
    /*
    auto it = playlists.end();
    it--;
    Playlist pl = *it;
     */
}

void MusicLibrary::removePlaylist(int pos) {
    auto it = playlists.begin();
        /*
    while (*it != playlist)
        it++;
        */
    for (int index = 0; index <= pos; index++)
        it++;
    /*
    auto temp = it;
    temp--;
    std::next(temp) = std::next(it); //chiedere se vale
    */
    delete *it;
    playlists.erase(it);
}
/*
void MusicLibrary::playPlaylist(Playlist playlist) {
    playlist.play();
}

void MusicLibrary::play() {
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
            randValue = rand() % copyAudioTracks.size() + 1;
            auto it1 = copyAudioTracks.begin();
            unsigned long i = 1;
            while (i != randValue) {
                it1++;
                i++;
            }
            (*it1)->playAudioTrack();
            copyAudioTracks.erase(it1);
        }
        if (loop)
            this->play();
    }
}
*/
bool MusicLibrary::isLoop() const {
    return loop;
}

void MusicLibrary::setLoop(bool loop) {
    MusicLibrary::loop = loop;
}

bool MusicLibrary::isShuffle() const {
    return shuffle;
}

void MusicLibrary::setShuffle(bool shuffle) {
    MusicLibrary::shuffle = shuffle;
}
/*
void MusicLibrary::playAudioTrack(AudioTrack audioTrack) {
    auto desiredAudioTrackIterator = audioTracks.begin();
    while (*(*desiredAudioTrackIterator) == audioTrack || desiredAudioTrackIterator != audioTracks.end())
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
*/

std::list<Playlist*>::iterator MusicLibrary::getEndPlaylistsIterator() {
    return playlists.end();
}

void MusicLibrary::newAudioTrack(const wxString &fileName, const wxURI &filePath, wxMediaCtrl** mediaCtrl) {
    //AudioTrack au(fileName, parent);
    auto au = new AudioTrack(fileName, fileName, mediaCtrl);
    audioTracks.push_back(au);
    (*(playlists.begin()))->addTrack(au);
}

std::list<Playlist*>::iterator MusicLibrary::getBeginPlaylistsIterator() {
    return playlists.begin();
}

std::list<AudioTrack*>::iterator MusicLibrary::getBeginAudioTracksIterator() {
    return audioTracks.begin();
}



unsigned long MusicLibrary::getAudioTracksSize() {
    return audioTracks.size();
}


unsigned long MusicLibrary::getPlaylistsSize() {
    return playlists.size();
}

void MusicLibrary::registerObserver(Observer *o) {
    observers.push_back(o);
}

void MusicLibrary::removeObserver(Observer *o) {
    observers.remove(o);
}

void MusicLibrary::notifyObserver() {
    auto it = observers.begin();
    while (it != observers.end()) {
        (*it)->update();
        it++;
    }
}

void MusicLibrary::removeAudioTrack(int pos) {
    (*getBeginPlaylistsIterator())->removeTrack(pos);
    auto audiotrack = getBeginAudioTracksIterator();
    for (int index = 0; index < pos; index++)
        audiotrack++;
    delete *audiotrack;
    audioTracks.erase(audiotrack);
}

std::list<AudioTrack*>::iterator MusicLibrary::getEndAudioTracksIterator() {
    return audioTracks.end();
}

/*
void MusicLibrary::changePlaylistName(wxString n, Playlist* playlist) {
    playlist->changeName(n);
}
*/



