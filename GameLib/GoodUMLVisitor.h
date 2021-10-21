/**
 * @file GoodUMLVisitor.h
 * @author Joe Getzen
 *
 * Good UML visitor class derived from ItemVisitor
 */

#ifndef INC_335PROJECT1_GOODUMLVISITOR_H
#define INC_335PROJECT1_GOODUMLVISITOR_H

#include "ItemVisitor.h"
#include "Item.h"
#include "GoodClassUML.h"
#include "BadClassUML.h"
#include "GoodInheritance.h"
#include "BadInheritance.h"

class GoodUMLVisitor : public ItemVisitor {
private:
    bool mIsGood=false;
public:
    bool IsGood() {return mIsGood;}
    void VisitGoodUML(GoodClassUML* UML) override {mIsGood=true;}
    void VisitBadUML(BadClassUML* UML) override {mIsGood=false;}
    void VisitGoodInheritance(GoodInheritance* UML) override {mIsGood=true;}
    void VisitBadInheritance(BadInheritance* UML) override {mIsGood=false;}
};

#endif //INC_335PROJECT1_GOODUMLVISITOR_H