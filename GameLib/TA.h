/**
 * @file TA.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_TA_H
#define INC_335PROJECT1_TA_H
#include "Item.h"

class TA : public Item {
private:
    enum State {
        NotSpawned,
        Spawned,
        Hit
    };

    State mTAState = State::NotSpawned;

    /// The Item Image
    std::unique_ptr<wxImage> mItemImage;

    /// The Bitmap for the Item
    wxGraphicsBitmap mItemBitmap;

    Game *mGame;

    int mScoreCount = 0;

public:
    TA(Game *game);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update(double elapsed) override;
    State GetState() const { return mTAState; }
    void SetState(State state) { mTAState = state; }
    void SetHitState() { mTAState = State::Hit; }
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

    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitTA(this); }


};

#endif //INC_335PROJECT1_TA_H
