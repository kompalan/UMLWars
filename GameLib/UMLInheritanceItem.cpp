/**
 * @file UMLInheritanceItem.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "UMLInheritanceItem.h"

using namespace std;

/**
 * Constructor
 * @param base base class of the inheritance relationship
 * @param derived derived class of the inheritance relationship
 */
UMLInheritanceItem::UMLInheritanceItem(std::wstring base, std::wstring derived)
{
    mBase = base;
    mDerived = derived;
}