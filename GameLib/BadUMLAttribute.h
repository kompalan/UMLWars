/**
 * @file BadUMLAttribute.h
 * @author Ian Byram
 *
 * Class for a bad UML class attribute
 */

#ifndef INC_335PROJECT1_BADUMLATTRIBUTE_H
#define INC_335PROJECT1_BADUMLATTRIBUTE_H

#include "UMLAttribute.h"

/**
 * Class for a bad UML class attribute
 */
class BadUMLAttribute : public UMLAttribute {
private:
    std::wstring mReason;

public:
    /// Default constructor (disabled)
    BadUMLAttribute() = delete;

    /// Copy constructor (disabled)
    BadUMLAttribute(const BadUMLAttribute &) = delete;

    /// Assignment operator
    void operator=(const BadUMLAttribute &) = delete;

    /**
     * Constructor
     * @param attribute the attribute of the UML class
     * @param reason the reason the UML class attribute is bad
     */
    BadUMLAttribute(std::wstring attribute, std::wstring reason) : UMLAttribute(attribute) { mReason = reason; }
};

#endif //INC_335PROJECT1_BADUMLATTRIBUTE_H
