/**
 * @file BadUMLOperation.h
 * @author Ian Byram
 *
 * Class for a bad UML class operation
 */

#ifndef INC_335PROJECT1_BADUMLOPERATION_H
#define INC_335PROJECT1_BADUMLOPERATION_H

#include "UMLOperation.h"

/**
 * Class for a bad UML class operation
 */
class BadUMLOperation : public UMLOperation {
private:
    /// The reason the UML class operation is bad
    std::wstring mReason;

public:
    /// Default constructor (disabled)
    BadUMLOperation() = delete;

    /// Copy constructor (disabled)
    BadUMLOperation(const BadUMLOperation &) = delete;

    /// Assignment operator
    void operator=(const BadUMLOperation &) = delete;

    BadUMLOperation(std::wstring operation, std::wstring reason);

    /**
     * Getter for the bad class operation reason
     * @return the bad class operation reason
     */
    std::wstring GetReason() { return mReason; }
};

#endif //INC_335PROJECT1_BADUMLOPERATION_H
