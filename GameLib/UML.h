/**
 * @file UML.h
 * @author Kristian Rica
 *
 *
 */

#pragma once

#ifndef INC_335PROJECT1_UML_H
#define INC_335PROJECT1_UML_H

#include "Item.h"

/**
 * Class storing basic UML object and its properties
 */

class UML : public Item {
private:
    /// Name of UML Item
    std::string mItemName = "";

    /// X coordinate of UML Item
    double mPosX = 0;

    /// Y coordinate of UML Item
    double mPosY = 0;

public:

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitUML(this); }
};

#endif //INC_335PROJECT1_UML_H
