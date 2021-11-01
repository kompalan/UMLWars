/**
 * @file ItemWithImage.h
 * @author Kristian Rica
 *
 *
 */

#ifndef INC_335PROJECT1_ITEMWITHIMAGE_H
#define INC_335PROJECT1_ITEMWITHIMAGE_H

#pragma once
#include "Item.h"

/**
 *  Class for Items which Have an image associated
 *  with them
 */
class ItemWithImage : public Item{
private:
    Game *mGame;

    /// The Item Image
    std::unique_ptr<wxImage> mImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mBitmap;

public:
    /**
        * Deleted Default Constructor
        */
    ItemWithImage() = delete;

    /**
     * Deleted Copy Constructor
     * @param item
     */
    ItemWithImage(const ItemWithImage &itemwithImage) = delete;

protected:
    ItemWithImage(Game *game, double posX, double posY, const std::wstring& imageName);

};

#endif //INC_335PROJECT1_ITEMWITHIMAGE_H
