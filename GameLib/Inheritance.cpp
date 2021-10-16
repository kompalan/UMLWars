/**
 * @file Inheritance.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "Inheritance.h"

using namespace std;

/**
 * Constructor
 * @param game the game the inheritance UML is a part of
 * @param base the base class of the inheritance
 * @param derived the derived class of the inheritance
 */
Inheritance::Inheritance(Game* game, std::shared_ptr<UML> base, std::shared_ptr<UML> derived) : Item(game)
{
    mBase = base;
    mDerived = derived;
}

void Inheritance::Draw(wxGraphicsContext *graphics)
{

}