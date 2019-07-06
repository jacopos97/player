///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MusicLibraryFrame.h"

///////////////////////////////////////////////////////////////////////////

MusicLibraryFrame::MusicLibraryFrame(ConcreteController* conCon, MusicLibrary* ml, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style ) {

	concreteController = conCon;
	musicLibrary = ml;


	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMusicLibrary;
	bSizerMusicLibrary = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerLibraryMusic;
	bSizerLibraryMusic = new wxBoxSizer( wxHORIZONTAL );
	
	playlistList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	playlistList->SetMinSize( wxSize( 90,-1 ) );

	
	bSizerLibraryMusic->Add( playlistList, 0, wxALL|wxEXPAND, 0 );
	
	wxBoxSizer* bSizerAudioTrack;
	bSizerAudioTrack = new wxBoxSizer( wxVERTICAL );
	
	audioTrackList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	audioTrackList->SetMinSize( wxSize( -1,160 ) );
	
	bSizerAudioTrack->Add( audioTrackList, 0, wxALL|wxEXPAND|wxALIGN_RIGHT, 0 );
	
	wxBoxSizer* bSizerMediaCtrl;
	bSizerMediaCtrl = new wxBoxSizer( wxHORIZONTAL );
	
	mediaCtrlAudioTrack = new wxMediaCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
	mediaCtrlAudioTrack->SetPlaybackRate(1);
	mediaCtrlAudioTrack->SetVolume(1);
	
	mediaCtrlAudioTrack->Stop();
	bSizerMediaCtrl->Add( mediaCtrlAudioTrack, 1, wxALL|wxEXPAND, 0 );

    wxBoxSizer* bSizerPlayPause;
    bSizerPlayPause = new wxBoxSizer( wxVERTICAL);

	buttonPlay = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerPlayPause->Add(buttonPlay, 1, wxALL, 0);

    buttonPause = new wxButton( this, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizerPlayPause->Add(buttonPause, 1, 0, 0);
	
	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxVERTICAL );
	
	buttonLoop = new wxButton( this, wxID_ANY, wxT("Loop"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( buttonLoop, 1, wxALL, 0 );
	
	buttonShuffle = new wxButton( this, wxID_ANY, wxT("Shuffle"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( buttonShuffle, 1, 0, 0 );

	
	bSizerMediaCtrl->Add( bSizerPlayPause, 0, wxALL|wxALIGN_BOTTOM|wxEXPAND, 0 );


	bSizerMediaCtrl->Add( bSizerButtons, 0, wxALL|wxALIGN_BOTTOM|wxEXPAND, 0 );
	
	
	bSizerAudioTrack->Add( bSizerMediaCtrl, 1, wxALL|wxEXPAND, 0 );
	
	
	bSizerLibraryMusic->Add( bSizerAudioTrack, 1, wxALL|wxEXPAND, 0 );
	
	
	bSizerMusicLibrary->Add( bSizerLibraryMusic, 1, wxALL|wxEXPAND, 0 );
	
	
	this->SetSizer( bSizerMusicLibrary );
	this->Layout();
	menuBar = new wxMenuBar( 0 );


    menuMusicLibrary = new wxMenu();
    wxMenuItem* menuItemAudioTrackAdd;
    menuItemAudioTrackAdd = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("AddTrack") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackAdd );

    wxMenuItem* menuItemAudioTrackDelete;
    menuItemAudioTrackDelete = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("DeleteTrack") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackDelete );

    menuBar->Append( menuMusicLibrary, wxT("MusicLibrary") );


	menuPlaylist = new wxMenu();
	wxMenuItem* menuItemPlaylistNew;
	menuItemPlaylistNew = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("New") ) , wxEmptyString, wxITEM_NORMAL );
	menuPlaylist->Append( menuItemPlaylistNew );

    wxMenuItem* menuItemPlaylistDelete;
    menuItemPlaylistDelete = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
    menuPlaylist->Append( menuItemPlaylistDelete );


    wxMenuItem* menuItemPlaylistAddTrack;
    menuItemPlaylistAddTrack = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("AddTrack") ) , wxEmptyString, wxITEM_NORMAL );
    menuPlaylist->Append( menuItemPlaylistAddTrack );

    wxMenuItem* menuItemPlaylistDeleteTrack;
    menuItemPlaylistDeleteTrack = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("DeleteTrack") ) , wxEmptyString, wxITEM_NORMAL );
    menuPlaylist->Append( menuItemPlaylistDeleteTrack );

    wxMenuItem* menuItemPlaylistChangeName;
    menuItemPlaylistChangeName = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("ChangeName") ) , wxEmptyString, wxITEM_NORMAL );
    menuPlaylist->Append( menuItemPlaylistChangeName );

    menuBar->Append( menuPlaylist, wxT("Playlist") );

	
	this->SetMenuBar( menuBar );
	
	
	this->Centre( wxBOTH );


	playlist = musicLibrary->getBeginPlaylistsIterator();
	audioTrack = (*playlist)->getEndIterator();
	update();
	

	// Connect Events
	buttonLoop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonLoopOnButtonClick ), NULL, this );
	buttonShuffle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonShuffleOnButtonClick ), NULL, this );
	buttonPlay->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonPlayOnButtonClick ), NULL, this );
    buttonPause->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonPauseOnButtonClick ), NULL, this );
	menuPlaylist->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemPlaylistNewOnMenuSelection ), this, menuItemPlaylistNew->GetId());
	menuPlaylist->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemPlaylistDeleteOnMenuSelection ), this, menuItemPlaylistDelete->GetId());
    menuPlaylist->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemPlaylistAddTrackOnMenuSelection ), this, menuItemPlaylistAddTrack->GetId());
    menuPlaylist->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemPlaylistDeleteTrackOnMenuSelection ), this, menuItemPlaylistDeleteTrack->GetId());
    menuPlaylist->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemPlaylistChangeNameOnMenuSelection ), this, menuItemPlaylistChangeName->GetId());
	menuMusicLibrary->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemAudioTrackAddOnMenuSelection ), this, menuItemAudioTrackAdd->GetId());
	menuMusicLibrary->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemAudioTrackDeleteOnMenuSelection ), this, menuItemAudioTrackDelete->GetId());
	playlistList->Bind(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(MusicLibraryFrame::playlistListItemOnClick), this, playlistList->GetId());
	audioTrackList->Bind(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(MusicLibraryFrame::audioTrackListItemOnClick), this, audioTrackList->GetId());

	mediaCtrlAudioTrack->Bind(wxEVT_MEDIA_LOADED, wxCommandEventHandler(MusicLibraryFrame::OnMediaLoaded), this, mediaCtrlAudioTrack->GetId());
	mediaCtrlAudioTrack->Bind(wxEVT_MEDIA_FINISHED, wxCommandEventHandler(MusicLibraryFrame::OnMediaFinished), this, mediaCtrlAudioTrack->GetId());
}

MusicLibraryFrame::~MusicLibraryFrame()
{
	// Disconnect Events
	buttonLoop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonLoopOnButtonClick ), NULL, this );
	buttonShuffle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonShuffleOnButtonClick ), NULL, this );
	buttonPlay->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonPlayOnButtonClick ), NULL, this );
    buttonPause->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonPauseOnButtonClick ), NULL, this );
}



void MusicLibraryFrame::update() {
    playlistList->Clear();
    auto musicLibraryPlaylistIterator = musicLibrary->getBeginPlaylistsIterator();
    auto endPlaylistIterator = musicLibrary->getEndPlaylistsIterator();
    while (musicLibraryPlaylistIterator != endPlaylistIterator) {
        playlistList->Append((*musicLibraryPlaylistIterator)->getName());
        musicLibraryPlaylistIterator++;
    }
}


void MusicLibraryFrame::buttonLoopOnButtonClick(wxCommandEvent &event) {
    bool loop = !(musicLibrary->isLoop());
    concreteController->setLoopMusicLibrary(loop);
    if (loop)
        buttonLoop->SetBackgroundColour(*wxLIGHT_GREY);
    else
        buttonLoop->SetBackgroundColour(*wxWHITE);
}


void MusicLibraryFrame::buttonShuffleOnButtonClick(wxCommandEvent &event) {
    bool shuffle = !(musicLibrary->isShuffle());
    concreteController->setShuffleMusicLibrary(shuffle);
    if (shuffle)
        buttonShuffle->SetBackgroundColour(*wxLIGHT_GREY);
    else
        buttonShuffle->SetBackgroundColour(*wxWHITE);
}


void MusicLibraryFrame::menuItemPlaylistNewOnMenuSelection(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    newPlaylist();
}

void MusicLibraryFrame::menuItemPlaylistDeleteOnMenuSelection(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    auto mLPlaylist = musicLibrary->getBeginPlaylistsIterator();
    mLPlaylist++;
    if(mLPlaylist == musicLibrary->getEndPlaylistsIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not effaceable playlists!", "Error!");
        errorMessage.ShowModal();
    }
    else {
        wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Delete playlist", playlistsNames);
        if (playlistsList.ShowModal() == wxID_OK) {
            int desiredPlaylistIndex = playlistsList.GetSelection();
            auto it = musicLibrary->getBeginPlaylistsIterator();
            for (int index = 0; index <= desiredPlaylistIndex; index++) {
                it++;
            }
            if (*it == *playlist) {
                playlist = musicLibrary->getBeginPlaylistsIterator();
                updatePlaylist(playlist);
            }
            concreteController->removePlaylist(desiredPlaylistIndex);
            playlistsNames.RemoveAt(static_cast<size_t>(desiredPlaylistIndex));
            update();
        }
    }
}

void MusicLibraryFrame::menuItemAudioTrackAddOnMenuSelection(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    newAudioTrack();
}

void MusicLibraryFrame::menuItemAudioTrackDeleteOnMenuSelection(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    if((*musicLibrary->getBeginPlaylistsIterator())->getBeginIterator() == (*musicLibrary->getBeginPlaylistsIterator())->getEndIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not effaceable audiotracks!", "Error!");
        errorMessage.ShowModal();
    }
    else {
        wxSingleChoiceDialog audioTracksList(NULL, "Select desired audiotrack:", "Remove track ",(*musicLibrary->getBeginPlaylistsIterator())->getArrayString());
        if (audioTracksList.ShowModal() == wxID_OK) {
            wxString selectedAudiotrack = audioTracksList.GetStringSelection();
            auto it = musicLibrary->getBeginPlaylistsIterator();
            it++;
            int index;
            while (it != musicLibrary->getEndPlaylistsIterator()) {
                index = (*it)->checkAudioTrackPresence(selectedAudiotrack);
                if (index != (*it)->getSize()) {
                    concreteController->removeTrackPlaylist(index, *it);
                    if (playlist == it)
                        updatePlaylist(playlist);
                }
                it++;
            }
            concreteController->removeTrackMusicLibrary(audioTracksList.GetSelection());
            if (playlist == musicLibrary->getBeginPlaylistsIterator())
                updatePlaylist(playlist);
        }
    }
}

void MusicLibraryFrame::playlistListItemOnClick(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    auto it = musicLibrary->getBeginPlaylistsIterator();
    for(int i = 1; i <= playlistList->GetSelection(); i++)
       it++;
    if (playlist != it) {
        playlist = it;
        updatePlaylist(playlist);
        if ((*playlist)->getBeginIterator() != (*playlist)->getEndIterator()) {
            audioTrack = (*playlist)->getBeginIterator();
            audioTrackList->SetSelection(0);
            playAudioTrack(audioTrack);
        }
    }
}

void MusicLibraryFrame::updatePlaylist(std::list<Playlist*>::iterator it) {
    audioTrackList->Clear();
    auto audioTrackIterator = (*it)->getBeginIterator();
    auto endAudioTrackIterator = (*it)->getEndIterator();
    while (audioTrackIterator != endAudioTrackIterator) {
        audioTrackList->Append((*audioTrackIterator)->getFileName());
        audioTrackIterator++;
    }
}

void MusicLibraryFrame::menuItemPlaylistAddTrackOnMenuSelection(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    auto mLPlaylist = musicLibrary->getBeginPlaylistsIterator();
    mLPlaylist++;
    if(mLPlaylist == musicLibrary->getEndPlaylistsIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not new playlists!\n Create a new playlist?", "Error!", wxOK | wxCANCEL | wxCENTRE);
        if(errorMessage.ShowModal() == wxID_OK)
            newPlaylist();
    }
    else {
        if((*musicLibrary->getBeginPlaylistsIterator())->getBeginIterator() == (*musicLibrary->getBeginPlaylistsIterator())->getEndIterator()) {
            wxMessageDialog errorMessage(NULL, "Ops!!! There are not audiotracks in musiclibrary!\n Add new track to musiclibrary?", "Error!", wxOK | wxCANCEL | wxCENTRE);
            if(errorMessage.ShowModal() == wxID_OK)
                newAudioTrack();
        }
        else {
            wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Add track to playlist", playlistsNames);
            if (playlistsList.ShowModal() == wxID_OK) {
                auto selectedPlaylist = musicLibrary->getBeginPlaylistsIterator();
                for (int i = 0; i <= playlistsList.GetSelection(); i++)
                    selectedPlaylist++;
                wxSingleChoiceDialog audioTracksList(NULL, "Select desired audiotrack:", "Add track to playlist", (*musicLibrary->getBeginPlaylistsIterator())->getArrayString());
                if (audioTracksList.ShowModal() == wxID_OK) {
                    wxString desiredAudiotrackTitle = audioTracksList.GetStringSelection();
                    bool duplicate = (*selectedPlaylist)->checkPossibleDuplicateTrack(desiredAudiotrackTitle);
                    if (duplicate) {
                        wxMessageDialog errorMessage(NULL, "File already present in the playlist", "Error!");
                        errorMessage.ShowModal();

                    } else {
                        auto desiredAudioTrack = musicLibrary->getBeginAudioTracksIterator();
                        while ((*desiredAudioTrack)->getFileName() != desiredAudiotrackTitle)
                            desiredAudioTrack++;
                        concreteController->addTrackPlaylist(*desiredAudioTrack, *selectedPlaylist);
                        if (playlist == selectedPlaylist)
                            updatePlaylist(selectedPlaylist);
                    }
                }
            }
        }
    }
}

void MusicLibraryFrame::menuItemPlaylistDeleteTrackOnMenuSelection(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    auto mLPlaylist = musicLibrary->getBeginPlaylistsIterator();
    mLPlaylist++;
    if(mLPlaylist == musicLibrary->getEndPlaylistsIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not new playlists!", "Error!");
        errorMessage.ShowModal();
    }
    else {
        wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Remove track to playlist", playlistsNames);
        if (playlistsList.ShowModal() == wxID_OK) {
            auto selectedPlaylist = musicLibrary->getBeginPlaylistsIterator();
            for (int i = 0; i <= playlistsList.GetSelection(); i++)
                selectedPlaylist++;
            if((*selectedPlaylist)->getBeginIterator() == (*selectedPlaylist)->getEndIterator()) {
                wxMessageDialog errorMessage(NULL, "Ops!!! There are not audiotracks in this playlist!", "Error!");
                errorMessage.ShowModal();
            }
            else {
                wxSingleChoiceDialog audioTracksList(NULL, "Select desired audiotrack:", "Remove track to playlist", (*selectedPlaylist)->getArrayString());
                if (audioTracksList.ShowModal() == wxID_OK) {
                    concreteController->removeTrackPlaylist(audioTracksList.GetSelection(), *selectedPlaylist);
                    if (playlist == selectedPlaylist)
                        updatePlaylist(playlist);
                }
            }
        }
    }
}

void MusicLibraryFrame::menuItemPlaylistChangeNameOnMenuSelection(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    auto mLPlaylist = musicLibrary->getBeginPlaylistsIterator();
    mLPlaylist++;
    if(mLPlaylist == musicLibrary->getEndPlaylistsIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not new playlists!\n Create a new playlist?", "Error!", wxOK | wxCANCEL | wxCENTRE);
        if(errorMessage.ShowModal() == wxID_OK)
            newPlaylist();
    }
    else {
        wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Change Name", playlistsNames);
        if (playlistsList.ShowModal() == wxID_OK) {
            auto playlistPos = playlistsList.GetSelection();
            auto selectedPlaylist = musicLibrary->getBeginPlaylistsIterator();
            for (int i = 0; i <= playlistPos; i++)
                selectedPlaylist++;
            wxTextEntryDialog playlistName(NULL, "Playlist name:", "Insert new name", (*selectedPlaylist)->getName());
            if (playlistName.ShowModal() == wxID_OK) {
                if (playlistName.GetValue() == "") {
                    wxMessageDialog errorMessage(NULL, "Insert a name for the playlist!!!", "Error!");
                    errorMessage.ShowModal();
                } else {
                    concreteController->changePlaylistName(playlistName.GetValue(), *selectedPlaylist);
                    playlistsNames.Insert(playlistName.GetValue(), static_cast<size_t>(playlistPos));
                    playlistPos++;
                    playlistsNames.RemoveAt(static_cast<size_t>(playlistPos));
                    update();
                }
            }
        }
    }
}

void MusicLibraryFrame::audioTrackListItemOnClick(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        mediaCtrlAudioTrack->Stop();
    int audioTrackPos = audioTrackList->GetSelection();
    audioTrack = (*playlist)->getAudioTrack(audioTrackPos);
    playAudioTrack(audioTrack);
}



void MusicLibraryFrame::OnMediaLoaded(wxCommandEvent &event) {
    if(!mediaCtrlAudioTrack->Play()) {
        wxMessageDialog errorMessage(NULL, "File not found!!!", "Error!");
        errorMessage.ShowModal();
    }
}

void MusicLibraryFrame::newPlaylist() {
    wxTextEntryDialog playlistName(NULL, "Playlist name:", "Insert playlist name", "NewPlaylist");
    if(playlistName.ShowModal() == wxID_OK) {
        if (playlistName.GetValue() == "") {
            wxMessageDialog errorMessage(NULL, "Insert a name for the playlist!!!", "Error!");
            errorMessage.ShowModal();
            newPlaylist();
        }
        else {
            concreteController->newPlaylist(playlistName.GetValue());
            auto it = musicLibrary->getEndPlaylistsIterator();
            it--;
            playlistsNames.Add((*it)->getName());
            playlist = it;
            update();
            int i = static_cast<int>(playlistList->GetCount());
            i--;
            playlistList->SetSelection(i);
            updatePlaylist(playlist);
        }
    }
}

void MusicLibraryFrame::newAudioTrack() {
    wxFileDialog newAudioTrack(NULL, "Choose a mp3 file:", wxEmptyString, wxEmptyString, "*.mp3");
    if (newAudioTrack.ShowModal() == wxID_OK) {
        wxString selectedTrackTitle = newAudioTrack.GetFilename();
        bool duplicate = (*musicLibrary->getBeginPlaylistsIterator())->checkPossibleDuplicateTrack(selectedTrackTitle);
        if (duplicate) {
            wxMessageDialog errorMessage(NULL, "File already present in the music library", "Error!");
            errorMessage.ShowModal();
        }
        else {
            wxString prePath = "file://";
            prePath.Append(newAudioTrack.GetPath());
            concreteController->newAudioTrack(selectedTrackTitle, prePath, &mediaCtrlAudioTrack);
            if (playlist == musicLibrary->getBeginPlaylistsIterator()) 
                updatePlaylist(playlist);
        }

    }
}

void MusicLibraryFrame::buttonPlayOnButtonClick(wxCommandEvent &event) {
    if((*playlist)->getBeginIterator() != (*playlist)->getEndIterator()) {
        if (mediaCtrlAudioTrack->GetState() == wxMEDIASTATE_STOPPED) {
            if (audioTrack == (*playlist)->getEndIterator()) {
                audioTrack = (*playlist)->getBeginIterator();
                audioTrackList->SetSelection(0);
            }
            playAudioTrack(audioTrack);
        } else if (mediaCtrlAudioTrack->GetState() == wxMEDIASTATE_PAUSED)
            mediaCtrlAudioTrack->Play();
    }
    else {
        wxMessageDialog errorMessage(NULL, "No file in this playlist!!!", "Error!");
        errorMessage.ShowModal();
    }
}

void MusicLibraryFrame::buttonPauseOnButtonClick(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() == wxMEDIASTATE_PLAYING)
        mediaCtrlAudioTrack->Pause();
}

void MusicLibraryFrame::playAudioTrack(std::list<AudioTrack*>::iterator au) {
    if ((*playlist)->getBeginIterator() != (*playlist)->getEndIterator()) {
        if (au == (*playlist)->getEndIterator()) {
            wxMessageDialog errorMessage(NULL, "No file selected!!!", "Error!");
            errorMessage.ShowModal();
        } else {
            if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
                mediaCtrlAudioTrack->Stop();
            bool load = mediaCtrlAudioTrack->Load(static_cast<wxURI>((*au)->getFilePath()));
            if (!load) {
                wxMessageDialog errorMessage(NULL, "File not found!!!", "Error!");
                errorMessage.ShowModal();
            }
        }
    }
}

void MusicLibraryFrame::OnMediaFinished(wxCommandEvent &event) {
    if(musicLibrary->isShuffle()){
        int nextPos = (*playlist)->getRandomAudioTrack(audioTrack);
        auto au = (*playlist)->getAudioTrack(nextPos);
        audioTrack = au;
        audioTrackList->SetSelection(nextPos);
        playAudioTrack(audioTrack);
    }
    else {
        audioTrack++;
        if (audioTrack == (*playlist)->getEndIterator()) {
            if (musicLibrary->isLoop()) {
                audioTrack = (*playlist)->getBeginIterator();
                audioTrackList->SetSelection(0);
                playAudioTrack(audioTrack);
            } else {
                playlist++;
                if (playlist == musicLibrary->getEndPlaylistsIterator()) {
                    playlist = musicLibrary->getBeginPlaylistsIterator();
                    playlistList->SetSelection(0);
                } else {
                    int i = playlistList->GetSelection();
                    i++;
                    playlistList->SetSelection(i);
                }
                updatePlaylist(playlist);
                audioTrackList->SetSelection(wxNOT_FOUND);
                audioTrack = (*playlist)->getEndIterator();
            }
        } else {
            int i = audioTrackList->GetSelection();
            i++;
            audioTrackList->SetSelection(i);
            playAudioTrack(audioTrack);
        }
    }
}
