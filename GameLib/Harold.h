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
    /// Rotation angle in radians for Harold
    double mRotation;

    /// The Item Image
    std::unique_ptr<wxImage> mItemImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mItemBitmap;

public:
    Harold(Game *game);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

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
    double GetHeight() const override { return mItemImage->GetHeight(); }

    /**
     * Get the Width of the Image for Harold
     * @return Image Width for Harold
     */
    double GetWidth() const override { return mItemImage->GetWidth(); }

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitHarold(this); }
};

#endif //INC_335PROJECT1_HAROLD_H
