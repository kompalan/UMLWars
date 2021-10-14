/**
 * @file GoodUMLAttribute.h
 * @author Ian Byram
 *
 * Class for a good UML class attribute
 */

#ifndef INC_335PROJECT1_GOODUMLATTRIBUTE_H
#define INC_335PROJECT1_GOODUMLATTRIBUTE_H

#include "UMLAttribute.h"

/**
 * Class for a good UML class attribute
 */
class GoodUMLAttribute : public UMLAttribute {
private:

public:
    /// Default constructor (disabled)
    GoodUMLAttribute() = delete;

    /// Copy constructor (disabled)
    GoodUMLAttribute(const GoodUMLAttribute &) = delete;

    /// Assignment operator
    void operator=(const GoodUMLAttribute &) = delete;

    GoodUMLAttribute(std::wstring attribute);
};

#endif //INC_335PROJECT1_GOODUMLATTRIBUTE_H
