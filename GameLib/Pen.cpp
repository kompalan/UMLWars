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
cse335::Vector InitialPos = cse335::Vector(10, 800);

const double Velocity = 500;

/**
 * Constructor
 * @param game Game object for forward reference
 */
Pen::Pen(Game* game) : Item(game, InitialPos.X(), InitialPos.Y() )
{
    mItemImage = std::make_unique<wxImage>(PenImageName, wxBITMAP_TYPE_ANY);
}

/**
 * Draw Harold On the Screen and Handle his Rotation
 * using wxGraphicsContext
 * @param graphics wxGraphicsContext object
 */
void Pen::Draw(wxGraphicsContext* graphics)
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

void Pen::HandleMouseDown(double virtualX, double virtualY)
{
    if (!isThrown)
    {
        double diffX = virtualX - (GetX());
        double diffY = virtualY - (GetY());

        // Rotate the Image to Point Harolds Hand Towards the Mouse
        double angle = atan2(diffY, diffX);
        mVelocity.SetX(Velocity *cos(angle));
        mVelocity.SetY(Velocity *sin(angle));

        isThrown = true;
    }
}

void Pen::Update(double elapsed)
{
    double newX = GetX() + mVelocity.X() * elapsed;
    double newY = GetY() + mVelocity.Y() * elapsed;
    SetLocation(newX, newY);
}