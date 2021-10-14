/**
 * @file BadUMLAttribute.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "BadUMLAttribute.h"

using namespace std;

/**
 * Constructor
 * @param attribute a UML class attribute
 * @param reason the reason the UML class attribute is bad
 */
BadUMLAttribute::BadUMLAttribute(std::wstring attribute, std::wstring reason) : UMLAttribute(attribute)
{
    mReason = reason;
}