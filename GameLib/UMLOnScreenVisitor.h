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
    /// Boolean representing whether the UML is on the screen
    bool mIsOnScreen = true;

public:
    /**
     * Returns whether the Last visited UML is on screen
     * @return True if UML is on screen otherwise false
     */
    bool IsOnScreen() { return mIsOnScreen; }

    /**
     * Visit a BadClassUML object and set mIsOnScreen to a boolean
     * indicating whether the given uml is on the screen
     * @param uml BadClassUML object
     */
    void VisitBadUML(BadClassUML* uml) { mIsOnScreen = uml->CheckOnScreen(); }

    /**
     * Visit a GoodClassUML object and set mIsOnScreen to a boolean
     * indicating whether the given uml is on the screen
     * @param uml BadClassUML object
     */
    void VisitGoodUML(GoodClassUML* uml) { mIsOnScreen = uml->CheckOnScreen(); }

    /**
     * Visit a BadInheritanceUML object and set mIsOnScreen to a boolean
     * indicating whether the given uml is on the screen
     * @param uml BadClassUML object
     */
    void VisitBadInheritance(BadInheritance* uml) { mIsOnScreen = uml->CheckOnScreen(); }

    /**
     * Visit a GoodInheritanceUML object and set mIsOnScreen to a boolean
     * indicating whether the given uml is on the screen
     * @param uml BadClassUML object
     */
    void VisitGoodInheritance(GoodInheritance* uml) { mIsOnScreen = uml->CheckOnScreen(); }

};

#endif //INC_335PROJECT1_UMLONSCREENVISITOR_H
