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
#include "Emitter.h"
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

    /// Pointer to an Emitter
    std::shared_ptr<Emitter> mEmitter;

    /// The Threshold for stop for seconds
    double mTimeToReturn = 1.7;

    /// Boolean representing whether the variant is enabled
    bool mCustomVariant = false;

    ///Bitmap for the background image in variant
    wxBitmap mBackground;

public:
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void Update(double elapsed);

    void OnMouseMove(int mouseX, int mouseY);

    void OnLeftDown(int mouseX, int mouseY);

    void AddItem(std::shared_ptr<Item> item);

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() { return mRandom; }

    bool HitTest(Pen* pen, std::shared_ptr<Item>);

    void RemoveOnHit(Pen* pen, double mRecordTime);

    void DeleteUML(std::vector<UML*> toDelete);

    void DeleteAllBadUML(TA *ta);

    void CheckItemOnScreen(std::shared_ptr<Item> item);

    /**
     * Returns the size of the mItems vector
     * @return Size of the items vector
     */
    int GetSize() const {return mItems.size();}

    /**
     * Get screen height
     * @return height value
     */
    int GetHeight() {return mHeight;}

    /**
     * Get screen width
     * @return width value
     */
    int GetWidth() {return mWidth;}

    /**
     * Getter for Harold
     * @return Pointer to Harold Object
     */
    std::shared_ptr<Harold> GetHarold() {return mHarold;}

    /**
     * Set the boolean representing whether the variant is enabled
     * @param custom Boolean to set to
     */
    void SwitchVariant(bool custom) { mCustomVariant = custom; }

    /**
     * Return a boolean representing whether the variant was selected
     * @return
     */
    bool IsCustomSelected() { return mCustomVariant; }

    /**
     * Return the Scale of the Screen
     * @return Scale of the Screen
     */
    double GetScale() { return mScale; }

    /**
     * Returns the wxBitmap for Variant Background image
     * @return Bitmap of Background image
     */
    wxBitmap GetBackground() {return mBackground;}
};

#endif //INC_335PROJECT1_GAME_H
