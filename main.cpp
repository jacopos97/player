#include <wx/wx.h>
#include "MusicLibraryFrame.h"
#include "ConcreteController.h"
#include "MusicLibrary.h"

class AudioPlayer : public wxApp {
public:
    bool OnInit() override {
            auto *mls = new MusicLibrary();
            auto *conCon = new ConcreteController(mls);
            MusicLibraryFrame *myFrame = new MusicLibraryFrame(conCon, mls, NULL);
            myFrame->Show(true);
            return true;
    }
};

wxIMPLEMENT_APP(AudioPlayer);