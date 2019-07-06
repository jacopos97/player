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
    explicit ConcreteController(MusicLibrary* msl) : playlist(nullptr), musicLibrary(msl) {}
    void addTrackPlaylist(AudioTrack* audioTrack, Playlist* playlist) override;
    void removeTrackPlaylist(int pos, Playlist* playlist) override;
    void changePlaylistName(wxString n, Playlist* playlist) override;
    void newPlaylist(wxString playlistName) override;
    void newAudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl) override;
    void removePlaylist (int pos) override;
    void removeTrackMusicLibrary (int pos) override;
    void setLoopMusicLibrary(bool loop) override;
    void setShuffleMusicLibrary(bool shuffle) override;
    ~ConcreteController() override = default; ;

private:
    Playlist* playlist;
    MusicLibrary* musicLibrary;
};


#endif //MP3_CONCRETECONTROLLER_H
