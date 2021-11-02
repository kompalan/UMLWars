/**
 * @file TA.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_TA_H
#define INC_335PROJECT1_TA_H
#include "ItemWithImage.h"

/**
 * Class for the TA Item
 */
class TA : public ItemWithImage {
private:
    /// Enum representing the states a TA could take
    enum State {
        NotSpawned,
        Spawned,
        Hit
    };

    /// State Object representing the state of the TA
    State mTAState = State::NotSpawned;

    /// Integer tracking the running correct score for the User
    int mScoreCount = 0;

public:
    TA(Game *game);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update(double elapsed) override;

    /**
     * Transition the TA State to Hit
     */
    bool SetHitState();

    /**
     * Get if the TA is spawned
     * @return boolean of if the TA is spawned
     */
    bool IsSpawned() const { return mTAState == State::Spawned; }

    /**
     * Increment the Score Counter
     */
    void IncrementScoreCount() { if (mTAState == State::NotSpawned) {mScoreCount++;} }

    /**
     * Accept the Visitor for this class and call VisitTA on it
     * @param visitor ItemVisitor object
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitTA(this); }

    /**
     * Setter for TA state to spawned
     */
    void SetSpawned() {mTAState = State::Spawned;}
};

#endif //INC_335PROJECT1_TA_H
