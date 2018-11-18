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
    auto it = playlists.end();
    it--;
    Playlist pl = selectPlaylist(it);
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
    auto it = audiotracks.begin();
    if (!shuffle){
        while (it != audiotracks.end()){
            it->playAudioTrack();
            it++;
        }
        if (loop)
            this->play();
    }
    else{//TODO: implement playAudioTrack() with shuffle
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

void MusicLibrary::playAudiotrack(AudioTrack audioTrack) {
    auto it = audiotracks.begin();
    while (*it != audioTrack && it != audiotracks.end())
        it++;
    if (*it == audioTrack)
        it->playAudioTrack();
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
