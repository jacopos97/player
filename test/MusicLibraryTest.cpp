//
// Created by jacopo on 23/03/19.
//

#include "gtest/gtest.h"

#include "../MusicLibrary.h"

TEST(MusicLibrary, TestConstructor) {
    auto ml = new MusicLibrary();
    ASSERT_EQ(false, ml->isShuffle());
    ASSERT_EQ(false, ml->isLoop());
}


TEST(MusicLibrary, TestNewAudioTrack) {
    auto ml = new MusicLibrary();
    wxString fileName1 = "file1";
    wxURI path = static_cast<wxURI>("path");
    wxString frameName = "Frame";
    auto frame = new wxFrame(NULL, wxID_ANY, frameName, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, wxFrameNameStr);
    auto media = new wxMediaCtrl(frame , wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
    ml->newAudioTrack(fileName1, path, &media);
    auto au1 = new AudioTrack(fileName1, path, &media);
    ASSERT_EQ(*au1, *(*ml->getBeginAudioTracksIterator()));
    ASSERT_EQ(*au1, *(*(*ml->getBeginPlaylistsIterator())->getBeginIterator()));
}

TEST(MusicLibrary, TestRemoveAudioTrack) {
    auto ml = new MusicLibrary();
    wxString fileName1 = "file1";
    wxURI path1 = static_cast<wxURI>("path1");
    wxString frameName = "Frame";
    auto frame = new wxFrame(NULL, wxID_ANY, frameName, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, wxFrameNameStr);
    auto media = new wxMediaCtrl(frame , wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
    ml->newAudioTrack(fileName1, path1, &media);
    wxString fileName2= "file2";
    wxURI path2 = static_cast<wxURI>("path2");
    ml->newAudioTrack(fileName2, path2, &media);
    wxString fileName3 = "file3";
    wxURI path3 = static_cast<wxURI>("path3");
    ml->removeAudioTrack(1);
    auto it = ml->getBeginAudioTracksIterator();
    auto it1 = (*ml->getBeginPlaylistsIterator())->getBeginIterator();
    ASSERT_EQ((*it)->getFileName(), fileName1);
    ASSERT_EQ((*it1)->getFileName(), fileName1);
    it++;
    it1++;
    ASSERT_EQ((*it)->getFileName(), fileName3);
    ASSERT_EQ((*it1)->getFileName(), fileName3);
    it++;
    it1++;
    ASSERT_EQ(ml->getEndAudioTracksIterator(), it);
    ASSERT_EQ((*ml->getBeginPlaylistsIterator())->getEndIterator(), it);
}