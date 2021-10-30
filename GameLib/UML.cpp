/**
 * @file UML.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "UML.h"
#include "Game.h"

using namespace std;

/// Initial x speed of UML
const double InitialSpeedX = 0;

/// Initial y speed of UML
const double InitialSpeedY = 0;

/**
 * Constructor
 * @param game the game the UML is a part of
 */
UML::UML(Game *game) : Item(game)
{

}

/**
 * Updates the position of the UML object
 * @param elapsed the time since the last update
 */
void UML::Update(double elapsed)
{
    if (mIsHit)
    {
        mTimeHit += elapsed;
        SetVelocity(InitialSpeedX,InitialSpeedY);
    }

    double newX = GetX() + GetVelocity().X() * elapsed;
    double newY = GetY() + GetVelocity().Y() * elapsed;
    SetLocation(newX, newY);
}

bool UML::CheckOnScreen()
{
    double gameWidth = GetGame()->GetWidth();
    double gameHeight = GetGame()->GetHeight();

    if (GetX() < -gameWidth/2 - mWidth/2 || GetX() > gameWidth/2 + mWidth/2 || GetY() > gameHeight + mHeight/2 || GetY() < 0)
    {
        return false;
    }
    return true;
}