/**
 * @file BadInheritanceItem.h
 * @author Ian Byram
 *
 * Class for bad inheritance relationships
 */

#ifndef INC_335PROJECT1_BADINHERITANCEITEM_H
#define INC_335PROJECT1_BADINHERITANCEITEM_H

#include "UMLInheritanceItem.h"

/**
 * Class for bad inheritance relationships
 */
class BadInheritanceItem : public UMLInheritanceItem {
private:
    /// Reason why the inheritance relationship is bad
    std::wstring mReason;

    /// If the direction of the inheritance is down
    bool mDown = false;

public:
    /// Default constructor (disabled)
    BadInheritanceItem() = delete;

    /// Copy constructor (disabled)
    BadInheritanceItem(const BadInheritanceItem &) = delete;

    /// Assignment operator
    void operator=(const BadInheritanceItem &) = delete;

    BadInheritanceItem(std::wstring base, std::wstring derived, std::wstring reason, bool down);

    /**
     * Getter for the bad inheritance reason
     * @return the bad inheritance reason
     */
    std::wstring GetReason() { return mReason; }

    /**
     * Getter for if the inheritance is upside down
     * @return if the inheritance is upside down
     */
    bool IsDown() { return mDown; }
};

#endif //INC_335PROJECT1_BADINHERITANCEITEM_H
