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
#include "AudioTrack.h"
#include "Playlist.h"


class MusicLibrary {
public:
    MusicLibrary() : loop(false), shuffle(false) {
        newPlaylist("Musiclibrary");
    }
    void newPlaylist (wxString playlistName);
    void newAudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl);
    void removePlaylist (int pos);
    void removeAudioTrack (int pos);
    bool isLoop() const;
    void setLoop(bool loop);
    bool isShuffle() const;
    void setShuffle(bool shuffle);
    std::list <Playlist*>::iterator getEndPlaylistsIterator();
    std::list <Playlist*>::iterator getBeginPlaylistsIterator();
    std::list <AudioTrack*>::iterator getBeginAudioTracksIterator();

    ~MusicLibrary() = default;

private:
    bool loop;
    bool  shuffle;
    std::list <Playlist*> playlists;
    std::list <AudioTrack*> audioTracks;
};


#endif //MP3_MUSICLIBRARY_H
