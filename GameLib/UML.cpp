/**
 * @file UML.cpp
 * @author Kristian Rica
 * @author Ian Byram
 */

#include "pch.h"
#include "UML.h"

using namespace std;

/// The font for class names
const wxFont nameFont(wxSize(0,15),
        wxFONTFAMILY_SWISS,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_NORMAL);

/// The font for attributes and operations
const wxFont normalFont(wxSize(0,15),
        wxFONTFAMILY_SWISS,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_NORMAL);

/// The light yellow color of the UML rectangle
const wxColour lightYellow = wxColour(255, 255, 193);

/// The minimum width the UML object can be in pixels
const double MinWidth = 100;

/// The minimum height the UML object can be in pixels
const double MinHeight = 20;

/// Number of pixels to pad the left and right side of the UML object
const double LeftRightPadding = 5;

/// Number of pixels to pad the top and bottom of the UML object
const double TopBottomPadding = 5;

/**
 * Constructor
 * @param game the game the UML object is a part of
 * @param name the name of the UML object
 * @param attributes the attributes of the UML object
 * @param operations the operations of the UML object
 */
UML::UML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
        std::vector<std::shared_ptr<UMLOperation>> operations) : Item(game)
{
    mName = name;
    mAttributes = attributes;
    mOperations = operations;
    mWidth = MinWidth;
    mHeight = MinHeight;
}

/**
 * Constructor
 * @param game the game the UML object is a part of
 * @param name the name of the UML object
 * @param attributes the attributes of the UML object
 * @param operations the operations of the UML object
 * @param partOfInheritance if the class UML is a part of an inheritance relationship
 */
UML::UML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
        std::vector<std::shared_ptr<UMLOperation>> operations, bool partOfInheritance) : Item(game)
{
    mName = name;
    mAttributes = attributes;
    mOperations = operations;
    mWidth = MinWidth;
    mHeight = MinHeight;
    mPartOfInheritance = partOfInheritance;
}

/**
 * Draw the class UML object on the screen
 * @param graphics wxGraphicsContext object
 */
void UML::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();

    // Check if the UML object is a part of an inheritance to avoid translating
    // the graphics context twice when drawing inheritance UML
//    if (!mPartOfInheritance)
//    {
//        graphics->Translate(GetX(), GetY());
//    }

    // Check if the width and height of the UML has been calculated already
    if (!mDimensionCalculated)
    {
        CalculateDimensions(graphics);
    }

    double wid, hit; //< Width and height variables to store GetTextExtent return values in

    double currentY = GetY() - mHeight/2; //< The current y value things are being drawn at

    // Set the brush and pen to draw the light yellow rectangle of the UML
    wxBrush rectBrush(lightYellow);
    graphics->SetBrush(rectBrush);
    wxPen pen(*wxBLACK);
    graphics->SetPen(pen);

    // Draw the light yellow rectangle of the UML
    graphics->DrawRectangle(GetX()-mWidth/2, currentY, mWidth, mHeight);

    // Draw the class name at centered at the top of the rectangle
    graphics->SetFont(nameFont, *wxBLACK);
    graphics->GetTextExtent(mName->GetItem(), &wid, &hit);
    graphics->DrawText(mName->GetItem(), GetX() - wid/2, currentY);

    currentY += hit; //< Increment the current y value

    // Draw a separator line below the class name
    graphics->StrokeLine(GetX() - mWidth/2, currentY, GetX() + mWidth/2, currentY);

    // Go through each attribute in the UML object and draw the text left justified in the rectangle
    if (mAttributes.size() != 0)
    {
        graphics->SetFont(normalFont, *wxBLACK);
        for (auto attribute : mAttributes)
        {
            graphics->GetTextExtent(attribute->GetItem(), &wid, &hit);
            graphics->DrawText(attribute->GetItem(), GetX() -mWidth/2 + LeftRightPadding, currentY);
            currentY += hit; //< Increment the current y value
        }
    }

    // Go through each operation in the UML object and draw the text left justified in the rectangle
    if (mOperations.size() != 0)
    {
        graphics->StrokeLine(GetX() - mWidth/2, currentY, GetX() + mWidth/2, currentY);
        graphics->SetFont(normalFont, *wxBLACK);
        for (auto operation : mOperations)
        {
            graphics->GetTextExtent(operation->GetItem(), &wid, &hit);
            graphics->DrawText(operation->GetItem(), GetX() - mWidth/2 + LeftRightPadding, currentY);
            currentY += hit; //< Increment the current y value
        }
    }

    graphics->PopState();
}

/**
 * Updates the position of the UML object
 * @param elapsed the time since the last update
 */
void UML::Update(double elapsed)
{
    double newX = GetX() + GetVelocity().X() * elapsed;
    double newY = GetY() + GetVelocity().Y() * elapsed;
    SetLocation(newX, newY);
}

/**
 * Calculates the required width and height of a UML object
 * @param graphics wxGraphicsContext object
 */
void UML::CalculateDimensions(shared_ptr<wxGraphicsContext> graphics)
{
    graphics->SetFont(nameFont, *wxBLACK);

    double wid, hit; //< Width and height variables to store GetTextExtent return values in

    // Get the width and height of the class name and initialize the UML width and height to those values
    graphics->GetTextExtent(mName->GetItem(), &wid, &hit);
    mHeight = hit;
    mWidth = wid;

    graphics->SetFont(normalFont, *wxBLACK);

    // Go through each attribute in the UML object and add the required height to the UML height and check if
    // the UML width needs to be replaced with a larger value to accommodate wider text
    for (auto attribute: mAttributes) {
        graphics->GetTextExtent(attribute->GetItem(), &wid, &hit);
        mHeight += hit;
        if (wid > mWidth) {
            mWidth = wid;
        }
    }

    // Go through each operation in the UML object and add the required height to the UML height and check if
    // the UML width needs to be replaced with a larger value to accommodate wider text
    for (auto operation: mOperations) {
        graphics->GetTextExtent(operation->GetItem(), &wid, &hit);
        mHeight += hit;
        if (wid > mWidth) {
            mWidth = wid;
        }
    }

    // Check if the UML width and height are below the minimum values. If they are, set them to the minimum values
    if (mWidth < MinWidth)
    {
        mWidth = MinWidth;
    }
    if (mHeight < MinHeight)
    {
        mHeight = MinHeight;
    }

    // Add a left-right and top-bottom padding to the width and height so when the text is drawn it isn't right
    // at the edge of the rectangle
    mWidth += LeftRightPadding;
    mHeight += TopBottomPadding;

    // Set to true to avoid recalculating the width and height each time the object is drawn
    mDimensionCalculated = true;
}