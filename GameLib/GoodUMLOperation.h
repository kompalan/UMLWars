/**
 * @file GoodUMLOperation.h
 * @author Ian Byram
 *
 * Class for a good UML class operation
 */

#ifndef INC_335PROJECT1_GOODUMLOPERATION_H
#define INC_335PROJECT1_GOODUMLOPERATION_H

#include "UMLOperation.h"

/**
 * Class for a good UML class operation
 */
class GoodUMLOperation : public UMLOperation {
private:

public:
    /// Default constructor (disabled)
    GoodUMLOperation() = delete;

    /// Copy constructor (disabled)
    GoodUMLOperation(const GoodUMLOperation &) = delete;

    /// Assignment operator
    void operator=(const GoodUMLOperation &) = delete;

    GoodUMLOperation(std::wstring operation);

};

#endif //INC_335PROJECT1_GOODUMLOPERATION_H
