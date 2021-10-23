/**
 * @file GoodInheritance.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "GoodInheritance.h"

using namespace std;

/**
 * Constructor
 * @param game the game the inheritance UML is a part of
 * @param base the base class of the inheritance
 * @param derived the derived class of the inheritance
 */
GoodInheritance::GoodInheritance(Game *game, std::shared_ptr<ClassUML> base, std::shared_ptr<ClassUML> derived)
            : Inheritance(game, base, derived)
{

}