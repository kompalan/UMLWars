/**
 * @file GoodInheritanceItem.h
 * @author Ian Byram
 *
 * Class for good inheritance relationships
 */

#ifndef INC_335PROJECT1_GOODINHERITANCEITEM_H
#define INC_335PROJECT1_GOODINHERITANCEITEM_H

#include "UMLInheritanceItem.h"

/**
 * Class for good inheritance relationships
 */
class GoodInheritanceItem : public UMLInheritanceItem {
private:

public:
    /// Default constructor (disabled)
    GoodInheritanceItem() = delete;

    /// Copy constructor (disabled)
    GoodInheritanceItem(const GoodInheritanceItem &) = delete;

    /// Assignment operator
    void operator=(const GoodInheritanceItem &) = delete;

    GoodInheritanceItem(std::wstring base, std::wstring derived);
};

#endif //INC_335PROJECT1_GOODINHERITANCEITEM_H
