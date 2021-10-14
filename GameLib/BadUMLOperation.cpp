/**
 * @file BadUMLOperation.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "BadUMLOperation.h"

using namespace std;

/**
 * Constructor
 * @param operation a UML class operation
 * @param reason the reason the UML class operation is bad
 */
BadUMLOperation::BadUMLOperation(std::wstring operation, std::wstring reason) : UMLOperation(operation)
{
    mReason = reason;
}

