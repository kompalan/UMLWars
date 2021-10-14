/**
 * @file Scoreboard.cpp
 * @author Joe Getzen
 */

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
    mGraphics->SetBrush(*wxWHITE_BRUSH);
    mGraphics->SetPen(*wxTRANSPARENT_PEN);

    //Categories
    wxFont smallFont(wxSize(0, 20),
            wxFONTFAMILY_ROMAN,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(smallFont, wxColour(255,140,0));

    graphics->GetTextExtent(L"Unfair", &wid, &hit);
    graphics->DrawText(L"Unfair", 300 - wid/2, 150 - hit/2);

    graphics->GetTextExtent(L"Missed", &wid, &hit);
    graphics->DrawText(L"Missed", 0 - wid/2, 150 - hit/2);

    graphics->GetTextExtent(L"Correct", &wid, &hit);
    graphics->DrawText(L"Correct", -300 - wid/2, 150 - hit/2);
    //Scores
    wxFont bigFont(wxSize(0, 60),
            wxFONTFAMILY_MODERN,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(bigFont, wxColour(255,140,0));
    //Backdrop
    mGraphics->DrawRectangle(-335,70,70,50);
    mGraphics->DrawRectangle(-35,70,70,50);
    mGraphics->DrawRectangle(265,70,70,50);

    graphics->GetTextExtent(std::to_string(mUnfair), &wid, &hit);
    graphics->DrawText(std::to_string(mUnfair), 300 - wid/2, 100 - hit/2);

    graphics->GetTextExtent(std::to_string(mMissed), &wid, &hit);
    graphics->DrawText(std::to_string(mMissed), 0 - wid/2, 100 - hit/2);

    graphics->GetTextExtent(std::to_string(mCorrect), &wid, &hit);
    graphics->DrawText(std::to_string(mCorrect), -300 - wid/2, 100 - hit/2);

}
/**
 * General update function to redraw scores
 */
void Scoreboard::Update()
{
    double wid, hit;
    mGraphics->SetBrush(*wxWHITE_BRUSH);
    mGraphics->SetPen(*wxTRANSPARENT_PEN);

    mGraphics->GetTextExtent(std::to_string(mUnfair-1), &wid, &hit);
    mGraphics->DrawRectangle(300 - wid/2, 100 - hit/2,wid,hit);

    mGraphics->GetTextExtent(std::to_string(mUnfair), &wid, &hit);
    mGraphics->DrawText(std::to_string(mUnfair), 300 - wid/2, 100 - hit/2);

    mGraphics->GetTextExtent(std::to_string(mMissed-1), &wid, &hit);
    mGraphics->DrawRectangle(0 - wid/2, 100 - hit/2,wid,hit);

    mGraphics->GetTextExtent(std::to_string(mMissed), &wid, &hit);
    mGraphics->DrawText(std::to_string(mMissed), 0 - wid/2, 100 - hit/2);

    mGraphics->GetTextExtent(std::to_string(mCorrect-1), &wid, &hit);
    mGraphics->DrawRectangle(-300 - wid/2, 100 - hit/2,wid,hit);

    mGraphics->GetTextExtent(std::to_string(mCorrect), &wid, &hit);
    mGraphics->DrawText(std::to_string(mCorrect), -300 - wid/2, 100 - hit/2);
}