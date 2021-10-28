/**
 * @file ItemWithImage.h
 * @author Kristian Rica
 *
 *
 */

#ifndef INC_335PROJECT1_ITEMWITHIMAGE_H
#define INC_335PROJECT1_ITEMWITHIMAGE_H

#pragma once
#include "pch.h"
#include "Item.h"

class ItemWithImage : public Item{
private:
    /// The Item Image
    std::unique_ptr<wxImage> mImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mBitmap;

public:

};

#endif //INC_335PROJECT1_ITEMWITHIMAGE_H
