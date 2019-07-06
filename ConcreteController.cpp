//
// Created by jacopo on 05/05/19.
//

#include "ConcreteController.h"

void ConcreteController::addTrackPlaylist(AudioTrack* audioTrack, Playlist* playlist) {
    ConcreteController::playlist = playlist;
    ConcreteController::playlist->addTrack(audioTrack);
}

void ConcreteController::removeTrackPlaylist(int pos, Playlist* playlist) {
    ConcreteController::playlist = playlist;
    ConcreteController::playlist->removeTrack(pos);
}

void ConcreteController::newPlaylist(wxString playlistName) {
    musicLibrary->newPlaylist(playlistName);
}

void ConcreteController::newAudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl) {
    musicLibrary->newAudioTrack(fileName, filePath, mediaCtrl);
}

void ConcreteController::removePlaylist(int pos) {
    musicLibrary->removePlaylist(pos);
}

void ConcreteController::removeTrackMusicLibrary(int pos) {
    musicLibrary->removeAudioTrack(pos);
}

void ConcreteController::setLoopMusicLibrary(bool loop) {
    musicLibrary->setLoop(loop);
}

void ConcreteController::setShuffleMusicLibrary(bool shuffle) {
    musicLibrary->setShuffle(shuffle);
}


void ConcreteController::changePlaylistName(wxString n, Playlist* playlist) {
    ConcreteController::playlist = playlist;
    ConcreteController::playlist->changeName(n);
}


