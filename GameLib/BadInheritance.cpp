/**
 * @file BadInheritance.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "BadInheritance.h"

using namespace std;

/**
 * Constructor
 * @param game the game the bad inheritance UML is a part of
 * @param base the base class of the inheritance UML
 * @param derived the derived class of the inheritance UML
 * @param reason the reason the inheritance is bad
 * @param down if the inheritance is upside down
 */
BadInheritance::BadInheritance(Game *game, std::shared_ptr<ClassUML> base, std::shared_ptr<ClassUML> derived,
        std::wstring reason, bool down) : Inheritance(game, base, derived, down)
{
    mReason = reason;
}