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

/// Integer representing how many points we need for TA to activate
const int TAScoreThreshold = 15;

/**
 * Constructor
 * @param game Game object to pass to item
 */
TA::TA(Game* game) :ItemWithImage(game, InitialPosition.X(), InitialPosition.Y(), TAImageName)
{
    mItemImage = std::make_unique<wxImage>(TAImageName, wxBITMAP_TYPE_ANY);
    mGame = game;
}

/**
 * Draws the TA On the Screen. Depending on the state
 * of the TA, it could be at different places with different
 * sizes
 * @param graphics Graphics context object pointer
 */
void TA::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    /// Font of the categories
    wxFont smallFont(wxSize(0, 40),
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    /// Font of the Scoreboard
    wxFont bigFont(wxSize(0, 85),
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    /// Color of the Scoreboard
    wxColour cyanBlue = wxColour(0,200,200);
    graphics->SetFont(bigFont,cyanBlue);

    graphics->PushState();
    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    if (mTAState == State::Spawned)
    {
        graphics->DrawBitmap(mItemBitmap,
                GetX(),
                GetY(),
                GetWidth(),
                GetHeight());

        graphics->DrawText(L"Hit Me!",-600,900);
    }
    else if (mTAState == State::Hit)
    {
        SetLocation(InitialPosition.X(), InitialPosition.Y());
        graphics->DrawBitmap(mItemBitmap,
                GetX(),
                GetY(),
                0,
                0);
        /// Call some function in game to remove all TA and switch the state to not spawned
        mGame->DeleteAllBadUML(this);
        mTAState = State::NotSpawned;
    }
    else
    {
        SetLocation(InitialPosition.X(), InitialPosition.Y());
        graphics->DrawBitmap(mItemBitmap,
                GetX(),
                GetY(),
                0,
                0);

        graphics->DrawText(std::to_string(15-mScoreCount),-600,900);
        graphics->SetFont(smallFont,cyanBlue);
        graphics->DrawText(L"TA in:",-600,850);
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
        SetLocation(-250, 850);
        mScoreCount = 0;
        mTAState = State::Spawned;
    }
}

bool TA::SetHitState()
{
    if (mTAState == State::Spawned)
    {
        mTAState = State::Hit;
    }

    return true;
}
