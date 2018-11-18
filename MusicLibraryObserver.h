//
// Created by jacopo on 10/11/18.
//

#ifndef MP3_MUSICLIBRARYOBSERVER_H
#define MP3_MUSICLIBRARYOBSERVER_H

#include "Observer.h"
#include "DisplayElements.h"
#include "MusicLibrary.h"

class MusicLibraryObserver : public Observer, public DisplayElements {
public:
    void update() override;
    void display();

private:
    MusicLibrary* musicLibrary;

};


#endif //MP3_MUSICLIBRARYOBSERVER_H
