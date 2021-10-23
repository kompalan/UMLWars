/**
 * @file Inheritance.h
 * @author Ian Byram
 *
 * Class for inheritance UML objects
 */

#ifndef INC_335PROJECT1_INHERITANCE_H
#define INC_335PROJECT1_INHERITANCE_H

#include "UML.h"
#include "ClassUML.h"

/**
 * Class for inheritance UML objects
 */
class Inheritance : public UML {
private:
    /// The base class of the inheritance relationship
    std::shared_ptr<ClassUML> mBase;

    /// The derived class of the inheritance relationship
    std::shared_ptr<ClassUML> mDerived;

    /// If the inheritance relationship is upside down
    bool mDown = false;

protected:
    Inheritance(Game *game, std::shared_ptr<ClassUML> base, std::shared_ptr<ClassUML> derived);

    Inheritance(Game *game, std::shared_ptr<ClassUML> base, std::shared_ptr<ClassUML> derived, bool down);
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

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void CalculateDimensions(std::shared_ptr<wxGraphicsContext> graphics) override;

};

#endif //INC_335PROJECT1_INHERITANCE_H
