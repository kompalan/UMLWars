/**
 * @file UMLOnScreenVisitor.h
 * @author Ian Byram
 *
 * Visitor to check if UML is on-screen
 */

#ifndef INC_335PROJECT1_UMLONSCREENVISITOR_H
#define INC_335PROJECT1_UMLONSCREENVISITOR_H

#include "ItemVisitor.h"
#include "BadClassUML.h"
#include "GoodClassUML.h"
#include "BadInheritance.h"
#include "GoodInheritance.h"

/**
 * Visitor to check if UML is on-screen
 */
class UMLOnScreenVisitor : public ItemVisitor {
private:
    bool mIsOnScreen = true;

public:

    bool IsOnScreen() { return mIsOnScreen; }

    void VisitBadUML(BadClassUML* uml) { mIsOnScreen = uml->CheckOnScreen(); }
    void VisitGoodUML(GoodClassUML* uml) { mIsOnScreen = uml->CheckOnScreen(); }
    void VisitBadInheritance(BadInheritance* uml) { mIsOnScreen = uml->CheckOnScreen(); }
    void VisitGoodInheritance(GoodInheritance* uml) { mIsOnScreen = uml->CheckOnScreen(); }

};

#endif //INC_335PROJECT1_UMLONSCREENVISITOR_H
