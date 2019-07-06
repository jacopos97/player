//
// Created by jacopo on 04/11/18.
//

#ifndef MP3_CONTROLLER_H
#define MP3_CONTROLLER_H

#include "Playlist.h"
#include "AudioTrack.h"


class Controller {
public:
    virtual void addTrackPlaylist(AudioTrack* audioTrack, Playlist* playlist) = 0;
    virtual void removeTrackPlaylist(int pos, Playlist* playlist) = 0;
    virtual void changePlaylistName(wxString n, Playlist* playlist) = 0;
    virtual void newPlaylist(wxString playlistName) = 0;
    virtual void newAudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl) = 0;
    virtual void removePlaylist (int pos) = 0;
    virtual void removeTrackMusicLibrary (int pos) = 0;
    virtual void setLoopMusicLibrary(bool loop) = 0;
    virtual void setShuffleMusicLibrary(bool shuffle) = 0;
    virtual ~Controller() {};
};


#endif //MP3_CONTROLLER_H
