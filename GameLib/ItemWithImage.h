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
    /// The Item Image
    std::shared_ptr<wxImage> mImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mBitmap;

public:
    /// Default constructor (disabled)
    ItemWithImage() = delete;

    /// Copy constructor (disabled)
    ItemWithImage(const ItemWithImage &) = delete;

    /// Assignment operator
    void operator=(const ItemWithImage &) = delete;

    /**
     * Get the image of the item
     * @return the image of the item
     */

    std::shared_ptr<wxImage> GetImage() {return mImage;}
    /**
     * Get the Height of the Image for Pen
     * @return Image Height for Pen
     */
    double GetHeight() const override { return mImage->GetHeight(); }

    /**
     * Get the Width of the Image for Pen
     * @return Image Width for Pen
     */
    double GetWidth() const override { return mImage->GetWidth(); }

    /**
     * Get the Bitmap for Items
     * @return mBitmap member variable
     */
    auto GetGraphicsBitmap() {return mBitmap;}

    /**
     * Renew the Bitmap member variable value
     * @param varBitmap wxGraphicsBitmap type variable
     */
    void SetGraphicsBitmap(const wxGraphicsBitmap& varBitmap) {mBitmap = varBitmap;}

protected:
    ItemWithImage(Game *game, double posX, double posY, std::wstring imageName);

};

#endif //INC_335PROJECT1_ITEMWITHIMAGE_H
