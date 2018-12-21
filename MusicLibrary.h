//
// Created by jacopo on 22/10/18.
//

#ifndef MP3_MUSICLIBRARY_H
#define MP3_MUSICLIBRARY_H

#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <time.h>
#include "Subject.h"
#include "AudioTrack.h"
#include "Playlist.h"


class MusicLibrary : public Subject {
public:
    MusicLibrary() : loop(false), shuffle(false) {};
    Playlist newPlaylist ();
    void newAudioTrack();
    void removePlaylist (Playlist playlist);
    void playPlaylist(Playlist playlist);
    void play();
    void playAudioTrack(AudioTrack audioTrack);
    bool isLoop() const;
    void setLoop(bool loop);
    bool isShuffle() const;
    void setShuffle(bool shuffle);
    std::list <Playlist>::iterator getEndPlaylistsIterator();
    std::list <Playlist>::iterator getBeginPlaylistsIterator();
    std::list <AudioTrack>::iterator getBeginAudioTracksIterator();
    unsigned long getAudioTracksSize();
    unsigned long getPlaylistsSize();
    Playlist selectPlaylist(int pos);
    void registerObserver (Observer *o) override;
    void removeObserver (Observer *o) override;
    void notifyObserver () override;
    ~MusicLibrary() override = default;

private:
    bool loop;
    bool  shuffle;
    std::list <Playlist> playlists;
    std::list <AudioTrack> audioTracks;
    std::list <Observer*> observers;
};


#endif //MP3_MUSICLIBRARY_H
