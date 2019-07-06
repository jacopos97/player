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
#include "AudioTrack.h"


class Playlist {
public:
    explicit Playlist(const wxString &n = "NewPlaylist") : name(n), loop(false), shuffle(false){};
    bool operator==(const Playlist& p) const;
    bool operator!=(const Playlist& p) const;
    void addTrack(AudioTrack* audioTrack);
    void removeTrack(int pos);
    void changeName(wxString n);
    bool isLoop() const;
    bool isShuffle() const;
    const wxString &getName() const;
    std::list<AudioTrack*>::iterator  getBeginIterator();
    std::list<AudioTrack*>::iterator getEndIterator();
    ~Playlist() = default;
    std::list<AudioTrack*>::iterator getAudioTrack(int pos);
    unsigned long getSize() const;
    wxArrayString getArrayString();
    int checkAudioTrackPresence(wxString audioTrackTitle);
    bool checkPossibleDuplicateTrack (wxString audioTrackTitle);
    int getRandomAudioTrack(std::list<AudioTrack*>::iterator au);


private:
    std::list <AudioTrack*> audioTracks;
    wxString name;
    bool loop;
    bool shuffle;
    wxArrayString audioTracksTitles;
};


#endif //MP3_PLAYLIST_H
