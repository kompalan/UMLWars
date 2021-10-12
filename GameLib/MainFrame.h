/**
 * @file MainFrame.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_MAINFRAME_H
#define INC_335PROJECT1_MAINFRAME_H

#include "WarsView.h"

/**
 * The MainFrame Class. This class represents a Frame that Holds
 * our Game View. It also defines Menu Options on the Frame
 */
class MainFrame : public wxFrame
{
private:
    /// The WarsView Object
    WarsView *mGameView;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&);
    void OnClose(wxCloseEvent &event);

public:
    void Initialize();

};

#endif //INC_335PROJECT1_MAINFRAME_H
