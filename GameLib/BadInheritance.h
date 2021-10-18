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

    BadInheritance(Game *game, std::shared_ptr<UML> base, std::shared_ptr<UML> derived, std::wstring reason, bool down);

};

#endif //INC_335PROJECT1_BADINHERITANCE_H
