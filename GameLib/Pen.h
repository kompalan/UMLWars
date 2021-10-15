/**
 * @file Pen.h
 * @author Yichen Ding
 *
 *
 */

#include "Item.h"
#include "Vector.h"
#ifndef INC_335PROJECT1_PEN_H
#define INC_335PROJECT1_PEN_H

class Pen : public Item {
private:
    ///< Rotation angle in radians for Harold
    double mRotation;

    /// The Item Image
    std::unique_ptr<wxImage> mItemImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mItemBitmap;

    cse335::Vector mVelocity = cse335::Vector();

    bool isThrown = false;

public:
    Pen(Game *game);
    void Draw(wxGraphicsContext *graphics) override;

    /**
     * Get the Height of the Image for Pen
     * @return Image Height for Pen
     */
    double GetHeight() const { return mItemImage->GetHeight(); }

    /**
     * Get the Width of the Image for Pen
     * @return Image Width for Pen
     */
    double GetWidth() const { return mItemImage->GetWidth(); }

    void HandleMouseDown(double virtualX, double virtualY) override;
    void Accept(ItemVisitor* visitor) override {};

    void Update(double elapsed) override;

//    void Accept(ItemVisitor* visitor) override {};
};

#endif //INC_335PROJECT1_PEN_H
