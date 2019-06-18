//
// Created by jacopo on 27/02/19.
//

#include <wx/wx.h>
#include "gtest/gtest.h"

#include "../AudioTrack.h"

TEST(AudioTrack, TestConstructor) {
    wxString frameName = "Frame";
    auto frame = new wxFrame(NULL, wxID_ANY, frameName, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, wxFrameNameStr);
    auto media = new wxMediaCtrl(frame , wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
    wxString filename = "filename";
    wxURI path = static_cast<wxURI>("path");
    auto au = new AudioTrack(filename, path, &media);
    ASSERT_EQ(au->getFileName(), filename);
    ASSERT_EQ(au->getFilePath(), path);
}