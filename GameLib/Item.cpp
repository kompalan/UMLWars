/**
 * @file Item.cpp
 * @author Anurag
 */

#include "pch.h"
#include "Item.h"

/**
 * Constructor
 * @param game Game object for forward reference
 * @param posX Initial X position of the Item
 * @param posY Initial Y position of the Item
 */
Item::Item(Game* game, double posX, double posY) : mGame(game)
{
    mX = posX;
    mY = posY;
}

/**
 * Constructor for items without x and y positions
 * @param game Game object for forward reference
 */
Item::Item(Game* game) : mGame(game)
{

}

/**
 * Returns the X position of the item
 * @return X position
 */
double Item::GetX() const
{
    return mX;
}

/**
 * Returns the Y position of the item
 * @return Y position
 */
double Item::GetY() const
{
    return mY;
}
