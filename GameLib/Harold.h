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
#include "ItemWithImage.h"

/**
 * Class Representing the Main Character: Harold
 */
class Harold : public ItemWithImage {
private:
    double mRotation; ///< Rotation angle in radians for Harold

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
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitHarold(this); }
};

#endif //INC_335PROJECT1_HAROLD_H
