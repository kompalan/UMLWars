/**
 * @file MainFrame.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_MAINFRAME_H
#define INC_335PROJECT1_MAINFRAME_H

class MainFrame : public wxFrame
{
private:

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&);
    void OnClose(wxCloseEvent &event);

public:
    void Initialize();

};

#endif //INC_335PROJECT1_MAINFRAME_H
