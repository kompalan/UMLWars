/**
 * @file ClassUML.cpp
 * @author Kristian Rica
 * @author Ian Byram
 */

#include "pch.h"
#include "ClassUML.h"
#include "GoodUMLVisitor.h"

using namespace std;


/// The minimum width the UML object can be in pixels
const double MinWidth = 100;

/// The minimum height the UML object can be in pixels
const double MinHeight = 25;

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
ClassUML::ClassUML(Game *game, std::shared_ptr<UMLName> name, std::vector<std::shared_ptr<UMLAttribute>> attributes,
        std::vector<std::shared_ptr<UMLOperation>> operations) : UML(game)
{
    mName = name;
    mAttributes = attributes;
    mOperations = operations;
}

/**
 * Draw the class UML object on the screen
 * @param graphics wxGraphicsContext object
 */
void ClassUML::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();

    /// The font for class names
    const wxFont NameFont(wxSize(0,15),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    /// The font for attributes and operations
    const wxFont NormalFont(wxSize(0,15),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    /// The font for displaying the message after UML is hit
    const wxFont DisplayFont(wxSize(0,30),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    /// The light yellow color of the UML rectangle
    const wxColour lightYellow = wxColour(255, 255, 193);

    // Check if the width and height of the UML has been calculated already
    if (!GetDimensionsCalculated())
    {
        CalculateDimensions(graphics);
    }

    double wid, hit; //< Width and height variables to store GetTextExtent return values in

    double currentY = GetY() - GetHeight()/2; //< The current y value things are being drawn at

    // Set the brush and pen to draw the light yellow rectangle of the UML
    wxBrush rectBrush(lightYellow);
    graphics->SetBrush(rectBrush);
    wxPen pen(*wxBLACK);
    graphics->SetPen(pen);

    // Draw the light yellow rectangle of the UML
    graphics->DrawRectangle(GetX()-GetWidth()/2, currentY, GetWidth(), GetHeight());

    // Draw the class name at centered at the top of the rectangle
    graphics->SetFont(NameFont, *wxBLACK);
    graphics->GetTextExtent(mName->GetItem(), &wid, &hit);
    graphics->DrawText(mName->GetItem(), GetX() - wid/2, currentY);

    currentY += hit; //< Increment the current y value

    // Draw a separator line below the class name
    graphics->StrokeLine(GetX() - GetWidth()/2, currentY, GetX() + GetWidth()/2, currentY);

    // Go through each attribute in the UML object and draw the text left justified in the rectangle
    if (mAttributes.size() != 0)
    {
        graphics->SetFont(NormalFont, *wxBLACK);
        for (auto attribute : mAttributes)
        {
            graphics->GetTextExtent(attribute->GetItem(), &wid, &hit);
            graphics->DrawText(attribute->GetItem(), GetX() -GetWidth()/2 + LeftRightPadding, currentY);
            currentY += hit; //< Increment the current y value
        }
    }

    // Go through each operation in the UML object and draw the text left justified in the rectangle
    if (mOperations.size() != 0)
    {
        graphics->StrokeLine(GetX() - GetWidth()/2, currentY, GetX() + GetWidth()/2, currentY);
        graphics->SetFont(NormalFont, *wxBLACK);
        for (auto operation : mOperations)
        {
            graphics->GetTextExtent(operation->GetItem(), &wid, &hit);
            graphics->DrawText(operation->GetItem(), GetX() - GetWidth()/2 + LeftRightPadding, currentY);
            currentY += hit; //< Increment the current y value
        }
    }

    if (IsHit())
    {
        GoodUMLVisitor visitor;

        Accept(&visitor);

        if (visitor.IsGood())
        {
            graphics->SetFont(DisplayFont, *wxRED);
        }
        else
        {
            graphics->SetFont(DisplayFont, wxColour(44, 117, 36));
        }

        graphics->GetTextExtent(GetMessage(), &wid, &hit);
        graphics->DrawText(GetMessage(), GetX()-wid/2, GetY()-hit/2);
    }

    graphics->PopState();
}

/**
 * Calculates the required width and height of a UML object
 * @param graphics wxGraphicsContext object
 */
void ClassUML::CalculateDimensions(shared_ptr<wxGraphicsContext> graphics)
{
    /// The font for class names
    const wxFont NameFont(wxSize(0,15),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    /// The font for attributes and operations
    const wxFont NormalFont(wxSize(0,15),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    /// The font for displaying the message after UML is hit
    const wxFont DisplayFont(wxSize(0,30),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    /// The light yellow color of the UML rectangle
    const wxColour lightYellow = wxColour(255, 255, 193);

    graphics->SetFont(NameFont, *wxBLACK);

    double wid, hit; //< Width and height variables to store GetTextExtent return values in

    // Get the width and height of the class name and initialize the UML width and height to those values
    graphics->GetTextExtent(mName->GetItem(), &wid, &hit);
    double height = hit;
    double width = wid;

    graphics->SetFont(NormalFont, *wxBLACK);

    // Go through each attribute in the UML object and add the required height to the UML height and check if
    // the UML width needs to be replaced with a larger value to accommodate wider text
    for (auto attribute: mAttributes) {
        graphics->GetTextExtent(attribute->GetItem(), &wid, &hit);
        height += hit;
        if (wid > width) {
            width = wid;
        }
    }

    // Go through each operation in the UML object and add the required height to the UML height and check if
    // the UML width needs to be replaced with a larger value to accommodate wider text
    for (auto operation: mOperations) {
        graphics->GetTextExtent(operation->GetItem(), &wid, &hit);
        height += hit;
        if (wid > width) {
            width = wid;
        }
    }

    // Check if the UML width and height are below the minimum values. If they are, set them to the minimum values
    if (width < MinWidth)
    {
        width = MinWidth;
    }
    if (height < MinHeight)
    {
        height = MinHeight;
    }

    // Add a left-right and top-bottom padding to the width and height so when the text is drawn it isn't right
    // at the edge of the rectangle
    width += LeftRightPadding;
    height += TopBottomPadding;

    // Set the width and height of the UML to the calculated values
    SetWidth(width);
    SetHeight(height);

    // Set to true to avoid recalculating the width and height each time the object is drawn
    SetDimensionsCalculated(true);
}