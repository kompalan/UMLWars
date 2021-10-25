/**
 * @file TA.cpp
 * @author Anurag Kompalli
 */

#include "TA.h"

/// Sparty Filename
const std::wstring TAImageName = L"images/sparty.png";

/// Initial Position
const cse335::Vector InitialPosition = cse335::Vector(0, -200);

TA::TA(Game* game) :Item(game, InitialPosition.X(), InitialPosition.Y())
{
    mItemImage = std::make_unique<wxImage>(TAImageName, wxBITMAP_TYPE_ANY);
    mGame = game;
}

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
        /// Call some function in game to remove all TA and switch the state to not spawned
    }

    graphics->PopState();
}

void TA::Update(double elapsed)
{
    if (mScoreCount > 15) {
        SetLocation(0, 200);
        mScoreCount = 0;
        mTAState = State::Spawned;
    }
}
