/**
 * @file GoodClassUML.h
 * @author Ian Byram
 *
 * Class for good UML class objects
 */

#ifndef INC_335PROJECT1_GOODCLASSUML_H
#define INC_335PROJECT1_GOODCLASSUML_H

#include "ClassUML.h"

/**
 * Class for good UML class objects
 */
class GoodClassUML : public ClassUML {
private:

public:
    /// Default constructor (disabled)
    GoodClassUML() = delete;
    
    /// Copy constructor (disabled)
    GoodClassUML(const GoodClassUML &) = delete;
    
    /// Assignment operator
    void operator=(const GoodClassUML &) = delete;

    GoodClassUML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
            std::vector<std::shared_ptr<UMLOperation>> operations);

    /**
     * Accept the Visitor and Call VisitGoodUML on the visitor object
     * @param visitor ItemVisitor object
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitGoodUML(this); }

};

#endif //INC_335PROJECT1_GOODCLASSUML_H
