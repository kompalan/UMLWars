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
#include "UMLAttribute.h"
#include "UMLOperation.h"

/**
 * Class storing basic UML object and its properties
 */
class UML : public Item {
private:
    /// Name of UML Item
    std::wstring mName;

    /// The list of attributes of the UML object
    std::vector<std::shared_ptr<UMLAttribute>> mAttributes;

    /// The list of operations of the UML object
    std::vector<std::shared_ptr<UMLOperation>> mOperations;

protected:
    UML(Game *game, std::wstring name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
            std::vector<std::shared_ptr<UMLOperation>> operations);
public:
    /// Default constructor (disabled)
    UML() = delete;

    /// Copy constructor (disabled)
    UML(const UML &) = delete;

    /// Assignment operator
    void operator=(const UML &) = delete;

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitUML(this); }

    void Draw(wxGraphicsContext *graphics);
};

#endif //INC_335PROJECT1_UML_H
