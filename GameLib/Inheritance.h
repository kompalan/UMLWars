/**
 * @file Inheritance.h
 * @author Ian Byram
 *
 * Class for inheritance UML objects
 */

#ifndef INC_335PROJECT1_INHERITANCE_H
#define INC_335PROJECT1_INHERITANCE_H

#include "Item.h"
#include "UML.h"

/**
 * Class for inheritance UML objects
 */
class Inheritance : public Item {
private:
    /// The base class of the inheritance relationship
    std::shared_ptr<UML> mBase;

    /// The derived class of the inheritance relationship
    std::shared_ptr<UML> mDerived;

    /// If the inheritance relationship is upside down
    bool mDown = false;

    /// The width of the inheritance object in pixels
    double mWidth = 100;

    /// The height of the inheritance object object in pixels
    double mHeight = 100;

    /// If the appropriate dimensions of the UML object have been calculated
    bool mDimensionCalculated = false;

    bool mIsHit = false;

protected:
    Inheritance(Game *game, std::shared_ptr<UML> base, std::shared_ptr<UML> derived);

    Inheritance(Game *game, std::shared_ptr<UML> base, std::shared_ptr<UML> derived, bool down);
public:
    /// Default constructor (disabled)
    Inheritance() = delete;

    /// Copy constructor (disabled)
    Inheritance(const Inheritance &) = delete;

    /// Assignment operator
    void operator=(const Inheritance &) = delete;

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitInheritance(this); }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update(double elapsed) override;

    void SetOnHit(bool isHit) { mIsHit = isHit; }
    /**
     * Get the width of the inheritance object in pixels
     * @return the width of the inheritance object in pixels
     */
    double GetWidth() const override { return mWidth; }

    /**
     * Get the height of the inheritance object in pixels
     * @return the height of the inheritance object in pixels
     */
    double GetHeight() const override { return mHeight; }
};

#endif //INC_335PROJECT1_INHERITANCE_H
