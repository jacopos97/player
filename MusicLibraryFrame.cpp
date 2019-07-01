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
	//this->drawMusicLibraryFrame();


	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMusicLibrary;
	bSizerMusicLibrary = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerLibraryMusic;
	bSizerLibraryMusic = new wxBoxSizer( wxHORIZONTAL );
	
	playlistList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	playlistList->SetMinSize( wxSize( 90,-1 ) );
    //playlistList->Append("Musiclibrary");

	
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
	//mediaState = mediaCtrlAudioTrack->GetState();
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
	//audioTrack = (*playlist)->getBeginIterator();
	update();


	mediaCtrlAudioTrack->Load(static_cast<wxURI>("file:///home/jacopo/Musica/Julie_Li_-_01_-_resound.mp3"));
	//mediaCtrlAudioTrack->Load("Scott_Holmes_-_Our_Big_Adventure.mp3");


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
    /*
    auto musicLibraryAudioTracksIterator = musicLibrary->getBeginAudioTracksIterator();
    while(audioTracks.size() != musicLibrary->getAudioTracksSize()) {
        audioTracks.push_back(*musicLibraryAudioTracksIterator);
        musicLibraryAudioTracksIterator++;
    }
    auto musicLibraryPlaylistIterator = musicLibrary->getBeginPlaylistsIterator();
    while (playlists.size() != musicLibrary->getPlaylistsSize()) {
        playlists.push_back(*musicLibraryPlaylistIterator);
        musicLibraryPlaylistIterator++;
    }


    musicLibraryLoop = musicLibrary->isLoop();
    musicLibraryShuffle = musicLibrary->isShuffle();



      Refresh();
      Update();
  */

    playlistList->Clear();
    auto musicLibraryPlaylistIterator = musicLibrary->getBeginPlaylistsIterator();
    auto endPlaylistIterator = musicLibrary->getEndPlaylistsIterator();
    while (musicLibraryPlaylistIterator != endPlaylistIterator) {
        playlistList->Append((*musicLibraryPlaylistIterator)->getName());
        musicLibraryPlaylistIterator++;
    }
/*
    audioTrackList->Clear();
    auto musicLibraryAudioTrackIterator = musicLibrary->getBeginAudioTracksIterator();
    auto endAudioTrackIterator = musicLibrary->getEndAudioTracksIterator();
    while (musicLibraryAudioTrackIterator != endAudioTrackIterator) {
        audioTrackList->Append(musicLibraryAudioTrackIterator->getFileName());
        musicLibraryAudioTrackIterator++;
    }
    */
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
    if (mediaCtrlAudioTrack->GetState() != wxMEDIASTATE_STOPPED)
        (*playlist)->play();
}


void MusicLibraryFrame::menuItemPlaylistNewOnMenuSelection(wxCommandEvent &event) {
    newPlaylist();
    //wxTextEntryDialog playlistName(NULL, "Playlist name:", "Insert playlist name", "NewPlaylist", wxOK | wxCENTRE | wxWS_EX_VALIDATE_RECURSIVELY);
    /*
    wxTextEntryDialog playlistName(NULL, "Playlist name:", "Insert playlist name", "NewPlaylist");
    if(playlistName.ShowModal() == wxID_OK) {
        concreteController->newPlaylist(playlistName.GetValue());
        auto it = musicLibrary->getEndPlaylistsIterator();
        it--;
        playlistsNames.Add((*it)->getName());
        update();
    }
     */
}

void MusicLibraryFrame::menuItemPlaylistDeleteOnMenuSelection(wxCommandEvent &event) {
    auto mLPlaylist = musicLibrary->getBeginPlaylistsIterator();
    mLPlaylist++;
    if(mLPlaylist == musicLibrary->getEndPlaylistsIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not effaceable playlists!", "Error!");
        errorMessage.ShowModal();
    }
    else {
        //void** ptr = nullptr;
        //wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Delete playlist", playlistsNames, ptr, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER | wxOK | wxCENTRE);
        wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Delete playlist", playlistsNames);
        if (playlistsList.ShowModal() == wxID_OK) {
            //wxString selectedPlaylistName = playlistsList.GetStringSelection();
            int desiredPlaylistIndex = playlistsList.GetSelection();
            /*
            auto selectedPlaylist = musicLibrary->getBeginPlaylistsIterator();
            selectedPlaylist++;
            for(int i = 0; i <= desiredPlaylistIndex; i++)
                selectedPlaylist++;
                */
            /*
            while ((*selectedPlaylist)->getName() != selectedPlaylistName)
                selectedPlaylist++;
                */
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
            //playlistsNames.Remove(selectedPlaylistName);
        }
    }
}

void MusicLibraryFrame::menuItemAudioTrackAddOnMenuSelection(wxCommandEvent &event) {
    newAudioTrack();
    /*
    wxFileDialog newAudioTrack(NULL, "Choose a mp3 file:", wxEmptyString, wxEmptyString, "*.mp3");
    if(newAudioTrack.ShowModal() == wxID_OK) {
        wxString selectedTrackTitle = newAudioTrack.GetFilename();
        bool duplicate = (*musicLibrary->getBeginPlaylistsIterator())->checkPossibleDuplicateTrack(selectedTrackTitle);
        if (duplicate) {
            wxMessageDialog errorMessage(NULL, "File already present in the music library", "Error!");
            errorMessage.ShowModal();
        } else {
            concreteController->newAudioTrack(selectedTrackTitle, static_cast<wxURI>(newAudioTrack.GetPath()),
                                              mediaCtrlAudioTrack);
            auto it = musicLibrary->getEndAudioTracksIterator();
            it--;
            //audiotracksTitles.Add((*it)->getFileName());
            if (playlist == musicLibrary->getBeginPlaylistsIterator())
                updatePlaylist(playlist);


            //wxURI path = newAudioTrack.GetPath();
            //mediaCtrlAudioTrack->Load(path);
            //mediaCtrlAudioTrack->Load(selectedTrackTitle);
            //mediaCtrlAudioTrack->LoadURI(selectedTrackTitle);
            //mediaCtrlAudioTrack->LoadURI(newAudioTrack.GetPath());


        }
    }
     */
}

void MusicLibraryFrame::menuItemAudioTrackDeleteOnMenuSelection(wxCommandEvent &event) {
    //auto mLPlaylist = musicLibrary->getBeginPlaylistsIterator();
    //auto mLTrackIterator = (*musicLibrary->getBeginPlaylistsIterator())->getBeginIterator();
    if((*musicLibrary->getBeginPlaylistsIterator())->getBeginIterator() == (*musicLibrary->getBeginPlaylistsIterator())->getEndIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not effaceable audiotracks!", "Error!");
        errorMessage.ShowModal();
    }
    else {
        //void** ptr = nullptr;
        //wxSingleChoiceDialog audioTracksList(NULL, "Select desired audiotrack:", "Remove track ", (*musicLibrary->getBeginPlaylistsIterator())->getArrayString(), ptr, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER | wxOK | wxCENTRE);
        wxSingleChoiceDialog audioTracksList(NULL, "Select desired audiotrack:", "Remove track ",
                                             (*musicLibrary->getBeginPlaylistsIterator())->getArrayString());
        if (audioTracksList.ShowModal() == wxID_OK) {

            //audiotracksTitles.RemoveAt(static_cast<size_t>(audioTracksList.GetSelection()));

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

    auto it = musicLibrary->getBeginPlaylistsIterator();
    for(int i = 1; i <= playlistList->GetSelection(); i++)
       it++;
    if (playlist != it) {
        playlist = it;
        updatePlaylist(playlist);
    }
    if ((*playlist)->getBeginIterator() != (*playlist)->getEndIterator())
        (*playlist)->play();
/*

    wxBoxSizer* bSizerMainFrame;
    bSizerMainFrame = new wxBoxSizer( wxVERTICAL );

    audioTrackList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
    audioTrackList->SetMinSize( wxSize( -1,160 ) );

    bSizerMainFrame->Add( audioTrackList, 0, wxALL|wxEXPAND, 0 );

    wxBoxSizer* bSizerMediaCtrl;
    bSizerMediaCtrl = new wxBoxSizer( wxHORIZONTAL );

    mediaCtrlAudioTrack = new wxMediaCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
    mediaCtrlAudioTrack->SetPlaybackRate(1);
    mediaCtrlAudioTrack->SetVolume(1);

    mediaCtrlAudioTrack->Stop();
    bSizerMediaCtrl->Add( mediaCtrlAudioTrack, 1, wxALL|wxEXPAND, 0 );

    wxBoxSizer* bSizerButtons;
    bSizerButtons = new wxBoxSizer( wxVERTICAL );

    buttonLoop = new wxButton( this, wxID_ANY, wxT("Loop"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizerButtons->Add( buttonLoop, 1, 0, 0 );

    buttonShuffle = new wxButton( this, wxID_ANY, wxT("Shuffle"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizerButtons->Add( buttonShuffle, 1, wxALL, 0 );


    bSizerMediaCtrl->Add( bSizerButtons, 0, wxALIGN_BOTTOM|wxEXPAND, 0 );

    buttonHome = new wxButton( this, wxID_ANY, wxT("Home"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizerMediaCtrl->Add( buttonHome, 0, wxALL|wxEXPAND, 0 );


    bSizerMainFrame->Add( bSizerMediaCtrl, 1, wxALL|wxEXPAND, 0 );


    this->SetSizer( bSizerMainFrame );
    bSizerMainFrame->Show(true);
    this->Layout();
    menuBar = new wxMenuBar( 0 );
    menuMusicLibrary = new wxMenu();
    wxMenuItem* menuItemAudioTrackAdd;
    menuItemAudioTrackAdd = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("Add") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackAdd );

    wxMenuItem* menuItemAudioTrackRemove;
    menuItemAudioTrackRemove = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("Remove") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackRemove );

    wxMenuItem* menuItemAudioTrackMove;
    menuItemAudioTrackMove = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("Move") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackMove );

    menuBar->Append( menuMusicLibrary, wxT("AudioTrack") );

    this->SetMenuBar( menuBar );


    this->Centre( wxBOTH );

    buttonHome->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonHomeOnButtonClick ), NULL, this );
*/
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
            //void** ptr = nullptr;
            //wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Add track to playlist", playlistsNames, ptr, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER | wxOK | wxCENTRE);
            wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Add track to playlist", playlistsNames);
            if (playlistsList.ShowModal() == wxID_OK) {
                /*
                wxString selectedPlaylistName = playlistsList.GetStringSelection();
                auto selectedPlaylist = musicLibrary->getBeginPlaylistsIterator();
                while((*selectedPlaylist)->getName() != selectedPlaylistName)
                    selectedPlaylist++;
                */
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
                        // (*selectedPlaylist)->addTrack(*desiredAudioTrack);
                        if (playlist == selectedPlaylist)
                            updatePlaylist(selectedPlaylist);
                    }
                }
            }
        }
    }
}

void MusicLibraryFrame::menuItemPlaylistDeleteTrackOnMenuSelection(wxCommandEvent &event) {
    auto mLPlaylist = musicLibrary->getBeginPlaylistsIterator();
    mLPlaylist++;
    if(mLPlaylist == musicLibrary->getEndPlaylistsIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not new playlists!", "Error!");
        errorMessage.ShowModal();
    }
    else {
        //void** ptr = nullptr;
        //wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Remove track to playlist", playlistsNames, ptr, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER | wxOK | wxCENTRE);
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


                    /*
                    auto desiredAudiotrack = audioTracksList.GetStringSelection();
                    auto it = (*selectedPlaylist)->getBeginIterator();
                    int index = 0;
                    while ((*it)->getFileName() != desiredAudiotrack){
                        it++;
                    concreteController->removeTrackPlaylist();
                    if (playlist == selectedPlaylist)
                        updatePlaylist(playlist);
                        */
                }
            }
        }
    }
}

void MusicLibraryFrame::menuItemPlaylistChangeNameOnMenuSelection(wxCommandEvent &event) {
    auto mLPlaylist = musicLibrary->getBeginPlaylistsIterator();
    mLPlaylist++;
    if(mLPlaylist == musicLibrary->getEndPlaylistsIterator()) {
        wxMessageDialog errorMessage(NULL, "Ops!!! There are not new playlists!\n Create a new playlist?", "Error!", wxOK | wxCANCEL | wxCENTRE);
        if(errorMessage.ShowModal() == wxID_OK)
            newPlaylist();
    }
    else {
        //void** ptr = nullptr;
        //wxSingleChoiceDialog playlistsList(NULL, "Select desired playlist:", "Change Name", playlistsNames, ptr, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER | wxOK | wxCENTRE);
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
    int audioTrackPos = audioTrackList->GetSelection();
    auto it = (*playlist)->getBeginIterator();
    /*
    for (int index = 0; index <= audioTrackPos; index++)
        it++;
        */
    int index = 0;
    while (index != audioTrackPos) {
        index++;
        it++;
    }
    //audioTrack = it;
    //(*playlist)->playAudioTrack(*it);
    concreteController->playTrackPlaylist((*playlist), (*it));
}



void MusicLibraryFrame::OnMediaLoaded(wxCommandEvent &event) {
    mediaCtrlAudioTrack->Play();
    //mediaState = mediaCtrlAudioTrack->GetState();
}

void MusicLibraryFrame::newPlaylist() {
    //wxTextEntryDialog playlistName(NULL, "Playlist name:", "Insert playlist name", "NewPlaylist", wxOK | wxCENTRE | wxWS_EX_VALIDATE_RECURSIVELY);
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
            update();
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
            //wxURI filePath = static_cast<wxURI>(prePath.Append(newAudioTrack.GetPath()));
            concreteController->newAudioTrack(selectedTrackTitle, prePath, &mediaCtrlAudioTrack);
            auto it = musicLibrary->getEndAudioTracksIterator();
            it--;
            //audiotracksTitles.Add((*it)->getFileName());
            if (playlist == musicLibrary->getBeginPlaylistsIterator())
                updatePlaylist(playlist);


            //wxURI path = newAudioTrack.GetPath();
            //mediaCtrlAudioTrack->Load(path);
            //mediaCtrlAudioTrack->Load(selectedTrackTitle);
            //mediaCtrlAudioTrack->LoadURI(selectedTrackTitle);
            //mediaCtrlAudioTrack->LoadURI(newAudioTrack.GetPath());


        }

    }
}

void MusicLibraryFrame::buttonPlayOnButtonClick(wxCommandEvent &event) {
    /*
    if (mediaState == wxMEDIASTATE_PLAYING) {
        mediaCtrlAudioTrack->Pause();
        mediaState = mediaCtrlAudioTrack->GetState();
    }
    else {
        if(mediaState == wxMEDIASTATE_STOPPED)
            (*playlist)->play();
    }
     */
    if (mediaCtrlAudioTrack->GetState() == wxMEDIASTATE_STOPPED)
        if ((*playlist)->getBeginIterator() != (*playlist)->getEndIterator())
            (*playlist)->play();
    if (mediaCtrlAudioTrack->GetState() == wxMEDIASTATE_PAUSED)
        mediaCtrlAudioTrack->Play();

}

void MusicLibraryFrame::buttonPauseOnButtonClick(wxCommandEvent &event) {
    if (mediaCtrlAudioTrack->GetState() == wxMEDIASTATE_PLAYING)
        mediaCtrlAudioTrack->Pause();
}


/*
bool MusicLibraryFrame::OnExit(wxCommandEventFunction) {
    return false;
}

*/



/*
void MusicLibraryFrame::buttonHomeOnButtonClick(wxCommandEvent &event) {

    this->drawMusicLibraryFrame();
    this->update();


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

    wxBoxSizer* bSizerButtons;
    bSizerButtons = new wxBoxSizer( wxVERTICAL );

    buttonLoop = new wxButton( this, wxID_ANY, wxT("Loop"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizerButtons->Add( buttonLoop, 1, wxALL, 0 );

    buttonShuffle = new wxButton( this, wxID_ANY, wxT("Shuffle"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizerButtons->Add( buttonShuffle, 1, 0, 0 );


    bSizerMediaCtrl->Add( bSizerButtons, 0, wxALL|wxALIGN_BOTTOM|wxEXPAND, 0 );


    bSizerAudioTrack->Add( bSizerMediaCtrl, 1, wxALL|wxEXPAND, 0 );


    bSizerLibraryMusic->Add( bSizerAudioTrack, 1, wxALL|wxEXPAND, 0 );


    bSizerMusicLibrary->Add( bSizerLibraryMusic, 1, wxALL|wxEXPAND, 0 );


    this->SetSizer( bSizerMusicLibrary );
    this->Layout();
    menuBar = new wxMenuBar( 0 );
    menuPlaylist = new wxMenu();
    wxMenuItem* menuItemPlaylistNew;
    menuItemPlaylistNew = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("New") ) , wxEmptyString, wxITEM_NORMAL );
    menuPlaylist->Append( menuItemPlaylistNew );

    wxMenuItem* menuItemPlaylistDelete;
    menuItemPlaylistDelete = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
    menuPlaylist->Append( menuItemPlaylistDelete );

    menuBar->Append( menuPlaylist, wxT("Playlist") );

    menuMusicLibrary = new wxMenu();
    wxMenuItem* menuItemAudioTrackAdd;
    menuItemAudioTrackAdd = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("Add") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackAdd );

    wxMenuItem* menuItemAudioTrackDelete;
    menuItemAudioTrackDelete = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackDelete );

    menuBar->Append( menuMusicLibrary, wxT("AudioTrack") );

    this->SetMenuBar( menuBar );


    this->Centre( wxBOTH );


}
*/


/*
void MusicLibraryFrame::drawMusicLibraryFrame() {
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

    wxBoxSizer* bSizerButtons;
    bSizerButtons = new wxBoxSizer( wxVERTICAL );

    buttonLoop = new wxButton( this, wxID_ANY, wxT("Loop"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizerButtons->Add( buttonLoop, 1, wxALL, 0 );

    buttonShuffle = new wxButton( this, wxID_ANY, wxT("Shuffle"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizerButtons->Add( buttonShuffle, 1, 0, 0 );


    bSizerMediaCtrl->Add( bSizerButtons, 0, wxALL|wxALIGN_BOTTOM|wxEXPAND, 0 );


    bSizerAudioTrack->Add( bSizerMediaCtrl, 1, wxALL|wxEXPAND, 0 );


    bSizerLibraryMusic->Add( bSizerAudioTrack, 1, wxALL|wxEXPAND, 0 );


    bSizerMusicLibrary->Add( bSizerLibraryMusic, 1, wxALL|wxEXPAND, 0 );


    this->SetSizer( bSizerMusicLibrary );
    this->Layout();
    menuBar = new wxMenuBar( 0 );
    menuPlaylist = new wxMenu();
    wxMenuItem* menuItemPlaylistNew;
    menuItemPlaylistNew = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("New") ) , wxEmptyString, wxITEM_NORMAL );
    menuPlaylist->Append( menuItemPlaylistNew );

    wxMenuItem* menuItemPlaylistDelete;
    menuItemPlaylistDelete = new wxMenuItem( menuPlaylist, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
    menuPlaylist->Append( menuItemPlaylistDelete );

    menuBar->Append( menuPlaylist, wxT("Playlist") );

    menuMusicLibrary = new wxMenu();
    wxMenuItem* menuItemAudioTrackAdd;
    menuItemAudioTrackAdd = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("Add") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackAdd );

    wxMenuItem* menuItemAudioTrackDelete;
    menuItemAudioTrackDelete = new wxMenuItem( menuMusicLibrary, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
    menuMusicLibrary->Append( menuItemAudioTrackDelete );

    menuBar->Append( menuMusicLibrary, wxT("AudioTrack") );

    this->SetMenuBar( menuBar );


    this->Centre( wxBOTH );



    // Connect Events
    buttonLoop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonLoopOnButtonClick ), NULL, this );
    buttonShuffle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MusicLibraryFrame::buttonShuffleOnButtonClick ), NULL, this );
    menuPlaylist->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemPlaylistNewOnMenuSelection ), this, menuItemPlaylistNew->GetId());
    menuPlaylist->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemPlaylistDeleteOnMenuSelection ), this, menuItemPlaylistDelete->GetId());
    menuMusicLibrary->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemAudioTrackAddOnMenuSelection ), this, menuItemAudioTrackAdd->GetId());
    menuMusicLibrary->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MusicLibraryFrame::menuItemAudioTrackDeleteOnMenuSelection ), this, menuItemAudioTrackDelete->GetId());
    playlistList->Bind(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(MusicLibraryFrame::playlistListItemOnClick), this, playlistList->GetId());

}

*/






