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
#include <wx/arrstr.h>
#include "Subject.h"
#include "AudioTrack.h"


class Playlist : public Subject {
public:
    explicit Playlist(const wxString &n = "NewPlaylist") : name(n), loop(false), shuffle(false){};
    bool operator==(const Playlist& p) const;
    bool operator!=(const Playlist& p) const;
    void addTrack(AudioTrack* audioTrack);
    void removeTrack(int pos);
    //void moveTrack(std::list<AudioTrack>::iterator selectedAudioTrack, std::list<AudioTrack>::iterator desiredPositionIterator);
    void playAudioTrack(AudioTrack* audioTrack);
    void play();
    void changeName(wxString n);
    bool isLoop() const;
    void setLoop(bool loop);
    bool isShuffle() const;
    void setShuffle(bool shuffle);
    const wxString &getName() const;
    std::list<AudioTrack*>::iterator  getBeginIterator();
    std::list<AudioTrack*>::iterator getEndIterator();
    ~Playlist() override = default;
    AudioTrack* getAudioTrack(unsigned long pos);
    unsigned long getSize() const;
    void registerObserver (Observer *o) override;
    void removeObserver (Observer *o) override;
    void notifyObserver () override;
    wxArrayString getArrayString();
    int checkAudioTrackPresence(wxString audioTrackTitle);
    bool checkPossibleDuplicateTrack (wxString audioTrackTitle);


private:
    std::list <AudioTrack*> audioTracks;
    wxString name;
    bool loop;
    bool shuffle;
    std::list <Observer*> observers;
    wxArrayString audioTracksTitles;
};


#endif //MP3_PLAYLIST_H
