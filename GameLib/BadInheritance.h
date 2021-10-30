/**
 * @file BadInheritance.h
 * @author Ian Byram
 *
 * Class for bad UML inheritance objects
 */

#ifndef INC_335PROJECT1_BADINHERITANCE_H
#define INC_335PROJECT1_BADINHERITANCE_H

#include "Inheritance.h"

/**
 * Class for bad UML inheritance objects
 */
class BadInheritance : public Inheritance {
private:
    /// The reason the inheritance relationship is bad
    std::wstring mReason;

public:
    /// Default constructor (disabled)
    BadInheritance() = delete;

    /// Copy constructor (disabled)
    BadInheritance(const BadInheritance &) = delete;

    /// Assignment operator
    void operator=(const BadInheritance &) = delete;

    BadInheritance(Game *game, std::shared_ptr<ClassUML> base, std::shared_ptr<ClassUML> derived, std::wstring reason, bool down);

    /**
     * Accept the ItemVisitor and Call VisitBadInheritance on it
     * @param visitor ItemVisitor Object
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitBadInheritance(this); }

    /**
     * Get the reason the inheritance is bad
     * @return the reason the inheritance is bad
     */
    std::wstring GetReason() { return mReason; }
};

#endif //INC_335PROJECT1_BADINHERITANCE_H
