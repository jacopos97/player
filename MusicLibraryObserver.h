//
// Created by jacopo on 10/11/18.
//

#ifndef MP3_MUSICLIBRARYOBSERVER_H
#define MP3_MUSICLIBRARYOBSERVER_H

#include <list>
#include "Observer.h"
#include "DisplayElements.h"
#include "MusicLibrary.h"

class MusicLibraryObserver : public Observer, public DisplayElements {
public:
    explicit MusicLibraryObserver(MusicLibrary* msl);
    void update() override;
    void display() override;
    ~MusicLibraryObserver() override = default;

private:
    MusicLibrary* musicLibrary;
    std::list <AudioTrack> audioTracks;
    std::list <Playlist> playlists;
    bool musicLibraryLoop;
    bool musicLibraryShuffle;
};


#endif //MP3_MUSICLIBRARYOBSERVER_H
