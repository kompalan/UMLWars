/**
 * @file Scoreboard.cpp
 * @author Joe Getzen
 */

#include "pch.h"
#include "Scoreboard.h"
/**
 * Constructor for the scoreboard
 * @param game provided for reference
 */
Scoreboard::Scoreboard(Game* game) : Item(game, 0, 100 )
{
}
/**
 * Draws the scoreboard on screen with GraphicsContext
 * @param graphics Context
 */
void Scoreboard::Draw(wxGraphicsContext* graphics)
{
    mGraphics = graphics;
    double wid, hit;

    graphics->PushState();
    //Categories
    graphics->SetFont(smallFont, burntOrange);

    graphics->GetTextExtent(L"Unfair", &wid, &hit);
    graphics->DrawText(L"Unfair", 300 - wid/2, 150 - hit/2);

    graphics->GetTextExtent(L"Missed", &wid, &hit);
    graphics->DrawText(L"Missed", 0 - wid/2, 150 - hit/2);

    graphics->GetTextExtent(L"Correct", &wid, &hit);
    graphics->DrawText(L"Correct", -300 - wid/2, 150 - hit/2);
    //Scores
    graphics->SetFont(bigFont, burntOrange);

    graphics->GetTextExtent(std::to_string(mUnfair), &wid, &hit);
    graphics->DrawText(std::to_string(mUnfair), 300 - wid/2, 100 - hit/2);

    graphics->GetTextExtent(std::to_string(mMissed), &wid, &hit);
    graphics->DrawText(std::to_string(mMissed), 0 - wid/2, 100 - hit/2);

    graphics->GetTextExtent(std::to_string(mCorrect), &wid, &hit);
    graphics->DrawText(std::to_string(mCorrect), -300 - wid/2, 100 - hit/2);
    graphics->PopState();
}
/**
 * General update function to redraw scores
 */
void Scoreboard::Update(double elapsed)
{
    if (!mGraphics)
    {
        double wid, hit;
        mGraphics->SetFont(smallFont, burntOrange);

        mGraphics->GetTextExtent(std::to_string(mUnfair), &wid, &hit);
        mGraphics->DrawText(std::to_string(mUnfair), 300 - wid/2, 100 - hit/2);

        mGraphics->GetTextExtent(std::to_string(mMissed), &wid, &hit);
        mGraphics->DrawText(std::to_string(mMissed), 0 - wid/2, 100 - hit/2);

        mGraphics->GetTextExtent(std::to_string(mCorrect), &wid, &hit);
        mGraphics->DrawText(std::to_string(mCorrect), -300 - wid/2, 100 - hit/2);
    }
}