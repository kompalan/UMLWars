/**
 * @file Inheritance.h
 * @author Ian Byram
 *
 * Class for inheritance UML objects
 */

#ifndef INC_335PROJECT1_INHERITANCE_H
#define INC_335PROJECT1_INHERITANCE_H

#include "Item.h"
#include "UML.h"

/**
 * Class for inheritance UML objects
 */
class Inheritance : public Item {
private:
    /// The base class of the inheritance relationship
    std::shared_ptr<UML> mBase;

    /// The derived class of the inheritance relationship
    std::shared_ptr<UML> mDerived;

protected:
    Inheritance(Game *game, std::shared_ptr<UML> base, std::shared_ptr<UML> derived);
public:
    /// Default constructor (disabled)
    Inheritance() = delete;

    /// Copy constructor (disabled)
    Inheritance(const Inheritance &) = delete;

    /// Assignment operator
    void operator=(const Inheritance &) = delete;

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitInheritance(this); }

    void Draw(wxGraphicsContext *graphics);
};

#endif //INC_335PROJECT1_INHERITANCE_H
