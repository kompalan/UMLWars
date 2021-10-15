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
    graphics->Translate(GetX(), GetY());
    graphics->Rotate(PenAngle);
    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    graphics->DrawBitmap(mItemBitmap,
            GetWidth()/2,
            GetHeight()/2,
            GetWidth(),
            GetHeight());
    graphics->PopState();
}