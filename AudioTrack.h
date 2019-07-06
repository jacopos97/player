//
// Created by jacopo on 19/10/18.
//

#ifndef MP3_AUDIOTRACK_H
#define MP3_AUDIOTRACK_H


#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <utility>
#include <wx/mediactrl.h>
#include <wx/window.h>
#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/validate.h>
#include <wx/msgdlg.h>






class AudioTrack  {
public:

    AudioTrack(const wxString &fileName, const wxString &filePath, wxMediaCtrl** mediaCtrl) {
        AudioTrack::fileName = fileName;
        AudioTrack::filePath = filePath;
        fileMedia = mediaCtrl;
    }

    AudioTrack(const AudioTrack &au) {
        fileName = au.getFileName();
        filePath = au.getFilePath();
        fileMedia = au.fileMedia;
    }

    bool operator==(const AudioTrack& a) const ;
    bool operator!=(const AudioTrack& a) const;
    ~AudioTrack() = default;
    const wxString &getFileName() const;
    const wxString &getFilePath() const;


private:
    wxString fileName;
    wxString filePath;
    wxMediaCtrl** fileMedia;
};


#endif //MP3_AUDIOTRACK_H
