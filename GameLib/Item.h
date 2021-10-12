/**
 * @file Item.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_ITEM_H
#define INC_335PROJECT1_ITEM_H
#include "pch.h"
#include <wx/graphics.h>

class Game; ///< Forward Reference to the Game Class

/**
 * Class Representing a Specific Item on the Screen
 *
 */
class Item {
private:
    /// Reference to game object for forward reference
    Game *mGame;

    double mX; ///< X location for the center of the item in virtual pixels
    double mY; ///< Y location for the center of the item in virtual pixels

    /// The Item Image
    std::unique_ptr<wxImage> mItemImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mItemBitmap;

public:
    double GetX() const;
    double GetY() const;

    virtual void Draw(wxGraphicsContext *graphics);

    /**
     * Set the Item Location
     * @param x X location in virtual pixels
     * @param y Y location in virtual pixels
     */
    void SetLocation(double x, double y) { mX = x; mY = y; }

    /**
     * Handle updates for animation
     * @param elapsed Time since last onDraw call
     */
     virtual void Update(double elapsed) {}

    /**
     * Deleted Default Constructor
     */
    Item() = delete;

    /**
     * Deleted Copy Constructor
     * @param item
     */
    Item(const Item &item) = delete;

    /**
     * Deleted Assignment Operator
     * @param item
     */
    void operator=(const Item &item) = delete;
protected:

    Item(Game *game, const std::wstring &filename);
};

#endif //INC_335PROJECT1_ITEM_H
