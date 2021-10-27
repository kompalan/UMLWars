/**
 * @file Scoreboard.cpp
 * @author Joe Getzen
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Vector.h"



/// Position of the Scoreboard
const cse335::Vector Position = cse335::Vector(0, 100);

/**
 * Constructor for the scoreboard
 */
Scoreboard::Scoreboard()
{
}
/**
 * Draws the scoreboard on screen with GraphicsContext
 * @param graphics Context
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid, hit;

    graphics->PushState();

    /// Font of the categories
    wxFont smallFont(wxSize(0, 40),
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    /// Font of the Scoreboard
    wxFont bigFont(wxSize(0, 85),
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    /// Color of the Scoreboard
    wxColour cyanBlue = wxColour(0,200,200);

    //Categories
    graphics->SetFont(smallFont, cyanBlue);

    graphics->GetTextExtent(L"Unfair", &wid, &hit);
    graphics->DrawText(L"Unfair", 300 - wid/2, 150 - hit/2);

    graphics->GetTextExtent(L"Missed", &wid, &hit);
    graphics->DrawText(L"Missed", 0 - wid/2, 150 - hit/2);

    graphics->GetTextExtent(L"Correct", &wid, &hit);
    graphics->DrawText(L"Correct", -300 - wid/2, 150 - hit/2);
    //Scores
    graphics->SetFont(bigFont, cyanBlue);

    graphics->GetTextExtent(std::to_string(mUnfair), &wid, &hit);
    graphics->DrawText(std::to_string(mUnfair), 300 - wid/2, 100 - hit/2);

    graphics->GetTextExtent(std::to_string(mMissed), &wid, &hit);
    graphics->DrawText(std::to_string(mMissed), 0 - wid/2, 100 - hit/2);

    graphics->GetTextExtent(std::to_string(mCorrect), &wid, &hit);
    graphics->DrawText(std::to_string(mCorrect), -300 - wid/2, 100 - hit/2);
    graphics->PopState();
}