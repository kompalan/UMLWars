/**
 * @file UMLName.h
 * @author Ian Byram
 *
 * Base class for any UML class name
 */

#ifndef INC_335PROJECT1_UMLNAME_H
#define INC_335PROJECT1_UMLNAME_H

#include "UMLClassItem.h"

/**
 * Base class for any UML class name
 */
class UMLName : public UMLClassItem {
private:

protected:
    UMLName(std::wstring name);
public:
    /// Default constructor (disabled)
    UMLName() = delete;

    /// Copy constructor (disabled)
    UMLName(const UMLName &) = delete;

    /// Assignment operator
    void operator=(const UMLName &) = delete;

};

#endif //INC_335PROJECT1_UMLNAME_H
