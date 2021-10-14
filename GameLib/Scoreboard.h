/**
 * @file Scoreboard.h
 * @author Joe Getzen
 *
 *
 */

#ifndef INC_335PROJECT1_SCOREBOARD_H
#define INC_335PROJECT1_SCOREBOARD_H

#include "Item.h"

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

    void Update();
};

#endif //INC_335PROJECT1_SCOREBOARD_H
