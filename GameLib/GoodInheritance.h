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

    GoodInheritance(Game *game, std::shared_ptr<UML> base, std::shared_ptr<UML> derived);
};

#endif //INC_335PROJECT1_GOODINHERITANCE_H
