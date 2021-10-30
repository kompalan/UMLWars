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
}

/**
 * Get whether the TA has been Hit
 * @return
 */
bool TAHitVisitor::GetHit() {
    return mIsHit;
}