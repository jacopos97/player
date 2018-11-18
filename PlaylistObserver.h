//
// Created by jacopo on 10/11/18.
//

#ifndef MP3_PLAYLISTOBSERVER_H
#define MP3_PLAYLISTOBSERVER_H


#include "Observer.h"
#include "DisplayElements.h"
#include "Playlist.h"


class PlaylistObserver  : public Observer, public DisplayElements {
public:
    void update();
    void display();

private:
    Playlist* playlist;
};




#endif //MP3_PLAYLISTOBSERVER_H
