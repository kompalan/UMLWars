/**
 * @file ClassUML.h
 * @author Kristian Rica
 * @author Ian Byram
 *
 * Class storing basic class UML object and its properties
 */

#pragma once

#ifndef INC_335PROJECT1_CLASSUML_H
#define INC_335PROJECT1_CLASSUML_H

#include "UML.h"
#include "UMLName.h"
#include "UMLAttribute.h"
#include "UMLOperation.h"
#include "Vector.h"

/**
 * Class storing basic class UML object and its properties
 */
class ClassUML : public UML {
private:
    /// Name of UML Item
    std::shared_ptr<UMLName> mName;

    /// The list of attributes of the UML object
    std::vector<std::shared_ptr<UMLAttribute>> mAttributes;

    /// The list of operations of the UML object
    std::vector<std::shared_ptr<UMLOperation>> mOperations;




protected:
    ClassUML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
            std::vector<std::shared_ptr<UMLOperation>> operations);

public:
    /// Default constructor (disabled)
    ClassUML() = delete;

    /// Copy constructor (disabled)
    ClassUML(const ClassUML &) = delete;

    /// Assignment operator
    void operator=(const ClassUML &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void CalculateDimensions(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitClassUML(this); }
};

#endif //INC_335PROJECT1_CLASSUML_H
