//
// Created by jacopo on 10/11/18.
//

#include "PlaylistObserver.h"


void PlaylistObserver::update() {
    auto playlistIterator = playlist->getBeginIterator();
    while (audioTracks.size() != playlist->getSize()) {
       audioTracks.push_back(*playlistIterator);
       playlistIterator++;
    }
    playlistName = playlist->getName();
    playlistLoop = playlist->isLoop();
    playlitstShuffle = playlist->isShuffle();
    display();
}

void PlaylistObserver::display() {

}

PlaylistObserver::PlaylistObserver(Playlist *pl) {
    playlist = pl;
    auto playlistIterator = playlist->getBeginIterator();
    while (audioTracks.size() != playlist->getSize()) {
        audioTracks.push_back(*playlistIterator);
        playlistIterator++;
    }
    playlistName = playlist->getName();
    playlistLoop = playlist->isLoop();
    playlitstShuffle = playlist->isShuffle();
}
