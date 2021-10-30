/**
 * @file GoodInheritance.h
 * @author Ian Byram
 *
 * Class for good UML inheritance objects
 */

#ifndef INC_335PROJECT1_GOODINHERITANCE_H
#define INC_335PROJECT1_GOODINHERITANCE_H

#include "Inheritance.h"

/**
 * Class for good UML inheritance objects
 */
class GoodInheritance : public Inheritance {
private:

public:
    /// Default constructor (disabled)
    GoodInheritance() = delete;
    
    /// Copy constructor (disabled)
    GoodInheritance(const GoodInheritance &) = delete;
    
    /// Assignment operator
    void operator=(const GoodInheritance &) = delete;

    GoodInheritance(Game *game, std::shared_ptr<ClassUML> base, std::shared_ptr<ClassUML> derived);

    /**
     * Accept the visitor and call VisitGoodInheritance on the
     * visitor object
     * @param visitor ItemVisitor object
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitGoodInheritance(this); }
};

#endif //INC_335PROJECT1_GOODINHERITANCE_H
