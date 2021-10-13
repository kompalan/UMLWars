/**
 * @file BadUMLName.h
 * @author Ian Byram
 *
 * Class for a bad UML class name
 */

#ifndef INC_335PROJECT1_BADUMLNAME_H
#define INC_335PROJECT1_BADUMLNAME_H

#include "UMLName.h"

/**
 * Class for a bad UML class name
 */
class BadUMLName : public UMLName {
private:
    /// The reason the UML class name is bad
    std::wstring mReason;

public:
    /// Default constructor (disabled)
    BadUMLName() = delete;

    /// Copy constructor (disabled)
    BadUMLName(const BadUMLName &) = delete;

    /// Assignment operator
    void operator=(const BadUMLName &) = delete;

    /**
     * Constructor
     * @param name the name of the UML class
     * @param reason the reason the UML class name is bad
     */
    BadUMLName(std::wstring name, std::wstring reason) : UMLName(name) { mReason = reason; }

    /**
     * Getter for the bad class name reason
     * @return the bad class name reason
     */
     std::wstring GetReason() { return mReason; }
};

#endif //INC_335PROJECT1_BADUMLNAME_H
