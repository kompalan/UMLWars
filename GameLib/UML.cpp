/**
 * @file UML.cpp
 * @author Kristian Rica
 */

#include "pch.h"
#include "UML.h"

using namespace std;

/**
 * Constructor
 * @param game the game the UML object is a part of
 * @param name the name of the UML object
 * @param attributes the attributes of the UML object
 * @param operations the operations of the UML object
 */
UML::UML(Game *game, std::wstring name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
        std::vector<std::shared_ptr<UMLOperation>> operations) : Item(game)
{
    mName = name;
    mAttributes = attributes;
    mOperations = operations;
}

/**
 * Draw the class UML object on the screen
 * @param graphics wxGraphicsContext object
 */
void UML::Draw(wxGraphicsContext *graphics)
{

}