/**
 * @file BadClassUML.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "BadClassUML.h"

using namespace std;

/**
 * Constructor
 * @param game the game the bad UML object is a part of
 * @param name the name of the bad UML object
 * @param attributes the attributes of the bad UML object
 * @param operations the operations of the bad UML object
 * @param reason the reason the UML object is bad
 */
BadClassUML::BadClassUML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
        std::vector<std::shared_ptr<UMLOperation>> operations, std::wstring reason) : UML(game, name, attributes, operations)
{
    mReason = reason;
}