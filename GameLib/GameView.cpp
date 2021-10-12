/**
 * @file GameView.cpp
 * @author Anurag Kompalli
 */


#include "pch.h"
#include "GameView.h"

#include <wx/dcbuffer.h>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the Game View and Bind the Paint and Timer events
 * to their respective handlers. Also Set Up Timer for Animations
 * @param mainFrame Parent MainFrame object to bind to
 */
void GameView::Initialize(wxFrame* mainFrame)
{
    Create(mainFrame, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}

/**
 * Paint Event that Draws the Window
 * @param event Paint Event Object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.OnDraw(gc.get(), rect.GetWidth(), rect.GetHeight());
}

/**
 * Handler for the Timer Event
 * @param event Timer Event Object
 */
void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}
