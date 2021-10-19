/**
 * @file Scoreboard.cpp
 * @author Joe Getzen
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Vector.h"

/// Font of the categories
const wxFont smallFont(wxSize(0, 20),
        wxFONTFAMILY_ROMAN,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_BOLD);

/// Font of the Scoreboard
const wxFont bigFont(wxSize(0, 60),
        wxFONTFAMILY_MODERN,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_BOLD);

/// Color of the Scoreboard
const wxColour burntOrange = wxColour(255,140,0);

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