/**
 * @file DeleteUMLVisitor.h
 * @author Ian Byram
 *
 * Visitor class to keep track of UML that should be deleted
 */

#ifndef INC_335PROJECT1_DELETEUMLVISITOR_H
#define INC_335PROJECT1_DELETEUMLVISITOR_H

#include "ItemVisitor.h"
#include "UML.h"

/**
 * Visitor class to keep track of UML that should be deleted
 */
class DeleteUMLVisitor : public ItemVisitor {
private:
    std::vector<UML*> mToDelete;
public:

    /**
     * Get the vector of UML to delete
     * @return the vector of UML to delete
     */
    std::vector<UML*> GetToDelete() { return mToDelete; }

    void VisitBadUML(BadClassUML* uml);
    void VisitGoodUML(GoodClassUML* uml);
    void VisitBadInheritance(BadInheritance* uml);
    void VisitGoodInheritance(GoodInheritance* uml);
};

#endif //INC_335PROJECT1_DELETEUMLVISITOR_H
