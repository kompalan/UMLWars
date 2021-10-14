/**
 * @file GoodInheritanceItem.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "GoodInheritanceItem.h"

using namespace std;

/**
 * Constructor
 * @param base the base class of the relationship
 * @param derived the derived class of the relationship
 */
GoodInheritanceItem::GoodInheritanceItem(std::wstring base, std::wstring derived) : UMLInheritanceItem(base, derived)
{

}
