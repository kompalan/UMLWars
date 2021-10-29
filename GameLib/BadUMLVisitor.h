/**
 * @file BadUMLVisitor.h
 * @author Joe Getzen
 *
 * Good UML visitor class derived from ItemVisitor
 */

#ifndef INC_335PROJECT1_BADUMLVISITOR_H
#define INC_335PROJECT1_BADUMLVISITOR_H

#include "ItemVisitor.h"
#include "Item.h"
#include "GoodClassUML.h"
#include "BadClassUML.h"
#include "GoodInheritance.h"
#include "BadInheritance.h"

class BadUMLVisitor : public ItemVisitor {
private:
    bool mIsBad = false;
public:
    bool IsBad() {return mIsBad;}
    void VisitGoodUML(GoodClassUML* UML) override {mIsBad = false;}
    void VisitBadUML(BadClassUML* UML) override {mIsBad = true;}
    void VisitGoodInheritance(GoodInheritance* UML) override {mIsBad = false;}
    void VisitBadInheritance(BadInheritance* UML) override {mIsBad = true;}
};

#endif //INC_335PROJECT1_BADUMLVISITOR_H
