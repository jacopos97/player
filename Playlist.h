//
// Created by jacopo on 21/10/18.
//

#ifndef MP3_PLAYLIST_H
#define MP3_PLAYLIST_H

#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <utility>
#include <time.h>
#include "Subject.h"
#include "AudioTrack.h"


class Playlist : public Subject {
public:
    explicit Playlist(std::string n = "NewPlaylist") : name(std::move(n)), loop(false), shuffle(false){};
    bool operator==(Playlist p);
    bool operator!=(Playlist p);
    void addTrack(AudioTrack audioTrack);
    void removeTrack(AudioTrack audioTrack);
    void moveTrack(std::list<AudioTrack>::iterator selectedAudioTrack, std::list<AudioTrack>::iterator desiredPosition);
    void playAudioTrack(AudioTrack audioTrack);
    void play();
    bool isLoop() const;
    void setLoop(bool loop);
    bool isShuffle() const;
    void setShuffle(bool shuffle);
    const std::string &getName() const;
    std::list<AudioTrack>::iterator  getBeginIterator();
    std::list<AudioTrack>::iterator getEndIterator();
    ~Playlist() override = default;
    AudioTrack getAudioTrack(unsigned long pos);
    unsigned long getSize() const;
    void registerObserver (Observer *o) override;
    void removeObserver (Observer *o) override;
    void notifyObserver () override;
private:
    std::list <AudioTrack> audioTracks;
    std::string name;
    bool loop;
    bool shuffle;
    std::list <Observer*> observers;
};


#endif //MP3_PLAYLIST_H
