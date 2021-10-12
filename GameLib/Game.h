/**
 * @file Game.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_GAME_H
#define INC_335PROJECT1_GAME_H

#include "pch.h"
#include <wx/graphics.h>
/**
 * Game Class that represents one Instance of the UML Wars
 * Game.
 */
class Game {
private:
    /// wxImage pointer to the Image of Harold in images/harold.png
    std::shared_ptr<wxImage> mHaroldImage;

    /// Converted bitmap from mHaroldImage
    wxGraphicsBitmap mHaroldBitmap;

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

};

#endif //INC_335PROJECT1_GAME_H
