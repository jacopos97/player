//
// Created by jacopo on 10/11/18.
//

#include "MusicLibraryObserver.h"

void MusicLibraryObserver::update() {
    auto musicLibraryAudioTracksIterator = musicLibrary->getBeginAudioTracksIterator();
    while(audioTracks.size() != musicLibrary->getAudioTracksSize()) {
        audioTracks.push_back(*musicLibraryAudioTracksIterator);
        musicLibraryAudioTracksIterator++;
    }
    auto musicLibraryPlaylistIterator = musicLibrary->getBeginPlaylistsIterator();
    while (playlists.size() != musicLibrary->getPlaylistsSize()) {
        playlists.push_back(*musicLibraryPlaylistIterator);
        musicLibraryPlaylistIterator++;
    }
    musicLibraryLoop = musicLibrary->isLoop();
    musicLibraryShuffle = musicLibrary->isShuffle();
    display();
}

void MusicLibraryObserver::display() {

}

MusicLibraryObserver::MusicLibraryObserver(MusicLibrary *msl) {
    musicLibrary = msl;
    auto musicLibraryAudioTracksIterator = musicLibrary->getBeginAudioTracksIterator();
    while(audioTracks.size() != musicLibrary->getAudioTracksSize()) {
        audioTracks.push_back(*musicLibraryAudioTracksIterator);
        musicLibraryAudioTracksIterator++;
    }
    auto musicLibraryPlaylistIterator = musicLibrary->getBeginPlaylistsIterator();
    while (playlists.size() != musicLibrary->getPlaylistsSize()) {
        playlists.push_back(*musicLibraryPlaylistIterator);
        musicLibraryPlaylistIterator++;
    }
    musicLibraryLoop = musicLibrary->isLoop();
    musicLibraryShuffle = musicLibrary->isShuffle();
}
