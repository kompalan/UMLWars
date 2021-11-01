/**
 * @file TA.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "TA.h"
#include "Game.h"

/// Sparty Filename
const std::wstring TAImageName = L"images/sparty.png";

/// Initial Position
const cse335::Vector InitialPosition = cse335::Vector(0, -200);

/// TA Hidden Position
const double TAPositionX = -250;

/// Integer representing how many points we need for TA to activate
const int TAScoreThreshold = 15;

/// Score and Hit Me! X position
const double TextPositionX = -600;

/// Score and Hit Me! Y position
const double TextPositionY = 900;

///small Text Y position
const double TAPositionY = 850;

/// String for TA can be used
const std::string TAUsable = "Hit Me!";

/// String for small text "TA in:"
const std::string TACountdown = "TA in:";

///Value of Blue and Green in Cyan color
const double CyanValue = 200;

///Pixel size of small font
const double SmallSize = 40;

///Pixel size of large font
const double LargeSize = 85;

/**
 * Constructor
 * @param game Game object to pass to item
 */
TA::TA(Game* game) :ItemWithImage(game, InitialPosition.X(), InitialPosition.Y(), TAImageName)
{

}

/**
 * Draws the TA On the Screen. Depending on the state
 * of the TA, it could be at different places with different
 * sizes
 * @param graphics Graphics context object pointer
 */
void TA::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    /// Font of the text
    wxFont smallFont(wxSize(0, SmallSize),
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    /// Font of the Countdown and Hit Me! text
    wxFont bigFont(wxSize(0, LargeSize),
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    /// Color of the Font
    wxColour cyanBlue = wxColour(0,CyanValue,CyanValue);

    graphics->SetFont(bigFont,cyanBlue);

    graphics->PushState();
    if(GetGraphicsBitmap().IsNull())
    {
        SetGraphicsBitmap(graphics->CreateBitmapFromImage(*GetImage()));
    }

    if (mTAState == State::Spawned)
    {
        graphics->DrawBitmap(GetGraphicsBitmap(),
                GetX(),
                GetY(),
                GetWidth(),
                GetHeight());

        graphics->DrawText(TAUsable,TextPositionX,TextPositionY);
    }
    else if (mTAState == State::Hit)
    {
        SetLocation(InitialPosition.X(), InitialPosition.Y());
        graphics->DrawBitmap(GetGraphicsBitmap(),
                GetX(),
                GetY(),
                0,
                0);
        /// Call some function in game to remove all TA and switch the state to not spawned
        GetGame()->DeleteAllBadUML(this);
        mTAState = State::NotSpawned;
    }
    else
    {
        SetLocation(InitialPosition.X(), InitialPosition.Y());
        graphics->DrawBitmap(GetGraphicsBitmap(),
                GetX(),
                GetY(),
                0,
                0);

        graphics->DrawText(std::to_string(TAScoreThreshold-mScoreCount),TextPositionX,TextPositionY);
        graphics->SetFont(smallFont,cyanBlue);
        graphics->DrawText(TACountdown,TextPositionX,TAPositionY);
    }


    graphics->PopState();
}

/**
 * Update Function for the TA. Once the
 * Cumulative Score Count is Above a Certain Value
 * then transition the state to spawned and reset the score
 * counter
 * @param elapsed Time since last OnDraw Call in seconds
 */
void TA::Update(double elapsed)
{
    if (mScoreCount >= TAScoreThreshold && mTAState == State::NotSpawned)
    {
        SetLocation(TAPositionX, TAPositionY);
        mScoreCount = 0;
        mTAState = State::Spawned;
    }
}
/**
 * Setter for mTAState to change when hit with pen
 * @return Always returns true
 */
bool TA::SetHitState()
{
    if (mTAState == State::Spawned)
    {
        mTAState = State::Hit;
    }

    return true;
}
