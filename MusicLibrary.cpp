//
// Created by jacopo on 22/10/18.
//

#include "MusicLibrary.h"

Playlist MusicLibrary::newPlaylist() {
    std::string playlistName;
    std::cout << "Nome playlist:";
    std::cin >> playlistName;
    Playlist playlist(playlistName);
    playlists.push_back(playlist);
    int i = static_cast<int>(playlists.size());
    Playlist pl = selectPlaylist(i);
    return pl;
}

void MusicLibrary::removePlaylist(Playlist playlist) {
    auto it = playlists.begin();
    while (*it != playlist || it != playlists.end())
        it++;
    if (*it == playlist)
        playlists.erase(it);
}

void MusicLibrary::playPlaylist(Playlist playlist) {
    playlist.play();
}

void MusicLibrary::play() {
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
            randValue = rand() % copyAudioTracks.size() + 1;
            auto it1 = copyAudioTracks.begin();
            unsigned long i = 1;
            while (i != randValue) {
                it1++;
                i++;
            }
            it1->playAudioTrack();
            copyAudioTracks.erase(it1);
        }
        if (loop)
            this->play();
    }
}

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

void MusicLibrary::playAudioTrack(AudioTrack audioTrack) {
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

Playlist MusicLibrary::selectPlaylist(int pos){
    auto it = playlists.begin();
    for (int i = 1; i < pos; i++)
        it++;
    return *it;
}

std::list<Playlist>::iterator MusicLibrary::getEndPlaylistsIterator() {
    return playlists.end();
}

void MusicLibrary::newAudioTrack() {

}

std::list<Playlist>::iterator MusicLibrary::getBeginPlaylistsIterator() {
    return playlists.begin();
}

std::list<AudioTrack>::iterator MusicLibrary::getBeginAudioTracksIterator() {
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

