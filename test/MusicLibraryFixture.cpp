//
// Created by jacopo on 23/03/19.
//

#include "gtest/gtest.h"

#include "../MusicLibrary.h"


class MusicLibrarySuite :public ::testing::Test {
protected:
    virtual void SetUp() {
        wxString name1 = "name1";
        wxString name2 = "name2";
        wxString name3 = "name3";
        ml.newPlaylist(name1);
        ml.newPlaylist(name2);
        ml.newPlaylist(name3);
    }
    MusicLibrary ml;
};


TEST_F(MusicLibrarySuite, TestNewPlaylist) {
    wxString name4 = "name4";
    ml.newPlaylist(name4);
    auto it = ml.getBeginPlaylistsIterator();
    ASSERT_EQ((*it)->getName(), "Musiclibrary");
    it++;
    ASSERT_EQ((*it)->getName(), "name1");
    it++;
    ASSERT_EQ((*it)->getName(), "name2");
    it++;
    ASSERT_EQ((*it)->getName(), "name3");
    it++;
    ASSERT_EQ((*it)->getName(), name4);
    it++;
    ASSERT_EQ(it, ml.getEndPlaylistsIterator());
}


TEST_F(MusicLibrarySuite, TestRemovePlaylist) {
    ml.removePlaylist(1);
    auto it = ml.getBeginPlaylistsIterator();
    ASSERT_EQ((*it)->getName(), "Musiclibrary");
    it++;
    ASSERT_EQ((*it)->getName(), "name1");
    it++;
    ASSERT_EQ((*it)->getName(), "name3");
    it++;
    ASSERT_EQ(it, ml.getEndPlaylistsIterator());
}




