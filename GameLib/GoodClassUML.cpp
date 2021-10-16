/**
 * @file GoodClassUML.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "GoodClassUML.h"

using namespace std;

/**
 * Constructor
 * @param game the game the UML object is a part of
 * @param name the name of the UML object
 * @param attributes the attributes of the UML object
 * @param operations the operations of the UML object
 */
GoodClassUML::GoodClassUML(Game* game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
        std::vector<std::shared_ptr<UMLOperation>> operations) : UML(game, name, attributes, operations)
{

}