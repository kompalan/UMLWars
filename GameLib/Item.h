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
#include "Vector.h"

class Game; ///< Forward Reference to the Game Class

/**
 * Class Representing a Specific Item on the Screen
 *
 */
class Item {
private:
    /// Reference to game object for forward reference
    Game *mGame;

    double mX = 0; ///< X location for the center of the item in virtual pixels
    double mY = 0; ///< Y location for the center of the item in virtual pixels

    /// The velocity of the object
    cse335::Vector mVelocity = cse335::Vector();

public:
    double GetX() const;
    double GetY() const;
    /**
     * Getter for Item Width
     * @return double for Width or 0 if not applicable
     */
    virtual double GetWidth() const {return 0;}
    /**
    * Getter for Item Height
    * @return double for Height or 0 if not applicable
    */
    virtual double GetHeight() const {return 0;}
    /**
     * Pure virtual function for drawing. Anything that is an
     * item has to implement its own draw function
     * @param graphics wxGraphicsContext object
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

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

    /**
     * Get mGame object that can be used to get the bound
     * @return mGame object
     */
    Game* GetGame() {return mGame;}

    /**
     * Set the x and y speed of the item
     * @param speedX the x speed of the UML object in pixels second
     * @param speedY the x speed of the UML object in pixels second
     */
    void SetSpeed(double speedX, double speedY) { mVelocity.Set(speedX, speedY); };

    /**
     * Get the velocity vector of the item
     * @return the velocity vector of the item
     */
    const cse335::Vector& GetVelocity() const { return mVelocity; }

protected:
    Item(Game *game, double posX, double posY);
    Item(Game *game);
};

#endif //INC_335PROJECT1_ITEM_H
