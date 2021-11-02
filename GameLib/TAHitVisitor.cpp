/**
 * @file TAHitVisitor.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "TAHitVisitor.h"

/**
 * Visit the TA and Set the Hit State
 * Accordingly
 * @param ta TA Object
 */
void TAHitVisitor::VisitTA(TA* ta) {
    mIsHit = ta->SetHitState();
    mIsSpawned = ta->IsSpawned();
}

/**
 * Get whether the TA has been Hit
 * @return whether the TA is hit
 */
bool TAHitVisitor::GetHit() {

    return mIsHit;
}

/**
 * Get whether the TA is spawned
 * @return whether the TA is spawned
 */
bool TAHitVisitor::GetSpawned()
{
    return mIsSpawned;
}
