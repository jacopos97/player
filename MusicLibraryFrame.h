///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MUSICLIBRARYFRAME_H__
#define __MUSICLIBRARYFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/mediactrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/arrstr.h>
#include <wx/textdlg.h>
#include <wx/filedlg.h>
#include <wx/choicdlg.h>
#include <list>
#include "MusicLibrary.h"
#include "ConcreteController.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class musicLibraryFrame
///////////////////////////////////////////////////////////////////////////////
class MusicLibraryFrame : public wxFrame{

private:
    MusicLibrary* musicLibrary;
    std::list<Playlist*>::iterator playlist;
    wxArrayString playlistsNames;
    std::list<AudioTrack*>::iterator audioTrack;
    ConcreteController* concreteController;

protected:
    wxListBox* playlistList;
    wxListBox* audioTrackList;
    wxMediaCtrl* mediaCtrlAudioTrack;
    wxButton* buttonLoop;
    wxButton* buttonShuffle;
    wxMenuBar* menuBar;
    wxMenu* menuPlaylist;
    wxMenu* menuMusicLibrary;
    wxButton* buttonPlay;
    wxButton* buttonPause;


    // Virtual event handlers, overide them in your derived class
	virtual void buttonLoopOnButtonClick( wxCommandEvent& event );
	virtual void buttonShuffleOnButtonClick( wxCommandEvent& event );
	virtual void buttonPlayOnButtonClick( wxCommandEvent& event);
    virtual void buttonPauseOnButtonClick( wxCommandEvent& event);
	virtual void menuItemPlaylistNewOnMenuSelection( wxCommandEvent& event );
	virtual void menuItemPlaylistDeleteOnMenuSelection( wxCommandEvent& event );
	virtual void menuItemAudioTrackAddOnMenuSelection( wxCommandEvent& event );
    virtual void menuItemAudioTrackDeleteOnMenuSelection( wxCommandEvent& event );



    virtual void playlistListItemOnClick( wxCommandEvent& event);
    virtual void audioTrackListItemOnClick( wxCommandEvent& event);
    virtual void menuItemPlaylistAddTrackOnMenuSelection( wxCommandEvent& event );
    virtual void menuItemPlaylistDeleteTrackOnMenuSelection( wxCommandEvent& event );
    virtual void menuItemPlaylistChangeNameOnMenuSelection( wxCommandEvent& event );



	void OnMediaLoaded(wxCommandEvent& event);
	void OnMediaFinished(wxCommandEvent& event);
	void newPlaylist();
	void newAudioTrack();
	void playAudioTrack(std::list<AudioTrack*>::iterator au);




public:
		
	MusicLibraryFrame(ConcreteController* conCon, MusicLibrary* ml, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Music Library"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL ) ;


    void update();
    void updatePlaylist(std::list<Playlist*>::iterator it);


    ~MusicLibraryFrame();
	
};


#endif //__MUSICLIBRARYFRAME_H__
