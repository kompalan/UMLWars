/**
 * @file BadClassUML.h
 * @author Ian Byram
 *
 * Class for bad UML class objects
 */

#ifndef INC_335PROJECT1_BADCLASSUML_H
#define INC_335PROJECT1_BADCLASSUML_H

#include "UML.h"

/**
 * Class for bad UML class objects
 */
class BadClassUML : public UML {
private:
    /// The reason the class UML is bad
    std::wstring mReason;

public:
    /// Default constructor (disabled)
    BadClassUML() = delete;
    
    /// Copy constructor (disabled)
    BadClassUML(const BadClassUML &) = delete;
    
    /// Assignment operator
    void operator=(const BadClassUML &) = delete;
    
    
    BadClassUML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
            std::vector<std::shared_ptr<UMLOperation>> operations, std::wstring reason);
};

#endif //INC_335PROJECT1_BADCLASSUML_H
