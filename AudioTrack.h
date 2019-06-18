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

    //AudioTrack(int length, std::string t, std::string f,std::string a = "Unknown author", std::string i = "") : audioTrackTime(length), currentTime(0), author(std::move(a)),image(std::move(i)), title(std::move(t)), fileName(std::move(f)){};
/*
    AudioTrack(int length, std::string &name, const wxString &fileName, std::string a = "Unknown author", std::string i = "") : audioTrackTime(length), currentTime(0), author(std::move(a)),image(std::move(i)), title(std::move(name)), fileName(fileName){

        bool mediaValidation;
        wxWindow parent;
        mediaValidation = fileMedia.Create(parent.GetParent() , wxID_ANY, fileName);
        if (!mediaValidation)
            std::cout << "File not found!\n";

    }

    AudioTrack(const AudioTrack& au): audioTrackTime(au.audioTrackTime), currentTime(au.currentTime), author(au.author), image(au.image), title(au.title), fileName(au.fileName){

        bool mediaValidation;
        wxWindow parent;
        mediaValidation = fileMedia.Create(parent.GetParent(), wxID_ANY, fileName);
        if (!mediaValidation)
            std::cout << "File not found!\n";

    }
    */

    AudioTrack(const wxString &fileName, const wxURI &filePath, wxMediaCtrl** mediaCtrl) {

        AudioTrack::fileName = fileName;
        AudioTrack::filePath = filePath;
        fileMedia = mediaCtrl;


        /*
        AudioTrack::parent = parent;
        bool mediaValidation = fileMedia.Create(AudioTrack::parent, wxID_ANY, fileName);
        if (!mediaValidation)
            std::cout << "File not found!\n";
            */
    }

    AudioTrack(const AudioTrack &au) {

        fileName = au.getFileName();
        filePath = au.getFilePath();
        fileMedia = au.fileMedia;
        /*
        parent = au.parent;
        bool mediaValidation = fileMedia.Create(parent, wxID_ANY, fileName);
        if (!mediaValidation)
            std::cout << "File not found!\n";
        */
    }


    bool operator==(const AudioTrack& a) const ;
    bool operator!=(const AudioTrack& a) const;
    void playAudioTrack();
    void restart();
    void pause();

    ~AudioTrack() override = default;

    //int getCurrentTime() const;
    //const int getAudioTrackTime() const;
    //const std::string &getTitle() const;

    //const std::string &getFileName() const;

    //const std::string &getAuthor() const;
    //const std::string &getImage() const;
    void registerObserver (Observer *o) override;
    void removeObserver (Observer *o) override;
    void notifyObserver () override;

    const wxString &getFileName() const;
    const wxURI &getFilePath() const;



private:
    /*
    const int audioTrackTime;
    int currentTime;
    std::string author;
    std::string image;
    std::string title;
    std::string audioTrackName;
     */
    std::list<Observer*> observers;

/*
    std::string author;
    std::string title;
*/
    wxString fileName;
    wxURI filePath;
    wxMediaCtrl** fileMedia;

    //wxWindow* parent;



};


#endif //MP3_AUDIOTRACK_H
