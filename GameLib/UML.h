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
#include "UMLName.h"
#include "UMLAttribute.h"
#include "UMLOperation.h"

/**
 * Class storing basic UML object and its properties
 */
class UML : public Item {
private:
    /// Name of UML Item
    std::shared_ptr<UMLName> mName;

    /// The list of attributes of the UML object
    std::vector<std::shared_ptr<UMLAttribute>> mAttributes;

    /// The list of operations of the UML object
    std::vector<std::shared_ptr<UMLOperation>> mOperations;

    /// The width of the UML object
    double mWidth = 100;

    /// The height of the UML object
    double mHeight = 100;

protected:
    UML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
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

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Get the width of the UML object in pixels
     * @return the width of the UML object in pixels
     */
    virtual double GetWidth() const override { return mWidth; }

    /**
     * Get the height of the UML object in pixels
     * @return the height of the UML object in pixels
     */
    virtual double GetHeight() const override { return mHeight; }
};

#endif //INC_335PROJECT1_UML_H
