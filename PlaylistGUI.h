///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  8 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PLAYLISTGUI_H__
#define __PLAYLISTGUI_H__

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

#include "Observer.h"
#include "Playlist.h"

#include "ConcreteController.h"
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class mainFrame
///////////////////////////////////////////////////////////////////////////////
class mainFrame : public wxFrame, public Observer {

private:

    Playlist* playlist;
    std::list <AudioTrack> audioTracks;
    std::string playlistName;
    bool playlistLoop;
    bool playlitstShuffle;

    ConcreteController* concreteController; // da non copiare


protected:
    wxListBox* listAudioTracks;
    wxMediaCtrl* mediaCtrl;
    wxButton* buttonLoop;
    wxButton* buttonShuffle;
    wxButton* buttonHome;
    wxMenuBar* menuBar;
    wxMenu* menuAudioTrack;

    // Virtual event handlers, overide them in your derived class
    virtual void buttonLoopOnButtonClick( wxCommandEvent& event );
    virtual void buttonShuffleOnButtonClick( wxCommandEvent& event );
    virtual void buttonHomeOnButtonClick( wxCommandEvent& event );
    virtual void menuItemAudioTrackAddOnMenuSelection( wxCommandEvent& event );
    virtual void menuItemAudioTrackRemoveOnMenuSelection( wxCommandEvent& event );
    virtual void menuItemAudioTrackMoveOnMenuSelection( wxCommandEvent& event );

public:

    mainFrame(ConcreteController* conCon, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Playlist"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

  //  void update() override;
    void display();


    ~mainFrame();
};

#endif //__PLAYLISTGUI_H__
