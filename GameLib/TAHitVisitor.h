/**
 * @file TAHitVisitor.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_TAHITVISITOR_H
#define INC_335PROJECT1_TAHITVISITOR_H

#include "TA.h"

class TAHitVisitor : public ItemVisitor {
private:
    bool mIsHit = false;
public:
    /**
     * Visit the TA and Set the Hit State
     * Accordingly
     * @param ta TA Object
     */
    void VisitTA(TA* ta) override {
        ta->SetHitState();
        mIsHit = true;
    }

    /**
     * Get whether the TA has been Hit
     * @return
     */
    bool GetHit() const {
        return mIsHit;
    }
};

#endif //INC_335PROJECT1_TAHITVISITOR_H
