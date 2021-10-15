/**
 * @file Scoreboard.h
 * @author Joe Getzen
 *
 *
 */

#pragma once

#ifndef INC_335PROJECT1_SCOREBOARD_H
#define INC_335PROJECT1_SCOREBOARD_H

#include "Item.h"

const wxFont smallFont(wxSize(0, 20),
        wxFONTFAMILY_ROMAN,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_BOLD);

const wxFont bigFont(wxSize(0, 60),
        wxFONTFAMILY_MODERN,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_BOLD);

const wxColour burntOrange= wxColour(255,140,0);

class Scoreboard : public Item{
private:
    ///Correct score
    int mCorrect=0;
    ///Missed score
    int mMissed=0;
    ///Unfair score
    int mUnfair=0;
    ///GraphicsContext being drawn to
    wxGraphicsContext *mGraphics;
public:
    Scoreboard(Game *game);

    void Draw(wxGraphicsContext* graphics) override;
    /**
    * Increments the Correct score by 1
    */
    void IncCorrect() {mCorrect+=1;};
    /**
    * Increments the Missed score by 1
    */
    void IncMissed() {mMissed+=1;};
    /**
    * Increments the Unfair score by 1
    */
    void IncUnfair() {mUnfair+=1;};
    /**
     * Getter for Correct score
     * @return mCorrect
     */
    int GetCorrect() {return mCorrect;}
    /**
     * Getter for Missed score
     * @return mMissed
     */
    int GetMissed() {return mMissed;}
    /**
     * Getter for Unfair score
     * @return mUnfair
     */
    int GetUnfair() {return mUnfair;}

    void Update(double elapsed) override;

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitScoreboard(this); }
};

#endif //INC_335PROJECT1_SCOREBOARD_H
