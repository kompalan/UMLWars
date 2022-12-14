/**
 * @file WarsView.cpp
 * @author Anurag Kompalli
 */


#include "pch.h"
#include "WarsView.h"
#include "ids.h"

#include <wx/dcbuffer.h>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Miliseconds conversion
const double MiliConversion = 0.001;

/**
 * Initialize the Game View and Bind the Paint and Timer events
 * to their respective handlers. Also Set Up Timer for Animations
 * @param mainFrame Parent MainFrame object to bind to
 */
void WarsView::Initialize(wxFrame* mainFrame)
{
    Create(mainFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &WarsView::OnPaint, this);
    Bind(wxEVT_TIMER, &WarsView::OnTimer, this);
    Bind(wxEVT_MOTION, &WarsView::OnMouseMove, this);
    Bind(wxEVT_LEFT_DOWN, &WarsView::OnLeftDown,this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}

/**
 * Add the menu items for the window
 * @param mainFrame MainFrame object to add menu on
 * @param menuBar wxMenuBar object
 */
void WarsView::AddMenus(wxFrame* mainFrame, wxMenuBar *menuBar)
{
    auto variantMenu = new wxMenu();
    variantMenu->Append(IDM_VARIANT_ORIGINAL, L"&Original", L"Original Variant",wxITEM_CHECK);
    variantMenu->Append(IDM_VARIANT_CUSTOM, L"&Custom", L"Custom Variant",wxITEM_CHECK);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &WarsView::OnOriginalVariant, this, IDM_VARIANT_ORIGINAL);
    mainFrame->Bind(wxEVT_UPDATE_UI, &WarsView::OnUpdateOriginalVariant, this, IDM_VARIANT_ORIGINAL);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &WarsView::OnCustomVariant, this, IDM_VARIANT_CUSTOM);
    mainFrame->Bind(wxEVT_UPDATE_UI, &WarsView::OnUpdateCustomVariant, this, IDM_VARIANT_CUSTOM);
    menuBar->Append(variantMenu, "&Variant");
}

/**
 * Paint Event that Draws the Window
 * @param event Paint Event Object
 */
void WarsView::OnPaint(wxPaintEvent& event)
{
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * MiliConversion;
    mTime = newTime;
    mGame.Update(elapsed);

    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Tell the game class to draw
    wxRect rect = GetRect();

    dc.SetClippingRegion(rect.GetWidth()/2 - (mGame.GetWidth()/2 * mGame.GetScale()),
            rect.GetHeight()/2 - (mGame.GetHeight()/2 * mGame.GetScale()),
            mGame.GetWidth()*mGame.GetScale() ,mGame.GetHeight()*mGame.GetScale());

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    // Draw Background if variant is selected
    if (mGame.IsCustomSelected())
    {
        gc->DrawBitmap(mGame.GetBackground(),
                rect.GetWidth()/2 - (mGame.GetWidth()/2 * mGame.GetScale()),
                rect.GetHeight()/2 - (mGame.GetHeight()/2 * mGame.GetScale()),
                mGame.GetWidth()*mGame.GetScale() ,mGame.GetHeight()*mGame.GetScale());
    }

    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
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

/**
 * Handler for Mouse click
 * @param event wxWidgets mouse move event
 */
void WarsView::OnLeftDown(wxMouseEvent& event)
{
    mGame.OnLeftDown(event.GetX(), event.GetY());
}

/**
 * Handler for the Original Variant Menu Option. Switches the
 * variant off.
 * @param event wxCommandEvent object
 */
void WarsView::OnOriginalVariant(wxCommandEvent& event)
{
        mVariantSelected = false;
        mGame.SwitchVariant(mVariantSelected);

}

/**
 * Handler for the Custom Variant Menu Option. Switches the
 * variant on.
 * @param event wxCommandEvent object
 */
void WarsView::OnCustomVariant(wxCommandEvent& event)
{
        mVariantSelected = true;
        mGame.SwitchVariant(mVariantSelected);
}

/**
 * Update handler for Variant>Original menu option
 * @param event Update event
 */
void WarsView::OnUpdateOriginalVariant(wxUpdateUIEvent& event)
{
    event.Check(!mVariantSelected);
}

/**
 * Update handler for Variant>Custom menu option
 * @param event Update event
 */
void WarsView::OnUpdateCustomVariant(wxUpdateUIEvent& event)
{
    event.Check(mVariantSelected);
}