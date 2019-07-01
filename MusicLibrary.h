//
// Created by jacopo on 22/10/18.
//

#ifndef MP3_MUSICLIBRARY_H
#define MP3_MUSICLIBRARY_H

#include <list>
#include <string>
#include <iterator>
#include <time.h>
#include <wx/wx.h>
#include <wx/mediactrl.h>
#include "Subject.h"
#include "AudioTrack.h"
#include "Playlist.h"


class MusicLibrary : public Subject {
public:
    MusicLibrary() : loop(false), shuffle(false) {
        newPlaylist("Musiclibrary");
    }
    void newPlaylist (wxString playlistName);
    void newAudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl);
    void removePlaylist (int pos);
    void removeAudioTrack (int pos);
    //void playPlaylist(Playlist playlist);
    //void play();
    //void playAudioTrack(AudioTrack audioTrack);
    bool isLoop() const;
    void setLoop(bool loop);
    bool isShuffle() const;
    void setShuffle(bool shuffle);
    std::list <Playlist*>::iterator getEndPlaylistsIterator();
    std::list <Playlist*>::iterator getBeginPlaylistsIterator();
    std::list <AudioTrack*>::iterator getBeginAudioTracksIterator();
    std::list <AudioTrack*>::iterator getEndAudioTracksIterator();
    unsigned long getAudioTracksSize();
    unsigned long getPlaylistsSize();
    void registerObserver (Observer *o) override;
    void removeObserver (Observer *o) override;
    void notifyObserver () override;
    //void changePlaylistName(wxString n, Playlist* playlist);


    ~MusicLibrary() override = default;

private:
    bool loop;
    bool  shuffle;
    std::list <Playlist*> playlists;
    std::list <AudioTrack*> audioTracks;
    std::list <Observer*> observers;
};


#endif //MP3_MUSICLIBRARY_H
