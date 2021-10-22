/**
 * @file Pen.h
 * @author Yichen Ding
 *
 *
 */

#ifndef INC_335PROJECT1_PEN_H
#define INC_335PROJECT1_PEN_H


#include "Item.h"
#include "Vector.h"

class Pen : public Item {
private:
    ///< Rotation angle in radians for Pen
    double mRotation = 0.0;

    /// The Item Image
    std::unique_ptr<wxImage> mItemImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mItemBitmap;

    /// Define the initial Velocity
    cse335::Vector mVelocity = cse335::Vector();

    /// Determiane if Harold firstly throws
    bool isThrown = false;

    Game *mGame;

    std::shared_ptr<Harold> mHarold;

    /// the time counter for pen
    double mTime = 0;

    bool mRecord = false;

public:
    Pen(Game *game);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Get the Height of the Image for Pen
     * @return Image Height for Pen
     */
    double GetHeight() const override { return mItemImage->GetHeight(); }

    /**
     * Get the Width of the Image for Pen
     * @return Image Width for Pen
     */
    double GetWidth() const override { return mItemImage->GetWidth(); }


    void HandleMouseDown(double virtualX, double virtualY) override;

    void ReturnToHarold();

    /// Accept function
    void Accept(ItemVisitor* visitor) override {};

    void Update(double elapsed) override;

    void HandleMouseMove(double virtualX, double virtualY) override;

    void SetRecord(bool mIf) {mRecord = mIf;}

    void Stop();
};

#endif //INC_335PROJECT1_PEN_H
