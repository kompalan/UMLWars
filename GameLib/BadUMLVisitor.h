/**
 * @file BadUMLVisitor.h
 * @author Kristian Rica
 *
 *
 */

#ifndef INC_335PROJECT1_BADUMLVISITOR_H
#define INC_335PROJECT1_BADUMLVISITOR_H

/**
 * Implements visitor class to count all Bad UML objects
 */

#include "ItemVisitor.h"

class BadUMLVisitor : public ItemVisitor {
private:
    bool mIsGood=false;
    int numBadUML = 0;
public:
    /**
     * Tell that UML visited is bad
     * @return false if UML is bad
     */
    bool IsGood() { return mIsGood; }

    /**
     * Get the number of Bad UMLs
     * @return Number of Bad UMLs
     */
    int getBadUMLnum() { return numBadUML; }

    /**
    * Visit a BadClassUML object
    * @param UML Bad UML we are visiting
    */
    void visitBadUML(BadClassUML* UML)
    {
        numBadUML++;
    }

};

#endif //INC_335PROJECT1_BADUMLVISITOR_H
