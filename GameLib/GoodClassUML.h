/**
 * @file GoodClassUML.h
 * @author Ian Byram
 *
 * Class for good UML class objects
 */

#ifndef INC_335PROJECT1_GOODCLASSUML_H
#define INC_335PROJECT1_GOODCLASSUML_H

#include "UML.h"

/**
 * Class for good UML class objects
 */
class GoodClassUML : public UML {
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
};

#endif //INC_335PROJECT1_GOODCLASSUML_H
