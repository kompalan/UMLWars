/**
 * @file UMLHitVisitor.h
 * @author Ian Byram
 *
 * Visitor class for UML that have been hit
 */

#ifndef INC_335PROJECT1_UMLHITVISITOR_H
#define INC_335PROJECT1_UMLHITVISITOR_H

#include "ItemVisitor.h"
#include "BadClassUML.h"
#include "GoodClassUML.h"
#include "GoodInheritance.h"
#include "BadInheritance.h"

/**
 * Visitor class for UML that have been hit
 */
class UMLHitVisitor : public ItemVisitor {
private:

public:
    void VisitBadUML(BadClassUML* uml) override { uml->SetIsHit(true); }
    void VisitGoodUML(GoodClassUML* uml) override { uml->SetIsHit(true); }
    void VisitBadInheritance(BadInheritance* uml) override { uml->SetIsHit(true); }
    void VisitGoodInheritance(GoodInheritance* uml) override { uml->SetIsHit(true); }
};

#endif //INC_335PROJECT1_UMLHITVISITOR_H
