#include <utility>

//
// Created by jacopo on 19/10/18.
//

#ifndef MP3_AUDIOTRACK_H
#define MP3_AUDIOTRACK_H


#include <string>
#include "Subject.h"


class AudioTrack: public Subject {
public:
    AudioTrack(double length, std::string t, std::string f,std::string a = "Unknown author", std::string i = ""): audioTrackTime(length), currentTime(0), author(std::move(a)),image(std::move(i)), title(std::move(t)), fileName(std::move(f)){};
    bool operator==(const AudioTrack a);
    bool operator!=(const AudioTrack a);
    void playAudioTrack();
    void restart();
    void pause();
    ~AudioTrack() = default;
    double getCurrentTime() const;
    double getAudioTrackTime() const;
    const std::string &getTitle() const;
    const std::string &getFileName() const;
    const std::string &getAuthor() const;


private:
    const double audioTrackTime;
    double currentTime;
    std::string author;
    std::string image;
    std::string title;
    std::string fileName;
};


#endif //MP3_AUDIOTRACK_H
