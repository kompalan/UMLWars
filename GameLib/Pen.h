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
#include "ItemWithImage.h"

/**
 * Class for the Pen that Harold Throws
 */
class Pen : public ItemWithImage {
private:
    ///< Rotation angle in radians for Pen
    double mRotation = 0.0;
    /// Stored rotation angle in radians for Pen while Thrown
    double mThrownRotation = 0.0;

    /// Define the initial Velocity
    cse335::Vector mVelocity = cse335::Vector();

    /// Game Object
    Game *mGame;

    /// Harold Object, used for width and height calculations
    std::shared_ptr<Harold> mHarold;

    /// Enum representing States that a pen could take
    enum class PenState
    {
        Held,
        Thrown,
        Hit
    };

    /// PenState object holding the State of the Pen
    PenState mPenState = PenState::Held;

    /// the time counter for pen
    double mTime = 0;

    /// a boolean describing whether we should hold the pen at that position
    bool mRecord = false;

public:
    Pen(Game *game);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void HandleMouseDown(double virtualX, double virtualY) override;

    void ReturnToHarold();

    /**
     * Accept the Item Visitor
     * @param visitor ItemVisitor object
     */
    void Accept(ItemVisitor* visitor) override {};

    void Update(double elapsed) override;

    void CheckBorder();

    /**
     * Set the mRecord boolean to mIf
     * @param mIf Boolean to set
     */
    void SetRecord(bool mIf) {mRecord = mIf;}

    void Stop();

    /**
     * Transitions the pen state to thrown
     */
    void ThrowPen() {mPenState=PenState::Thrown;}

//    /**
//     * Transitions the Pen State to Hit
//     */
//    void HasHit() {mPenState=PenState::Hit;}

    /**
     * Returns a boolean indicating whether the pen is thrown
     * @return True if Pen is thrown otherwise false
     */
    bool IsThrown () {return (mPenState==PenState::Thrown);}
};

#endif //INC_335PROJECT1_PEN_H
