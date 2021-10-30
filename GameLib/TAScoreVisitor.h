/**
 * @file TAScoreVisitor.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_TASCOREVISITOR_H
#define INC_335PROJECT1_TASCOREVISITOR_H

#include "ItemVisitor.h"
#include "TA.h"

/**
 * Visitor to Increment the Score of the TA
 */
class TAScoreVisitor : public ItemVisitor{
private:

public:
    /**
     * Visit the given TA object and increment the score count
     * @param ta TA object
     */
    void VisitTA(TA* ta) override {  ta->IncrementScoreCount(); }
};

#endif //INC_335PROJECT1_TASCOREVISITOR_H
