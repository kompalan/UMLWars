/**
 * @file ItemWithImage.cpp
 * @author Kristian Rica
 */

#include "pch.h"
#include "Game.h"
#include "ItemWithImage.h"

/**
 * Constructor
 * @param game Game object for forward reference
 * @param posX Initial X position of the Item
 * @param posY Initial Y position of the Item
 * @param imageName The image Path
 */
ItemWithImage::ItemWithImage(Game *game, double posX, double posY, const std::wstring imageName) : Item(game, posX, posY)
{
    mImage = std::make_unique<wxImage>(imageName, wxBITMAP_TYPE_ANY);
}