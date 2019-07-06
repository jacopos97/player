//
// Created by jacopo on 22/10/18.
//

#include "MusicLibrary.h"

void MusicLibrary::newPlaylist(wxString playlistName) {
    auto playlist = new Playlist(playlistName);
    playlists.push_back(playlist);
}

void MusicLibrary::removePlaylist(int pos) {
    auto it = playlists.begin();
    for (int index = 0; index <= pos; index++)
        it++;
    delete *it;
    playlists.erase(it);
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

std::list<Playlist*>::iterator MusicLibrary::getEndPlaylistsIterator() {
    return playlists.end();
}

void MusicLibrary::newAudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl) {
    auto au = new AudioTrack(fileName, filePath, mediaCtrl);
    audioTracks.push_back(au);
    (*(playlists.begin()))->addTrack(au);
}

std::list<Playlist*>::iterator MusicLibrary::getBeginPlaylistsIterator() {
    return playlists.begin();
}

std::list<AudioTrack*>::iterator MusicLibrary::getBeginAudioTracksIterator() {
    return audioTracks.begin();
}

void MusicLibrary::removeAudioTrack(int pos) {
    (*getBeginPlaylistsIterator())->removeTrack(pos);
    auto audiotrack = getBeginAudioTracksIterator();
    for (int index = 0; index < pos; index++)
        audiotrack++;
    delete *audiotrack;
    audioTracks.erase(audiotrack);
}

