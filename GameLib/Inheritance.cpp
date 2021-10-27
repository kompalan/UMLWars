/**
 * @file Inheritance.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "Inheritance.h"
#include "GoodUMLVisitor.h"

using namespace std;


/// The length of the arrow line between classes in pixels
const double ArrowLineLength = 16;

/// The height of the tip of the arrow in pixels
const double ArrowTipHeight = 10;

/// The width of the tip of the arrow in pixels
const double ArrowTipWidth = 12;

/**
 * Constructor
 * @param game the game the inheritance UML is a part of
 * @param base the base class of the inheritance
 * @param derived the derived class of the inheritance
 */
Inheritance::Inheritance(Game* game, std::shared_ptr<ClassUML> base, std::shared_ptr<ClassUML> derived) : UML(game)
{
    mBase = base;
    mDerived = derived;
}

/**
 * Constructor with a down parameter
 * @param game the game the inheritance UML is a part of
 * @param base the base class of the inheritance
 * @param derived the derived class of the inheritance
 * @param down if the inheritance relationship is upside down
 */
Inheritance::Inheritance(Game* game, std::shared_ptr<ClassUML> base, std::shared_ptr<ClassUML> derived, bool down) : UML(game)
{
    mBase = base;
    mDerived = derived;
    mDown = down;
}

/**
 * Draw the inheritance object on the screen
 * @param graphics wxGraphicsContext object
 */
void Inheritance::Draw(shared_ptr<wxGraphicsContext> graphics)
{

    graphics->PushState();

    /// The font for displaying the message after UML is hit
    wxFont DisplayFontInheritance(wxSize(0,30),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    // Check if the width and height of the inheritance have already been calculated to avoid recalculating them
    if (!GetDimensionsCalculated())
    {
        CalculateDimensions(graphics);
    }

    // X and Y centers for the base and derived classes
    double baseX, baseY, derivedX, derivedY;

    // Checks if the inheritance is upside to appropriately draw the base or derived class
    // on top and the arrow in the right direction
    if (mDown)
    {
        // Calculates the X and Y value for the derived class and sets its location there
        derivedX = GetX();
        derivedY = GetY() - GetHeight()/2 + mDerived->GetHeight()/2;
        mDerived->SetLocation(derivedX, derivedY);

        // Calculates the X and Y value for the base class and sets its location there
        baseX = GetX();
        baseY = GetY() + GetHeight()/2 - mBase->GetHeight()/2;
        mBase->SetLocation(baseX, baseY);

        // Draws the base and derived class at their calculated X and Y values
        mBase->Draw(graphics);
        mDerived->Draw(graphics);

        // Draw the arrow pointing down
        wxPen pen(*wxBLACK);
        graphics->SetPen(pen);

        graphics->StrokeLine(GetX(), derivedY + mDerived->GetHeight()/2,
                GetX(), derivedY + mDerived->GetHeight()/2 + ArrowLineLength);

        graphics->StrokeLine(GetX() - ArrowTipWidth/2, derivedY + mDerived->GetHeight()/2 + ArrowLineLength,
                GetX() + ArrowTipWidth/2, derivedY + mDerived->GetHeight()/2 + ArrowLineLength);

        graphics->StrokeLine(GetX() + ArrowTipWidth/2, derivedY + mDerived->GetHeight()/2 + ArrowLineLength,
                GetX(), derivedY + mDerived->GetHeight()/2 + ArrowLineLength + ArrowTipHeight);

        graphics->StrokeLine(GetX(), derivedY + mDerived->GetHeight()/2 + ArrowLineLength + ArrowTipHeight,
                GetX() - ArrowTipWidth/2, derivedY + mDerived->GetHeight()/2 + ArrowLineLength);

    }
    else
    {
        // Calculates the X and Y value for the base class and sets its location there
        baseX = GetX();
        baseY = GetY() - GetHeight()/2 + mBase->GetHeight()/2;
        mBase->SetLocation(baseX, baseY);

        // Calculates the X and Y value for the derived class and sets its location there
        derivedX = GetX();
        derivedY = GetY() + GetHeight()/2 - mDerived->GetHeight()/2;
        mDerived->SetLocation(derivedX, derivedY);

        // Draws the base and derived class at their calculated X and Y values
        mBase->Draw(graphics);
        mDerived->Draw(graphics);

        // Draw the arrow pointing up
        wxPen pen(*wxBLACK);
        graphics->SetPen(pen);

        graphics->StrokeLine(GetX(), derivedY - mDerived->GetHeight()/2,
                GetX(), derivedY - mDerived->GetHeight()/2 - ArrowLineLength);

        graphics->StrokeLine(GetX() - ArrowTipWidth/2, derivedY - mDerived->GetHeight()/2 - ArrowLineLength,
                GetX() + ArrowTipWidth/2, derivedY - mDerived->GetHeight()/2 - ArrowLineLength);

        graphics->StrokeLine(GetX() + ArrowTipWidth/2, derivedY - mDerived->GetHeight()/2 - ArrowLineLength,
                GetX(), derivedY - mDerived->GetHeight()/2 - ArrowLineLength - ArrowTipHeight);

        graphics->StrokeLine(GetX(), derivedY - mDerived->GetHeight()/2 - ArrowLineLength - ArrowTipHeight,
                GetX() - ArrowTipWidth/2, derivedY - mDerived->GetHeight()/2 - ArrowLineLength);
    }
    if (IsHit())
    {
        GoodUMLVisitor visitor;

        Accept(&visitor);

        if (visitor.IsGood())
        {
            graphics->SetFont(DisplayFontInheritance, *wxRED);
        }
        else
        {
            graphics->SetFont(DisplayFontInheritance, wxColour(44, 117, 36));
        }
        double wid, hit;

        graphics->GetTextExtent(GetMessage(), &wid, &hit);
        graphics->DrawText(GetMessage(), GetX()-wid/2, GetY()-hit/2);
    }

    graphics->PopState();
}

/**
 * Calculates the required width and height of an Inheritance object
 * @param graphics wxGraphicsContext object
 */
void Inheritance::CalculateDimensions(std::shared_ptr<wxGraphicsContext> graphics)
{
    mBase->CalculateDimensions(graphics); //< Calculate dimensions of the base class
    mDerived->CalculateDimensions(graphics); //< Calculate dimensions of the derived class

    // Set the width and height of the inheritance object to be and the max of the two widths and
    // the sum of all the heights (including the arrow parts)
    double height = mBase->GetHeight() + mDerived->GetHeight() + ArrowLineLength + ArrowTipHeight;
    double width = max(mBase->GetWidth(), mDerived->GetWidth());

    // Set the width and height of the inheritance to the calculated values
    SetWidth(width);
    SetHeight(height);

    SetDimensionsCalculated(true); //< Set to true to avoid recalculating dimensions each time the object is drawn
}