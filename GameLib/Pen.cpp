/**
 * @file Pen.cpp
 * @author Yichen Ding
 */
#include "pch.h"
#include "Pen.h"
#include "Game.h"
#include "ItemWithImage.h"

/// Path to Pen Image
const std::wstring PenImageName = L"images/redpen.png";

/// The angle of Pen
const double PenAngle = 1;

/// Pen's Initial Position on the Screen
cse335::Vector InitialPos = cse335::Vector(0, 850);

/// Velocity of pen in pixels per second
const double Velocity = 1000;

/// Distance at which to keep the pen relative to harold's center
const double Radius = 61.3;

/**
 * Constructor
 * @param game Game object for forward reference
 */
Pen::Pen(Game* game) : ItemWithImage(game, InitialPos.X(), InitialPos.Y(), PenImageName)
{
    mGame = game;
    mHarold = game->GetHarold();
}

/**
 * Draw Pen On the Screen and Handle his Rotation
 * using wxGraphicsContext
 * @param graphics wxGraphicsContext object
 */
void Pen::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();

    if(mPenState==PenState::Held)
    {
        graphics->Translate(mHarold->GetX(), mHarold->GetY());
        graphics->Rotate(mRotation - 4.71);
    }

    if(GetGraphicsBitmap().IsNull())
    {
        SetGraphicsBitmap(graphics->CreateBitmapFromImage(*GetImage()));
    }

    if (mPenState==PenState::Hit)
    {
        graphics->DrawBitmap(GetGraphicsBitmap(),
                0,
                0,
                0,
                0);
    }

    else if(mPenState==PenState::Held)
    {
        graphics->DrawBitmap(GetGraphicsBitmap(),
                -GetWidth()-30,
                -GetHeight()-30,
                GetWidth(),
                GetHeight());
    }
    else
    {
        graphics->Translate(GetX()-10, GetY()-10);
        graphics->Rotate(mThrownRotation- 4.71);
        graphics->DrawBitmap(GetGraphicsBitmap(),
                0,
                0,
                GetWidth(),
                GetHeight());
    }
    graphics->PopState();
}

/**
 * Handler to act the mouse click operation
 * @param virtualX X coordinate of the mouse in virtual pixels
 * @param virtualY Y coordinate of the mouse in virtual pixels
 */
void Pen::HandleMouseDown(double virtualX, double virtualY)
{
    /// determine if the pen has been thrown
    if (mPenState==PenState::Held)
    {
        double diffX = virtualX - (GetX());
        double diffY = virtualY - (GetY());

        // Rotate the Image to Point Pen Hand Towards the Mouse
        double angle = atan2(diffY, diffX);
        mVelocity.SetX(Velocity *cos(angle));
        mVelocity.SetY(Velocity *sin(angle));

        mPenState=PenState::Thrown;
        mThrownRotation=mRotation;
    }
}

/**
 * Update Pen On the Screen and Handle its moving
 * using wxGraphicsContext
 * @param elapsed elapsed value to update
 */
void Pen::Update(double elapsed)
{
    if((mPenState==PenState::Thrown || mPenState==PenState::Hit))
    {
        mTime+=elapsed;
        if(mGame->IsCustomSelected())
        {
            CheckBorder();
        }
        double newX = GetX()+mVelocity.X()*elapsed;
        double newY = GetY()+mVelocity.Y()*elapsed;

        auto tempGame = GetGame();
        if (mTime > 1 && mPenState==PenState::Hit) {
            mVelocity = cse335::Vector();
            SetLocation(mHarold->GetX(), mHarold->GetY());
            mPenState=PenState::Held;
            mTime = 0;
        }
        else
        {
            SetLocation(newX, newY);
        }
        mGame->RemoveOnHit(this, mTime);
    }
    else
    {
        SetLocation(mHarold->GetX() + Radius * cos(mRotation -1 ), mHarold->GetY() + Radius * sin(mRotation - 1));
    }
    if (mRecord)
    {
        mTime += elapsed;
    }
    mRotation = mHarold->GetRotation();

}

/**
 * Checks whether the Pen is hitting the border of the screen
 * and sets the X and Y velocity to be opposite. Used for Game Variant
 */
void Pen::CheckBorder(){
    if((GetY() < 0) || (GetY() > mGame->GetHeight())){
        mVelocity.SetY(-mVelocity.Y());
    }
    if((GetX() < ((-mGame->GetWidth()/2) + GetWidth()/2)) || (GetX() > (mGame->GetWidth()/2))){
        mVelocity.SetX(-mVelocity.X());
    }
}

/**
 * Return the Pen To Harold After It Has Hit Something
 */
void Pen::ReturnToHarold()
{
    SetLocation(InitialPos.X(), InitialPos.Y());
    mVelocity = cse335::Vector();
    mPenState=PenState::Held;
    mTime = 0;
}

/**
 * When The pen hit the UML, make it stop there
 * until the time is up, then return
 */
void Pen::Stop()
{
    mPenState = PenState::Hit;
    mVelocity = cse335::Vector();
    mRecord = false;
}
