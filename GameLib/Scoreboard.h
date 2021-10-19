/**
 * @file Scoreboard.h
 * @author Joe Getzen
 * @author Anurag Kompalli
 *
 */

#pragma once

#ifndef INC_335PROJECT1_SCOREBOARD_H
#define INC_335PROJECT1_SCOREBOARD_H

/**
 * Scoreboard class to keep track of correct,
 * missing, or unfair points in the game
 */
class Scoreboard {
private:
    ///Correct score
    int mCorrect=0;
    ///Missed score
    int mMissed=0;
    ///Unfair score
    int mUnfair=0;
public:
    Scoreboard();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
    * Increments the Correct score by 1
    */
    void IncCorrect() {mCorrect+=1;}

    /**
    * Increments the Missed score by 1
    */
    void IncMissed() {mMissed+=1;}

    /**
    * Increments the Unfair score by 1
    */
    void IncUnfair() {mUnfair+=1;}

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
};

#endif //INC_335PROJECT1_SCOREBOARD_H
