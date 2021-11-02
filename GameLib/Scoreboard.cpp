/**
 * @file Scoreboard.cpp
 * @author Joe Getzen
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Vector.h"

///Value of Blue and Green in Cyan color
const double CyanValue = 200;

///Pixel size of small font
const double SmallSize = 40;

///Pixel size of large font
const double LargeSize = 85;

///X position of Unfair Score
const double UnfairX = 300;

///X position of Correct Score
const double CorrectX = -300;

///Y Position for all categories
const double CategoriesY = 150;

///Y Position for all scores
const double ScoresY=100;

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

    // Font of the categories
    wxFont smallFont(wxSize(0, SmallSize),
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    // Font of the Scoreboard
    wxFont bigFont(wxSize(0, LargeSize),
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    // Color of the Scoreboard
    wxColour cyanBlue = wxColour(0,CyanValue,CyanValue);

    //Categories
    graphics->SetFont(smallFont, cyanBlue);

    graphics->GetTextExtent(L"Unfair", &wid, &hit);
    graphics->DrawText(L"Unfair", UnfairX - wid/2, CategoriesY - hit/2);

    graphics->GetTextExtent(L"Missed", &wid, &hit);
    graphics->DrawText(L"Missed", 0 - wid/2, CategoriesY - hit/2);

    graphics->GetTextExtent(L"Correct", &wid, &hit);
    graphics->DrawText(L"Correct", CorrectX - wid/2, CategoriesY - hit/2);

    //Scores
    graphics->SetFont(bigFont, cyanBlue);

    graphics->GetTextExtent(std::to_string(mUnfair), &wid, &hit);
    graphics->DrawText(std::to_string(mUnfair), UnfairX - wid/2, ScoresY - hit/2);

    graphics->GetTextExtent(std::to_string(mMissed), &wid, &hit);
    graphics->DrawText(std::to_string(mMissed), 0 - wid/2, ScoresY - hit/2);

    graphics->GetTextExtent(std::to_string(mCorrect), &wid, &hit);
    graphics->DrawText(std::to_string(mCorrect), CorrectX - wid/2, ScoresY - hit/2);
    graphics->PopState();
}