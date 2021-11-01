/**
 * @file Harold.cpp
 * @author Anurag
 */

#include "pch.h"
#include "Harold.h"
#include "ItemWithImage.h"

/// Harold Filename
const std::wstring HaroldImageName = L"images/harold.png";

/// Rotation angle for Harold's Hand
const double HaroldsHand = 1.078;

/// Harold's Initial Position on the Screen
cse335::Vector InitialPosition = cse335::Vector(0, 900);

/**
 * Constructor
 * @param game Game object for forward reference
 */
Harold::Harold(Game* game) : ItemWithImage(game, InitialPosition.X(), InitialPosition.Y(), HaroldImageName)
{

}

/**
 * Draw Harold On the Screen and Handle his Rotation
 * using wxGraphicsContext
 * @param graphics wxGraphicsContext object
 */
void Harold::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    graphics->Translate(GetX(), GetY());
    graphics->Rotate(mRotation);
    if(GetGraphicsBitmap().IsNull())
    {
        SetGraphicsBitmap(graphics->CreateBitmapFromImage(*GetImage()));
    }

    graphics->DrawBitmap(GetGraphicsBitmap(),
            -GetWidth()/2,
            -GetHeight()/2,
            GetWidth(),
            GetHeight());
    graphics->PopState();
}

/**
 * When the mouse moves to a certain X, Y position,
 * calculate the angle of rotation and set mRotation accordingly
 * @param virtualX X coordinate of the mouse in virtual pixels
 * @param virtualY Y coordinate of the mouse in virtual pixels
 */
void Harold::HandleMouseMove(double virtualX, double virtualY)
{
    double diffX = virtualX - (GetX());
    double diffY = virtualY - (GetY());

    /// Rotate the Image to Point Harold's Hand Towards the Mouse
    mRotation = atan2(diffY, diffX) + HaroldsHand;
}
