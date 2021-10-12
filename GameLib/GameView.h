/**
 * @file GameView.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_GAMEVIEW_H
#define INC_335PROJECT1_GAMEVIEW_H

#include "pch.h"
#include "Game.h"

/**
 * The GameView Class. This class represents a
 * view that holds the UML Wars Game.
 */
class GameView : public wxWindow {
private:
    /// Game Object to Manipulate
    Game mGame;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    void OnPaint(wxPaintEvent& event);
    void OnTimer(wxTimerEvent& event);

public:
    void Initialize(wxFrame *mainFrame);

    /// Stop Timer After Close
    void Stop() {mTimer.Stop();}
};

#endif //INC_335PROJECT1_GAMEVIEW_H
