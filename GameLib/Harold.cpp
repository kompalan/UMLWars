/**
 * @file Harold.cpp
 * @author Anurag
 */

#include "Harold.h"

/// Harold Filename
const std::wstring HaroldImageName = L"images/harold.png";

/**
 * Constructor
 * @param game Game object for forward reference
 */
Harold::Harold(Game* game) : Item(game, HaroldImageName)
{
}
