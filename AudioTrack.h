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
#include "Subject.h"


class AudioTrack : public Subject  {
public:

    AudioTrack(int length, std::string t, std::string f,std::string a = "Unknown author", std::string i = "") : audioTrackTime(length), currentTime(0), author(std::move(a)),image(std::move(i)), title(std::move(t)), fileName(std::move(f)){};
    /*
     AudioTrack(wxSize length, const wxString &name, const wxString &fileName,std::string a = "Unknown author", std::string i = "") : audioTrackTime(length), currentTime(wxDefaultPosition), author(std::move(a)),image(std::move(i)), title(name), fileName(fileName){
        wxMediaCtrl media;
        bool mediaValidation;
        wxWindow parent;
        mediaValidation = media.Create(parent.GetParent(), wxID_ANY, fileName, currentTime, length);
        if (!mediaValidation)
            std::cout << "File not found!\n";
    };
     */
    bool operator==(AudioTrack a);
    bool operator!=(AudioTrack a);
    void playAudioTrack();
    void restart();
    void pause();
    ~AudioTrack() override = default;
    int getCurrentTime() const;
    const int getAudioTrackTime() const;
    const std::string &getTitle() const;
    const std::string &getFileName() const;
    const std::string &getAuthor() const;
    const std::string &getImage() const;
    void registerObserver (Observer *o) override;
    void removeObserver (Observer *o) override;
    void notifyObserver () override;
    /*
    wxPoint getCurrentTime() const;
    const wxSize getAudioTrackTime() const;
    const wxString &getTitle() const;
    const wxString &getFileName() const;
     */



private:

    const int audioTrackTime;
    int currentTime;
    std::string author;
    std::string image;
    std::string title;
    std::string fileName;
    std::list<Observer*> observers;
    /*
    wxSize audioTrackTime;
    wxPoint currentTime;
    std::string author;
    std::string image;
    wxString title;
    wxString fileName;*/


};


#endif //MP3_AUDIOTRACK_H
