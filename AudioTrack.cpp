//
// Created by jacopo on 19/10/18.
//

#include "AudioTrack.h"



bool AudioTrack::operator==(const AudioTrack& a) const {
    return (fileName == a.fileName);
}

bool AudioTrack::operator!=(const AudioTrack& a) const {
    return (fileName != a.fileName);
}


const wxString &AudioTrack::getFileName() const {
    return fileName;
 }


const wxString &AudioTrack::getFilePath() const {
    return filePath;
}
