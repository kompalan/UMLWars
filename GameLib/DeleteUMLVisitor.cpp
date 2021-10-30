/**
 * @file DeleteUMLVisitor.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "DeleteUMLVisitor.h"

/// Waiting time before UML is removed from the list
const double TimeBeforeDelete = 1;

/**
 * Check if the UML should be deleted
 * @param uml the UML being checked for deletion
 */
void DeleteUMLVisitor::CheckDeleteUML(UML* uml)
{
    if (uml->GetTimeHit() >= TimeBeforeDelete || !uml->CheckOnScreen())
    {
        mToDelete.push_back(uml);
    }
}
