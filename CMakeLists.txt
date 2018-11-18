cmake_minimum_required(VERSION 3.12)
project(MP3)


set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
add_executable(MP3 main.cpp AudioTrack.cpp AudioTrack.h Playlist.cpp Playlist.h MusicLibrary.cpp MusicLibrary.h Subject.h Observer.h TestAudioTrack.h Controller.h ConcreteController.cpp ConcreteController.h AudioTrackObserver.cpp AudioTrackObserver.h DisplayElements.h PlaylistObserver.cpp PlaylistObserver.h MusicLibraryObserver.cpp MusicLibraryObserver.h TestPlaylist.h TestMusicLibrary.h)
target_link_libraries(MP3 ${wxWidgets_LIBRARIES})

