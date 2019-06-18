//
// Created by jacopo on 02/03/19.
//

#include "gtest/gtest.h"

#include "../Playlist.h"

TEST(Playlist, TestConstructor) {
    wxString name = "new";
    Playlist pl(name);
    ASSERT_EQ("new", pl.getName());
    ASSERT_EQ(false, pl.isLoop());
    ASSERT_EQ(false, pl.isShuffle());
}

TEST(Playlist, TestChangeName) {
    Playlist pl;
    pl.changeName("My hits");
    ASSERT_EQ(pl.getName(), "My hits");
}