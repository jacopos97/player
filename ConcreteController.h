//
// Created by jacopo on 05/05/19.
//

#ifndef MP3_CONCRETECONTROLLER_H
#define MP3_CONCRETECONTROLLER_H

#include "Controller.h"
#include "MusicLibrary.h"
#include "Playlist.h"
#include "AudioTrack.h"


class ConcreteController : public Controller {
public:
    //explicit ConcreteController(MusicLibrary* msl) : audioTrack(nullptr), playlist(nullptr), musicLibrary(msl) {}
    explicit ConcreteController(MusicLibrary* msl) : playlist(nullptr), musicLibrary(msl) {}
    //void playAudioTrack() override;
    //void restartAudioTrack() override;
    //void pauseAudioTrack() override;
    void addTrackPlaylist(AudioTrack* audioTrack, Playlist* playlist) override;
    void removeTrackPlaylist(int pos, Playlist* playlist) override;
    //void moveTrackPlaylist(std::list<AudioTrack>::iterator selectedAudioTrack, std::list<AudioTrack>::iterator desiredPositionIterator) override;
    //void playTrackPlaylist(Playlist* playlist, AudioTrack* audioTrack) override;
    //void playPlaylist() override;
    void changePlaylistName(wxString n, Playlist* playlist) override;
    //void setLoopPlaylist(bool loop) override;
    //void setShufflePlaylist(bool shuffle) override;
    void newPlaylist(wxString playlistName) override;
    void newAudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl) override;
    void removePlaylist (int pos) override;
    void removeTrackMusicLibrary (int pos) override;
    /*
    void playPlaylistMusicLibrary(Playlist playlist) override;
    void playMusicLibrary() override;
    void playAudioTrack(AudioTrack audioTrack) override;
     */
    void setLoopMusicLibrary(bool loop) override;
    void setShuffleMusicLibrary(bool shuffle) override;
    ~ConcreteController() override = default; ;

private:
    //AudioTrack* audioTrack;
    Playlist* playlist;
    MusicLibrary* musicLibrary;
};


#endif //MP3_CONCRETECONTROLLER_H
