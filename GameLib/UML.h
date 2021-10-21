/**
 * @file UML.h
 * @author Kristian Rica
 * @author Ian Byram
 *
 */

#pragma once

#ifndef INC_335PROJECT1_UML_H
#define INC_335PROJECT1_UML_H

#include "Item.h"
#include "UMLName.h"
#include "UMLAttribute.h"
#include "UMLOperation.h"
#include "Vector.h"

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

    /// The width of the UML object in pixels
    double mWidth = 0;

    /// The height of the UML object in pixels
    double mHeight = 0;

    /// If the appropriate dimensions of the UML object have been calculated
    bool mDimensionCalculated = false;

    /// If the UML is a part of an inheritance relationship
    bool mPartOfInheritance = false;

protected:
    UML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
            std::vector<std::shared_ptr<UMLOperation>> operations);

    UML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
            std::vector<std::shared_ptr<UMLOperation>> operations, bool partOfInheritance);
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
    void Update(double elapsed);
    void CalculateDimensions(std::shared_ptr<wxGraphicsContext> graphics);

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
