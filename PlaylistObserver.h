//
// Created by jacopo on 10/11/18.
//

#ifndef MP3_PLAYLISTOBSERVER_H
#define MP3_PLAYLISTOBSERVER_H

#include <list>
#include "Observer.h"
#include "DisplayElements.h"
#include "Playlist.h"


class PlaylistObserver  : public Observer, public DisplayElements {
public:
    explicit PlaylistObserver(Playlist* pl);
    void update() override;
    void display() override;
    ~PlaylistObserver() override = default;

private:
    Playlist* playlist;
    std::list <AudioTrack> audioTracks;
    std::string playlistName;
    bool playlistLoop;
    bool playlitstShuffle;
};




#endif //MP3_PLAYLISTOBSERVER_H
