/**
 * @file UMLOperation.h
 * @author Ian Byram
 *
 * Base class for any UML class operation
 */

#ifndef INC_335PROJECT1_UMLOPERATION_H
#define INC_335PROJECT1_UMLOPERATION_H

#include "UMLClassItem.h"

/**
 * Base class for any UML class operation
 */
class UMLOperation : public UMLClassItem {
private:

protected:
    UMLOperation(std::wstring operation);
public:
    /// Default constructor (disabled)
    UMLOperation() = delete;

    /// Copy constructor (disabled)
    UMLOperation(const UMLOperation &) = delete;

    /// Assignment operator
    void operator=(const UMLOperation &) = delete;


};

#endif //INC_335PROJECT1_UMLOPERATION_H
