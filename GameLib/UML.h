/**
 * @file UML.h
 * @author Ian Byram
 *
 * Base class for all UML objects
 */

#ifndef INC_335PROJECT1_UML_H
#define INC_335PROJECT1_UML_H

#include "Item.h"

/**
 * Base class for all UML objects
 */
class UML : public Item {
private:
    /// The width of the UML object in pixels
    double mWidth = 0;

    /// The height of the UML object in pixels
    double mHeight = 0;

    /// If the appropriate dimensions of the UML object have been calculated
    bool mDimensionCalculated = false;

    /// The message to display when the UML is hit
    std::wstring mMessage;

    /// The time since the UML object was hit
    double mTimeHit = 0;

    /// If the UML has been hit by the pen
    bool mIsHit = false;

protected:
    UML(Game *game);

public:
//    /// Default constructor (disabled)
//    UML() = delete;
//
//    /// Copy constructor (disabled)
//    UML(const UML &) = delete;
//
//    /// Assignment operator
//    void operator=(const UML &) = delete;

    /**
     * Calculates the dimensions of a UML object
     * @param graphics wxGraphicsContext object
     */
    virtual void CalculateDimensions(std::shared_ptr<wxGraphicsContext> graphics) {}

    /**
     * Draws a UML object
     * @param graphics wxGraphicsContext object
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}

    void Update(double elapsed) override;

    /**
     * Accept visitor
     * @param visitor visitor that's accepted
     */
    virtual void Accept(ItemVisitor* visitor) override { visitor->VisitUML(this); }

    /**
     * Get the width of the UML object in pixels
     * @return the width of the UML object in pixels
     */
    virtual double GetWidth() const override { return mWidth; }

    /**
     * Get the height of the UML object in pixels
     * @return the height of the UML object in pixels
     */
    virtual double GetHeight() const override { return mHeight; }

    /**
     * Sets the width of the UML object
     * @param width the width of the UML object
     */
    void SetWidth(double width) { mWidth = width; }

    /**
     * Sets the height of the UML object
     * @param height the width of the UML object
     */
    void SetHeight(double height) { mHeight = height; }

    /**
     * Gets if the dimensions of the UML are calculated
     * @return if the dimensions of the UML are calculated
     */
    bool GetDimensionsCalculated() { return mDimensionCalculated; }

    /**
     * Sets if the dimensions of the UML are calculated
     * @param isCalculated
     */
    void SetDimensionsCalculated(bool isCalculated) { mDimensionCalculated = isCalculated; }

    /**
     * Gets the UML display message
     * @return the UML display message
     */
    std::wstring GetMessage() { return mMessage; }

    /**
     * Sets the display message of the UML
     * @param message the message to set the UML message to
     */
    void SetMessage(std::wstring message) { mMessage = message; }

    /**
     * Gets whether the UML has been hit
     * @return if the UML has been hit
     */
    bool IsHit() { return mIsHit; }

    /**
     * Sets if the UML has been hit
     * @param isHit if the UML has been hit
     */
    void SetIsHit(bool isHit) { mIsHit = isHit; }

    /**
     * Get the time since the UML was hit
     * @return the time since the UML was hit
     */
    double GetTimeHit() { return mTimeHit; }

    /**
     * Sets the time the UML has been hit for
     * @param time the time the UML has been hit for
     */
    void SetTimeHit(double time) { mTimeHit = time; }
};

#endif //INC_335PROJECT1_UML_H
