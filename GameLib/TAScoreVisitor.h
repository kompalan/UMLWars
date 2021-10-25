/**
 * @file TAVisitor.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_TASCOREVISITOR_H
#define INC_335PROJECT1_TASCOREVISITOR_H

#include "ItemVisitor.h"
#include "TA.h"

class TAScoreVisitor : public ItemVisitor{
private:

public:
    void VisitTA(TA* ta) override {  ta->IncrementScoreCount(); }
};

#endif //INC_335PROJECT1_TASCOREVISITOR_H
