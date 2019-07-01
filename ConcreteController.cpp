//
// Created by jacopo on 05/05/19.
//

#include "ConcreteController.h"

void ConcreteController::playAudioTrack() {
    audioTrack->playAudioTrack();
}
/*
void ConcreteController::restartAudioTrack() {
    audioTrack->restart();
}
*/
/*
void ConcreteController::pauseAudioTrack() {
    audioTrack->pause();
}
 */

void ConcreteController::addTrackPlaylist(AudioTrack* audioTrack, Playlist* playlist) {
    ConcreteController::playlist = playlist;
    ConcreteController::playlist->addTrack(audioTrack);
}

void ConcreteController::removeTrackPlaylist(int pos, Playlist* playlist) {
    ConcreteController::playlist = playlist;
    ConcreteController::playlist->removeTrack(pos);
}
/*
void ConcreteController::moveTrackPlaylist(std::list<AudioTrack>::iterator selectedAudioTrack, std::list<AudioTrack>::iterator desiredPositionIterator) {
    playlist->moveTrack(selectedAudioTrack, desiredPositionIterator);
}
*/
void ConcreteController::playTrackPlaylist(Playlist* playlist, AudioTrack* audioTrack) {
    ConcreteController::playlist = playlist;
    ConcreteController::playlist->playAudioTrack(audioTrack);
}

void ConcreteController::playPlaylist() {
    playlist->play();
}



void ConcreteController::setLoopPlaylist(bool loop) {
    playlist->setLoop(loop);
}

void ConcreteController::setShufflePlaylist(bool shuffle) {
    playlist->setShuffle(shuffle);
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
/*
void ConcreteController::playPlaylistMusicLibrary(Playlist playlist) {
    musicLibrary->playPlaylist(playlist);
}

void ConcreteController::playMusicLibrary() {
    musicLibrary->play();
}

void ConcreteController::playAudioTrack(AudioTrack audioTrack) {
    musicLibrary->playAudioTrack(audioTrack);
}
*/
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


