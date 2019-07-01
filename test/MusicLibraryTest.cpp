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
