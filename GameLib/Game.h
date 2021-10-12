/**
 * @file Game.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_GAME_H
#define INC_335PROJECT1_GAME_H

#include "pch.h"
#include "Item.h"
#include "Harold.h"
#include <wx/graphics.h>

/**
 * Game Class that represents one Instance of the UML Wars
 * Game.
 */
class Game {
private:
    /// Collection of items holding everything on the screen
    std::vector<std::shared_ptr<Item>> mItems;

public:
    /// Game area in virtual pixels
    const static int Width = 1250;

    /// Game area height in virtual pixels
    const static int Height = 1000;

    /// X Offset to reposition the drawing to
    double mXOffset;

    /// Y Offset to reposition the drawing to
    double mYOffset;

    /// New Scale of the Drawing
    double mScale;


    Game();
    void OnDraw(wxGraphicsContext *graphics, int width, int height);
    void Update(double elapsed);

    void AddItem(std::shared_ptr<Item> item);
};

#endif //INC_335PROJECT1_GAME_H
