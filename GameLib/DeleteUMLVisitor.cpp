/**
 * @file DeleteUMLVisitor.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "DeleteUMLVisitor.h"
#include "BadClassUML.h"
#include "GoodClassUML.h"
#include "BadInheritance.h"
#include "GoodInheritance.h"

const double TimeBeforeDelete = 1;

void DeleteUMLVisitor::VisitBadUML(BadClassUML* uml)
{
    if (uml->GetTimeHit() >= TimeBeforeDelete)
    {
        mToDelete.push_back(uml);
    }
}

void DeleteUMLVisitor::VisitGoodUML(GoodClassUML* uml)
{
    if (uml->GetTimeHit() >= TimeBeforeDelete)
    {
        mToDelete.push_back(uml);
    }
}

void DeleteUMLVisitor::VisitBadInheritance(BadInheritance* uml)
{
    if (uml->GetTimeHit() >= TimeBeforeDelete)
    {
        mToDelete.push_back(uml);
    }
}

void DeleteUMLVisitor::VisitGoodInheritance(GoodInheritance* uml)
{
    if (uml->GetTimeHit() >= TimeBeforeDelete)
    {
        mToDelete.push_back(uml);
    }
}
