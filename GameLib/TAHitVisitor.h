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

public:
    void VisitTA(TA* ta) override {  ta->SetHitState(); }
};

#endif //INC_335PROJECT1_TAHITVISITOR_H
