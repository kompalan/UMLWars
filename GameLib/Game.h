/**
 * @file Game.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_GAME_H
#define INC_335PROJECT1_GAME_H

#include "Item.h"
#include "Harold.h"
#include <wx/graphics.h>
#include "UMLData.h"
#include "Scoreboard.h"
#include "Pen.h"
#include <random>

/**
 * Game Class that represents one Instance of the UML Wars
 * Game.
 */
class Game {
private:
    /// Collection of items holding everything on the screen
    std::vector<std::shared_ptr<Item>> mItems;

    /// UML data for the game
    std::shared_ptr<UMLData> mData;

    /// Game area width in virtual pixels
    const static int mWidth = 1250;

    /// Game area height in virtual pixels
    const static int mHeight = 1000;

    /// X Offset to reposition the drawing to
    double mXOffset;

    /// Y Offset to reposition the drawing to
    double mYOffset;

    /// New Scale of the Drawing
    double mScale;

    /// Pointer to Harold
    std::shared_ptr<Harold> mHarold;

    /// Pointer to Scoreboard
    std::shared_ptr<Scoreboard> mScoreboard;

    /// Random number generator
    std::mt19937 mRandom;

public:
    Game();
    void OnDraw(wxGraphicsContext *graphics, int width, int height);
    void Update(double elapsed);

    void OnMouseMove(int mouseX, int mouseY);

    void OnLeftDown(int mouseX, int mouseY);
    void AddItem(std::shared_ptr<Item> item);

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

    bool HitTest(std::shared_ptr<Pen> pen, std::shared_ptr<Item>);

    /**
     * Check if item is still in screen and delete it if not
     * @return Whether item is in screen or not
     */
    bool CheckItemOnScreen(std::shared_ptr<Item> item);
};

#endif //INC_335PROJECT1_GAME_H
