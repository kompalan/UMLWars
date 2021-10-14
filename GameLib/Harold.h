/**
 * @file Harold.h
 * @author Anurag
 *
 *
 */

#ifndef INC_335PROJECT1_HAROLD_H
#define INC_335PROJECT1_HAROLD_H

#include "Item.h"
#include "Vector.h"

/**
 * Class Representing the Main Character: Harold
 */
class Harold : public Item {
private:
    double mRotation; ///< Rotation angle in radians for Harold

    double mX; ///< X location for the center of the item in virtual pixels
    double mY; ///< Y location for the center of the item in virtual pixels

    /// The Item Image
    std::unique_ptr<wxImage> mItemImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mItemBitmap;

public:
    Harold(Game *game);
    void Draw(wxGraphicsContext *graphics) override;
    void HandleMouseMove(double virtualX, double virtualY) override;

    /**
     * Get the Rotation in Radians for Harold
     * @return Rotation in Radians
     */
    double GetRotation() const {return mRotation;}

    /**
     * Get the Height of the Image for Harold
     * @return Image Height for Harold
     */
    double GetHeight() const { return mItemImage->GetHeight(); }

    /**
     * Get the Width of the Image for Harold
     * @return Image Width for Harold
     */
    double GetWidth() const { return mItemImage->GetWidth(); }
};

#endif //INC_335PROJECT1_HAROLD_H
