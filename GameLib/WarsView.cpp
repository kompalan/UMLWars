/**
 * @file WarsView.cpp
 * @author Anurag Kompalli
 */


#include "pch.h"
#include "WarsView.h"

#include <wx/dcbuffer.h>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the Game View and Bind the Paint and Timer events
 * to their respective handlers. Also Set Up Timer for Animations
 * @param mainFrame Parent MainFrame object to bind to
 */
void WarsView::Initialize(wxFrame* mainFrame)
{
    Create(mainFrame, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &WarsView::OnPaint, this);
    Bind(wxEVT_TIMER, &WarsView::OnTimer, this);
    Bind(wxEVT_MOTION, &WarsView::OnMouseMove, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}

/**
 * Paint Event that Draws the Window
 * @param event Paint Event Object
 */
void WarsView::OnPaint(wxPaintEvent& event)
{
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mGame.Update(elapsed);

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
void WarsView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}

/**
 * Handler for Mouse Move
 * @param event wxWidgets mouse move event
 */
void WarsView::OnMouseMove(wxMouseEvent& event)
{
    mGame.OnMouseMove(event.GetX(), event.GetY());
}
