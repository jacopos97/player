cmake_minimum_required(VERSION 3.12)
project(MP3)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED COMPONENTS net core base media)
include(${wxWidgets_USE_FILE})
add_subdirectory(test)
set(SOURCE_FILES AudioTrack.cpp Playlist.cpp MusicLibrary.cpp MusicLibraryFrame.cpp Controller.h ConcreteController.cpp)
add_executable(MP3 main.cpp )
add_library(core ${SOURCE_FILES} )
target_link_libraries(MP3 core ${wxWidgets_LIBRARIES})

