/**
 * @file TAHitVisitor.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_TAHITVISITOR_H
#define INC_335PROJECT1_TAHITVISITOR_H

#include "TA.h"

/**
 * Visitor to determine and set whether a TA is
 * Hit by the Pen
 */
class TAHitVisitor : public ItemVisitor {
private:
    /// Boolean indicating whether the TA is hit or not
    bool mIsHit = false;
public:
    void VisitTA(TA* ta) override;

    bool GetHit();
};

#endif //INC_335PROJECT1_TAHITVISITOR_H
