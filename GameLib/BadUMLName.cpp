/**
 * @file BadUMLName.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "BadUMLName.h"

using namespace std;

/**
 * Constructor
 * @param name a UML class name
 * @param reason the reason the UML class name is bad
 */
BadUMLName::BadUMLName(std::wstring name, std::wstring reason) : UMLName(name)
{
    mReason = reason;
}