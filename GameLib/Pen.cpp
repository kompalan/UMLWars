/**
 * @file Pen.cpp
 * @author Yichen Ding
 */
#include "pch.h"
#include "Pen.h"
#include "Game.h"

const std::wstring PenImageName = L"images/redpen.png";

/// The angle of Pen
const double PenAngle = 1;

/// Pen's Initial Position on the Screen
cse335::Vector InitialPos = cse335::Vector(3, 850);

const double Velocity = 500;

/**
 * Constructor
 * @param game Game object for forward reference
 */
Pen::Pen(Game* game) : Item(game, InitialPos.X(), InitialPos.Y() )
{
    mItemImage = std::make_unique<wxImage>(PenImageName, wxBITMAP_TYPE_ANY);
    mGame = game;
}

/**
 * Draw Pen On the Screen and Handle his Rotation
 * using wxGraphicsContext
 * @param graphics wxGraphicsContext object
 */
void Pen::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();

    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    graphics->DrawBitmap(mItemBitmap,
            GetX(),
            GetY(),
            GetWidth(),
            GetHeight());
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
    if (!isThrown)
    {
        double diffX = virtualX - (GetX());
        double diffY = virtualY - (GetY());

        // Rotate the Image to Point Pen Hand Towards the Mouse
        double angle = atan2(diffY, diffX);
        mVelocity.SetX(Velocity *cos(angle));
        mVelocity.SetY(Velocity *sin(angle));

        isThrown = true;
    }
}

/**
 * Update Pen On the Screen and Handle its moving
 * using wxGraphicsContext
 * @param elapsed elapsed value to update
 */
void Pen::Update(double elapsed)
{
    double newX = GetX() + mVelocity.X() * elapsed;
    double newY = GetY() + mVelocity.Y() * elapsed;
    SetLocation(newX, newY);
}

/**
 * When Pen goes out of the Screen and Handle its resetting
 * @param x position x on screen
 * @param y position y on screen
 */
void Pen::SetLocation(double x, double y)
{
    auto tempGame = GetGame();
    int bound_height = tempGame->GetHeight();
    int bound_width = tempGame->GetWidth();
    if(x > bound_width || y > bound_height || x < -1* bound_width || y < -1*bound_height)
    {
        mVelocity = cse335::Vector();
        x = InitialPos.X();
        y = InitialPos.Y();
        isThrown = false;
    }
    AdditonalSet(x,y);

    if(isThrown) {
        mGame->RemoveOnHit(this);
    }
}

/**
 * Patch Fix to Return Pen To Harold After Pen Hit
 * Something
 */
void Pen::ReturnToHarold()
{
    SetLocation(InitialPos.X(), InitialPos.Y());
    mVelocity = cse335::Vector();
    isThrown = false;
}
