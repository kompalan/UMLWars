/**
 * @file TA.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_TA_H
#define INC_335PROJECT1_TA_H
#include "Item.h"

/**
 * Class for the TA Item
 */
class TA : public Item {
private:
    /// Enum representing the states a TA could take
    enum State {
        NotSpawned,
        Spawned,
        Hit
    };

    /// State Object representing the state of the TA
    State mTAState = State::NotSpawned;

    /// The Item Image
    std::unique_ptr<wxImage> mItemImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mItemBitmap;

    /// Game object to call delete methods on
    Game *mGame;

    /// Integer tracking the running correct score for the User
    int mScoreCount = 0;

public:
    TA(Game *game);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update(double elapsed) override;

    /**
     * Transition the TA State to Hit
     */
    void SetHitState() { mTAState = State::Hit; }

    /**
     * Increment the Score Counter
     */
    void IncrementScoreCount() { mScoreCount++; }

    /**
     * Get the Height of the Image for Sparty
     * @return Image Height for Sparty
     */
    double GetHeight() const override { return mItemImage->GetHeight(); }

    /**
     * Get the Width of the Image for Sparty
     * @return Image Width for Sparty
     */
    double GetWidth() const override { return mItemImage->GetWidth(); }

    /**
     * Accept the Visitor for this class and call VisitTA on it
     * @param visitor ItemVisitor object
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitTA(this); }
};

#endif //INC_335PROJECT1_TA_H
