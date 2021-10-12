/**
 * @file Item.cpp
 * @author Anurag
 */

#include "Item.h"

/**
 * Constructor
 * @param game Game object for forward reference
 * @param filename filename of the image of the item
 */
Item::Item(Game* game, const std::wstring& filename) : mGame(game)
{
    mItemImage = std::make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
}

/**
 * Returns the X position of the item
 * @return X position
 */
double Item::GetX() const
{
    return mX;
}

/**
 * Returns the Y position of the item
 * @return Y position
 */
double Item::GetY() const
{
    return mY;
}

/**
 * Virtual Function that Draws the item on the screen
 * @param graphics wxGraphicsContext
 */
void Item::Draw(wxGraphicsContext* graphics)
{
    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    double width = mItemImage->GetWidth();
    double height = mItemImage->GetHeight();

    graphics->DrawBitmap(mItemBitmap,
            GetX(),
            GetY(),
            width,
            height);
}



