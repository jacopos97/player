cmake_minimum_required(VERSION 3.12)
project(MP3)


set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
add_subdirectory(test)
set(SOURCE_FILES AudioTrack.cpp AudioTrack.h Playlist.cpp Playlist.h MusicLibrary.cpp MusicLibrary.h Observer.h Controller.h ConcreteController.h AudioTrackObserver.cpp AudioTrackObserver.h DisplayElements.h PlaylistObserver.cpp PlaylistObserver.h MusicLibraryObserver.cpp MusicLibraryObserver.h Subject.h)
add_executable(MP3 main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(MP3 core ${wxWidgets_LIBRARIES})

