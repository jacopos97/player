///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "PlaylistGUI.h"

///////////////////////////////////////////////////////////////////////////

mainFrame::mainFrame(ConcreteController* conCon, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	concreteController = conCon;

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMainFrame;
	bSizerMainFrame = new wxBoxSizer( wxVERTICAL );
	
	listAudioTracks = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	listAudioTracks->SetMinSize( wxSize( -1,160 ) );
	
	bSizerMainFrame->Add( listAudioTracks, 0, wxALL|wxEXPAND, 0 );
	
	wxBoxSizer* bSizerMediaCtrl;
	bSizerMediaCtrl = new wxBoxSizer( wxHORIZONTAL );
	
	mediaCtrl = new wxMediaCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
	mediaCtrl->SetPlaybackRate(1);
	mediaCtrl->SetVolume(1);
	
	mediaCtrl->Stop();
	bSizerMediaCtrl->Add( mediaCtrl, 1, wxALL|wxEXPAND, 0 );
	
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
	this->Layout();
	menuBar = new wxMenuBar( 0 );
	menuAudioTrack = new wxMenu();
	wxMenuItem* menuItemAudioTrackAdd;
	menuItemAudioTrackAdd = new wxMenuItem( menuAudioTrack, wxID_ANY, wxString( wxT("Add") ) , wxEmptyString, wxITEM_NORMAL );
	menuAudioTrack->Append( menuItemAudioTrackAdd );
	
	wxMenuItem* menuItemAudioTrackRemove;
	menuItemAudioTrackRemove = new wxMenuItem( menuAudioTrack, wxID_ANY, wxString( wxT("Remove") ) , wxEmptyString, wxITEM_NORMAL );
	menuAudioTrack->Append( menuItemAudioTrackRemove );
	
	wxMenuItem* menuItemAudioTrackMove;
	menuItemAudioTrackMove = new wxMenuItem( menuAudioTrack, wxID_ANY, wxString( wxT("Move") ) , wxEmptyString, wxITEM_NORMAL );
	menuAudioTrack->Append( menuItemAudioTrackMove );
	
	menuBar->Append( menuAudioTrack, wxT("AudioTrack") ); 
	
	this->SetMenuBar( menuBar );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	buttonLoop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::buttonLoopOnButtonClick ), NULL, this );
	buttonShuffle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::buttonShuffleOnButtonClick ), NULL, this );
	buttonHome->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::buttonHomeOnButtonClick ), NULL, this );
	menuAudioTrack->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::menuItemAudioTrackAddOnMenuSelection ), this, menuItemAudioTrackAdd->GetId());
	menuAudioTrack->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::menuItemAudioTrackRemoveOnMenuSelection ), this, menuItemAudioTrackRemove->GetId());
	menuAudioTrack->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::menuItemAudioTrackMoveOnMenuSelection ), this, menuItemAudioTrackMove->GetId());
}

mainFrame::~mainFrame()
{
	// Disconnect Events
	buttonLoop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::buttonLoopOnButtonClick ), NULL, this );
	buttonShuffle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::buttonShuffleOnButtonClick ), NULL, this );
	buttonHome->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::buttonHomeOnButtonClick ), NULL, this );
	
}


/*
void mainFrame::update() {
	auto playlistIterator = playlist->getBeginIterator();
	while (audioTracks.size() != playlist->getSize()) {
		audioTracks.push_back(*playlistIterator);
		playlistIterator++;
	}
	playlistName = playlist->getName();
	playlistLoop = playlist->isLoop();
	playlitstShuffle = playlist->isShuffle();
	display();
}
*/
void mainFrame::display() {

}


void mainFrame::buttonLoopOnButtonClick(wxCommandEvent &event) {
	//concreteController->setLoopPlaylist();
	event.Skip();
}

void mainFrame::buttonShuffleOnButtonClick(wxCommandEvent &event) {
	//concreteController->setShufflePlaylist();
	event.Skip();
}

void mainFrame::buttonHomeOnButtonClick(wxCommandEvent &event) {

	event.Skip();
}

void mainFrame::menuItemAudioTrackAddOnMenuSelection(wxCommandEvent &event) {
	//concreteController->addTrackPlaylist();
	event.Skip();
}

void mainFrame::menuItemAudioTrackRemoveOnMenuSelection(wxCommandEvent &event) {
	//concreteController->removeTrackPlaylist();
	event.Skip();
}

void mainFrame::menuItemAudioTrackMoveOnMenuSelection(wxCommandEvent &event) {
	//concreteController->moveTrackPlaylist();
	event.Skip();
}



