//
// Created by jacopo on 04/11/18.
//

#ifndef MP3_CONTROLLER_H
#define MP3_CONTROLLER_H

#include "Playlist.h"
#include "AudioTrack.h"


class Controller {
public:
    //Controller() = default;
    virtual void playAudioTrack() = 0;
    //virtual void restartAudioTrack() = 0;
    //virtual void pauseAudioTrack() =  0;
    virtual void addTrackPlaylist(AudioTrack* audioTrack, Playlist* playlist) = 0;
    virtual void removeTrackPlaylist(int pos, Playlist* playlist) = 0;
    //virtual void moveTrackPlaylist(std::list<AudioTrack>::iterator selectedAudioTrack, std::list<AudioTrack>::iterator desiredPositionIterator) = 0;
    virtual void playTrackPlaylist(Playlist* playlist, AudioTrack* audioTrack) = 0;
    virtual void playPlaylist() = 0;
    virtual void changePlaylistName(wxString n, Playlist* playlist) = 0;
    virtual void setLoopPlaylist(bool loop) = 0;
    virtual void setShufflePlaylist(bool shuffle) = 0;
    virtual void newPlaylist(wxString playlistName) = 0;
    virtual void newAudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl) = 0;
    virtual void removePlaylist (int pos) = 0;
    virtual void removeTrackMusicLibrary (int pos) = 0;
    /*
    virtual void playPlaylistMusicLibrary(Playlist playlist) = 0;
    virtual void playMusicLibrary() = 0;
    virtual void playAudioTrack(AudioTrack audioTrack) = 0;
     */
    virtual void setLoopMusicLibrary(bool loop) = 0;
    virtual void setShuffleMusicLibrary(bool shuffle) = 0;
    virtual ~Controller() {};
};

#endif //MP3_CONTROLLER_H
