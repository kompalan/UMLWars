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

/**
 * Class for Visitors of BadUML
 */
class BadUMLVisitor : public ItemVisitor {
private:
    /// Boolean determining whether a given UML is bad or not
    bool mIsBad = false;
public:
    /**
     * Return Whether the Last UMLVisited was good or bad
     * @return Boolean where false is Good UML and true is Bad UML
     */
    bool IsBad() {return mIsBad;}

    /**
     * Visit a good UML and set mIsBad to false.
     * @param UML GoodClassUML Object
     */
    void VisitGoodUML(GoodClassUML* UML) override {mIsBad = false;}

    /**
     * Visit a bad UML and set mIsBad to true;
     * @param UML BadClassUML object
     */
    void VisitBadUML(BadClassUML* UML) override {mIsBad = true;}

    /**
     * Visit a good inheritance uml object and set
     * mIsBad to false
     * @param UML GoodInheritance Object
     */
    void VisitGoodInheritance(GoodInheritance* UML) override {mIsBad = false;}

    /**
     * Visit a bad inheritance uml object and set
     * mIsBad to false
     * @param UML BadInheritance Object
     */
    void VisitBadInheritance(BadInheritance* UML) override {mIsBad = true;}
};

#endif //INC_335PROJECT1_BADUMLVISITOR_H
