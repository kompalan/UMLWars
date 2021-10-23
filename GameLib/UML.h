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

protected:
    UML(Game *game);

public:
    /// Default constructor (disabled)
    UML() = delete;

    /// Copy constructor (disabled)
    UML(const UML &) = delete;

    /// Assignment operator
    void operator=(const UML &) = delete;

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
};

#endif //INC_335PROJECT1_UML_H
