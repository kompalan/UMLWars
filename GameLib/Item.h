/**
 * @file Item.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef INC_335PROJECT1_ITEM_H
#define INC_335PROJECT1_ITEM_H

#include <wx/graphics.h>
#include "ItemVisitor.h"

class Game; ///< Forward Reference to the Game Class

/**
 * Class Representing a Specific Item on the Screen
 *
 */
class Item {
private:
    /// Reference to game object for forward reference
    Game *mGame;

    double mX; ///< X location for the center of the item in virtual pixels
    double mY; ///< Y location for the center of the item in virtual pixels

public:
    double GetX() const;
    double GetY() const;

    /**
     * Pure virtual function for drawing. Anything that is an
     * item has to implement its own draw function
     * @param graphics wxGraphicsContext object
     */
    virtual void Draw(wxGraphicsContext *graphics) = 0;

    /**
     * Set the Item Location
     * @param x X location in virtual pixels
     * @param y Y location in virtual pixels
     */
    void SetLocation(double x, double y) { mX = x; mY = y; }

    /**
     * Handle updates for animation
     * @param elapsed Time since last onDraw call
     */
    virtual void Update(double elapsed) {}

    /**
     * Handle Mouse Move Event
     * @param virtualX X coordinate in virtual pixels
     * @param virtualY Y coordinate in virtual pixels
     */
    virtual void HandleMouseMove(double virtualX, double virtualY) {};

    virtual void HandleMouseDown(double virtualX, double virtualY) {};

    /**
     * Deleted Default Constructor
     */
    Item() = delete;

    /**
     * Deleted Copy Constructor
     * @param item
     */
    Item(const Item &item) = delete;

    /**
     * Deleted Assignment Operator
     * @param item
     */
    void operator=(const Item &item) = delete;

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) = 0;

protected:
    Item(Game *game, double posX, double posY);
};

#endif //INC_335PROJECT1_ITEM_H
