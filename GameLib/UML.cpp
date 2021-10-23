/**
 * @file UML.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "UML.h"

using namespace std;

/**
 * Constructor
 * @param game the game the UML is a part of
 */
UML::UML(Game *game) : Item(game)
{

}

/**
 * Updates the position of the UML object
 * @param elapsed the time since the last update
 */
void UML::Update(double elapsed)
{
    double newX = GetX() + GetVelocity().X() * elapsed;
    double newY = GetY() + GetVelocity().Y() * elapsed;
    SetLocation(newX, newY);
}