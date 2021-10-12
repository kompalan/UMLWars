/**
 * @file Game.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Game.h"
#include "Harold.h"

using namespace std;

/**
 * Constructor
 */
Game::Game()
{
}

/**
 * Draw the View on the Graphics Context using Virtual Pixels
 * @param graphics Graphics Context to Draw on
 * @param width Height of the Window
 * @param height Width of the Window
 */
void Game::OnDraw(wxGraphicsContext *graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(Width);
    auto scaleY = double(height) / double(Height);
    mScale = min(scaleX, scaleY);

    mXOffset = width / 2;
    mYOffset = 0;
    if (height > Height * mScale) {
        mYOffset = (float)((height - Height * mScale) / 2);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE
    for(auto item : mItems)
    {
        item->Draw(graphics);
    }

    graphics->PopState();
}

/**
 * Update function of the Game: Handles Animations
 * @param elapsed Time Elapsed since Last OnDraw
 */
void Game::Update(double elapsed)
{
    for(auto item : mItems)
    {
        item->Update(elapsed);
    }
}

/**
 * Adds an item to the list
 * @param item Item to add to the list
 */
void Game::AddItem(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}
