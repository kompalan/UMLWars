/**
 * @file GoodUMLName.h
 * @author Ian Byram
 *
 * Class for a good UML class name
 */

#ifndef INC_335PROJECT1_GOODUMLNAME_H
#define INC_335PROJECT1_GOODUMLNAME_H

#include "UMLName.h"

/**
 * Class for a good UML class name
 */
class GoodUMLName : public UMLName {
private:

public:
    /// Default constructor (disabled)
    GoodUMLName() = delete;

    /// Copy constructor (disabled)
    GoodUMLName(const GoodUMLName &) = delete;

    /// Assignment operator
    void operator=(const GoodUMLName &) = delete;

    GoodUMLName(std::wstring name);
};

#endif //INC_335PROJECT1_GOODUMLNAME_H
