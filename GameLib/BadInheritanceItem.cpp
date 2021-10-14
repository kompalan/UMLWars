/**
 * @file BadInheritanceItem.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "BadInheritanceItem.h"

using namespace std;

/**
 * Constructor
 * @param base the base class of the inheritance relationship
 * @param derived the derived class of the inheritance relationship
 * @param reason the reason the inheritance is bad
 * @param down if the inheritance is pointed down
 */
BadInheritanceItem::BadInheritanceItem(std::wstring base, std::wstring derived, std::wstring reason, bool down) :
                UMLInheritanceItem(base, derived)
{
    mReason = reason;
    mDown = down;
}