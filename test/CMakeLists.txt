cmake_minimum_required(VERSION 3.12)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(wxWidgets REQUIRED COMPONENTS net core base media)
include(${wxWidgets_USE_FILE})
set(TEST_SOURCE_FILES runAllTests.cpp AudioTrackTest.cpp PlaylistTest.cpp PlaylistFixture.cpp MusicLibraryTest.cpp MusicLibraryFixture.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core ${wxWidgets_LIBRARIES})