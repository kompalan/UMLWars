/**
 * @file WarsView.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_WARSVIEW_H
#define INC_335PROJECT1_WARSVIEW_H

#include "Game.h"

/**
 * The WarsView Class. This class represents a
 * view that holds the UML Wars Game.
 */
class WarsView : public wxWindow {
private:
    /// Game Object to Manipulate
    Game mGame = Game();

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    void OnPaint(wxPaintEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnMouseMove(wxMouseEvent &event);
    void OnLeftDown(wxMouseEvent &event);
    void OnOriginalVariant(wxCommandEvent&);
    void OnCustomVariant(wxCommandEvent&);
public:
    void Initialize(wxFrame *mainFrame);

    /// Stop Timer After Close
    void Stop() {mTimer.Stop();}

    void AddMenus(wxFrame* mainFrame, wxMenuBar* menuBar);
};

#endif //INC_335PROJECT1_WARSVIEW_H
