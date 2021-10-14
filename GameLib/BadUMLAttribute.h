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
    /// The reason the UML class attribute is bad
    std::wstring mReason;

public:
    /// Default constructor (disabled)
    BadUMLAttribute() = delete;

    /// Copy constructor (disabled)
    BadUMLAttribute(const BadUMLAttribute &) = delete;

    /// Assignment operator
    void operator=(const BadUMLAttribute &) = delete;

    BadUMLAttribute(std::wstring attribute, std::wstring reason);

    /**
     * Getter for the bad class attribute reason
     * @return the bad class attribute reason
     */
    std::wstring GetReason() { return mReason; }
};

#endif //INC_335PROJECT1_BADUMLATTRIBUTE_H
