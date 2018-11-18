//
// Created by jacopo on 22/10/18.
//

#ifndef MP3_MUSICLIBRARY_H
#define MP3_MUSICLIBRARY_H

#include <list>
#include <string>
#include <iostream>
#include "Subject.h"
#include "AudioTrack.h"
#include "Playlist.h"


class MusicLibrary: public Subject {
public:
    MusicLibrary() : loop(false), shuffle(false) {};
    Playlist newPlaylist ();
    void newAudioTrack();
    void removePlaylist (Playlist playlist);
    void playPlaylist(Playlist playlist);
    void play();
    void playAudiotrack(AudioTrack audioTrack);
    bool isLoop() const;
    void setLoop(bool loop);
    bool isShuffle() const;
    void setShuffle(bool shuffle);
    std::list <Playlist>::iterator getEndPlaylistsIterator();
    Playlist selectPlaylist(int pos);
    ~MusicLibrary() = default;

private:
    bool loop;
    bool  shuffle;
    std::list <Playlist> playlists;
    std::list <AudioTrack> audiotracks;
};


#endif //MP3_MUSICLIBRARY_H
