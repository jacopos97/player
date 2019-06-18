//
// Created by jacopo on 02/03/19.
//

#include <wx/wx.h>
#include "gtest/gtest.h"

#include "../Playlist.h"


class PlaylistSuite :public ::testing::Test {
protected:
    virtual void SetUp() {
        //auto window = new wxWindow();
        wxString frameName = "Frame";
        auto frame = new wxFrame(NULL, wxID_ANY, frameName, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, wxFrameNameStr);
        pl.setLoop(true);
        pl.setShuffle(true);
        pl.changeName("Summer hits");
        auto media = new wxMediaCtrl(frame , wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
        wxString fileName1 = "file1";
        wxURI path1 = static_cast<wxURI>("path1");
        auto au1 = new AudioTrack(fileName1, path1, &media);
        wxString fileName2 = "file2";
        wxURI path2 = static_cast<wxURI>("path2");
        auto au2 = new AudioTrack(fileName2, path2, &media);
        wxString fileName3 = "file3";
        wxURI path3 = static_cast<wxURI>("path3");
        auto au3 = new AudioTrack(fileName3, path3, &media);
        pl.addTrack(au1);
        pl.addTrack(au2);
        pl.addTrack(au3);
    }
    Playlist pl;
};

TEST_F (PlaylistSuite, TestAddTrack) {
    wxString frameName = "Frame";
    auto frame = new wxFrame(NULL, wxID_ANY, frameName, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, wxFrameNameStr);
    auto media = new wxMediaCtrl(frame , wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
    /*
    wxString fileName1 = "file1";
    wxURI path1 = static_cast<wxURI>("path1");
    auto au1 = new AudioTrack(fileName1, path1, media);
    wxString fileName2 = "file2";
    wxURI path2 = static_cast<wxURI>("path2");
    auto au2 = new AudioTrack(fileName2, path2, media);
    wxString fileName3 = "file3";
    wxURI path3 = static_cast<wxURI>("path3");
    auto au3 = new AudioTrack(fileName3, path3, media);
     */
    wxString fileName4 = "file4";
    wxURI path4 = static_cast<wxURI>("path4");
    auto au4 = new AudioTrack(fileName4, path4, &media);
    pl.addTrack(au4);
    auto it = pl.getBeginIterator();
    ASSERT_EQ((*it)->getFileName(), "path1");
    it++;
    ASSERT_EQ((*it)->getFileName(), "path2");
    it++;
    ASSERT_EQ((*it)->getFileName(), "path3");
    it++;
    ASSERT_EQ((*it)->getFileName(), "path4");
    it++;
    ASSERT_EQ(it, pl.getEndIterator());
}


TEST_F (PlaylistSuite,TestRemoveTrack) {
    /*
    std::string title1 = "song1";
    std::string fileName1 = "file1";
    AudioTrack au1(1024,title1,fileName1);
    std::string title2 = "song2";
    std::string fileName2 = "file2";
    AudioTrack au2(654,title2,fileName2);
    std::string title3 = "song3";
    std::string fileName3 = "file3";
    AudioTrack au3(3852,title3,fileName3);
     */
    pl.removeTrack(1);
    auto it = pl.getBeginIterator();
    ASSERT_EQ((*it)->getFileName(), "path1");
    it++;
    ASSERT_EQ((*it)->getFileName(), "path3");
    it++;
    ASSERT_EQ((*it),(*pl.getEndIterator()));
}
/*
TEST_F (PlaylistSuite, TestMoveTrack) {
    std::string title1 = "song1";
    std::string fileName1 = "file1";
    AudioTrack au1(1024,title1,fileName1);
    std::string title2 = "song2";
    std::string fileName2 = "file2";
    AudioTrack au2(654,title2,fileName2);
    std::string title3 = "song3";
    std::string fileName3 = "file3";
    AudioTrack au3(3852,title3,fileName3);
    std::string title4 = "song4";
    std::string fileName4 = "file4";
    AudioTrack au4(2347,title4,fileName4);
    std::string title5 = "song5";
    std::string fileName5 = "file5";
    AudioTrack au5(879,title5,fileName5);
    pl.addTrack(au4);
    pl.addTrack(au5);
    auto it = pl.getBeginIterator();
    auto it1 = it;
    it++;
    auto it2 = it;
    it++;
    auto it3 = it;
    it++;
    auto it4 = it;
    it++;
    auto it5 = it;
    pl.moveTrack(it2,it4);
    pl.moveTrack(it1,it5);
    pl.moveTrack(it5,it3);
    pl.moveTrack(it4,it3);
    it = pl.getBeginIterator();
    ASSERT_EQ(it,it5);
    it++;
    ASSERT_EQ(it,it4);
    it++;
    ASSERT_EQ(it,it3);
    it++;
    ASSERT_EQ(it,it2);
    it++;
    ASSERT_EQ(it,it1);
    it++;
    ASSERT_EQ(it,pl.getEndIterator());
}
 */