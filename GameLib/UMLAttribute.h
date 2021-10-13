/**
 * @file UMLAttribute.h
 * @author Ian Byram
 *
 * Base class for any UML attributes
 */

#ifndef INC_335PROJECT1_UMLATTRIBUTE_H
#define INC_335PROJECT1_UMLATTRIBUTE_H

#include "UMLClassItem.h"

/**
 * Base class for any UML attributes
 */
class UMLAttribute : public UMLClassItem {
private:

protected:
    /**
     * Constructor
     * @param attribute the attribute of the UML class
     */
    UMLAttribute(std::wstring attribute) : UMLClassItem(attribute) {}
public:
    /// Default constructor (disabled)
    UMLAttribute() = delete;

    /// Copy constructor (disabled)
    UMLAttribute(const UMLAttribute &) = delete;

    /// Assignment operator
    void operator=(const UMLAttribute &) = delete;


};

#endif //INC_335PROJECT1_UMLATTRIBUTE_H
