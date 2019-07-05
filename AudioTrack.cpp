//
// Created by jacopo on 19/10/18.
//

#include "AudioTrack.h"


/*
void AudioTrack::playAudioTrack() {
    bool path = (*fileMedia)->Load(static_cast<wxURI>(filePath));
    if (!path) {
        wxMessageDialog errorMessage(NULL, "File not found!!!", "Error!");
        errorMessage.ShowModal();
    }
    else {
        (*fileMedia)->Play();

        auto mediaLength = (*fileMedia)->Length();
        while((*fileMedia)->GetState() == wxMEDIASTATE_PLAYING)
            if((*fileMedia)->Tell() == mediaLength)
                (*fileMedia)->Stop();

        //while((*fileMedia)->Tell() == mediaLength)
    }
}
*/
/*
void AudioTrack::restart() {

    //this->playAudioTrack();
}
*/

bool AudioTrack::operator==(const AudioTrack& a) const {
    return (fileName == a.fileName);
}

bool AudioTrack::operator!=(const AudioTrack& a) const {
    return (fileName != a.fileName);
}
/*
int AudioTrack::getCurrentTime() const {
    return currentTime;
}

const int AudioTrack::getAudioTrackTime() const {
    return audioTrackTime;
}
 */
/*
const std::string &AudioTrack::getTitle() const {
    return title;
}
*/
/*
const std::string &AudioTrack::getFileName() const {
    return fileName;
}
*/



const wxString &AudioTrack::getFileName() const {
    return fileName;
 }

/*
const std::string &AudioTrack::getAuthor() const {
    return author;
}
 */
/*
const std::string &AudioTrack::getImage() const {
    return image;
}
*/
/*
void AudioTrack::pause() {
     //fileMedia.Pause();
}
*/
void AudioTrack::registerObserver(Observer *o) {
    observers.push_back(o);
}

void AudioTrack::removeObserver(Observer *o) {
    observers.remove(o);
}

void AudioTrack::notifyObserver() {
    auto it = observers.begin();
    while (it != observers.end()) {
        (*it)->update();
        it++;
    }
}

const wxString &AudioTrack::getFilePath() const {
    return filePath;
}
/*
void AudioTrack::OnMediaLoaded(wxCommandEvent &event) {
    if((*fileMedia)->Play()) {
        wxMessageDialog errorMessage(NULL, "Couldn't play file!!!", "Error!");
        errorMessage.ShowModal();
    }
}
*/


