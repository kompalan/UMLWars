/**
 * @file GoodInheritance.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "GoodInheritance.h"

using namespace std;

GoodInheritance::GoodInheritance(Game *game, std::shared_ptr<UML> base, std::shared_ptr<UML> derived)
            : Inheritance(game, base, derived)
{

}