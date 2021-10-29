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

const int TAScoreThreshold = 15;

/**
 * Constructor
 * @param game Game object to pass to item
 */
TA::TA(Game* game) :Item(game, InitialPosition.X(), InitialPosition.Y())
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
    graphics->PushState();
    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    if (mTAState == State::Spawned) {
        graphics->DrawBitmap(mItemBitmap,
                GetX(),
                GetY(),
                GetWidth(),
                GetHeight());
    } else if (mTAState == State::Hit) {
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
    if (mScoreCount > TAScoreThreshold && mTAState == State::NotSpawned) {
        SetLocation(0, 200);
        mScoreCount = 0;
        mTAState = State::Spawned;
    }
}
