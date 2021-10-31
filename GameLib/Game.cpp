/**
 * @file Game.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Game.h"
#include "Harold.h"
#include "Pen.h"
#include "Emitter.h"
#include "BadUMLVisitor.h"
#include "UMLHitVisitor.h"
#include "DeleteUMLVisitor.h"
#include "UMLOnScreenVisitor.h"
#include "TAScoreVisitor.h"
#include "TAHitVisitor.h"

using namespace std;

/// XML file to read the UML data from
const std::wstring Filename = L"data/uml.xml";
///PNG file for the variant background image
const std::wstring VarBackground = L"images/bounce house.png";

/**
 * Constructor
 */
Game::Game()
{
    /// Add and load the UML data
    mData = std::make_shared<UMLData>(this);
    mData->LoadData(Filename);

    ///Add Scoreboard to Game
    mScoreboard = std::make_shared<Scoreboard>();

    /// Add Harold to the Screen
    mHarold = std::make_shared<Harold>(this);
    AddItem(mHarold);

    ///Add Pen to the Screen
    AddItem(std::make_shared<Pen>(this));

    /// Instantiate random device for the game
    std::random_device rd;
    mRandom.seed(rd());

    mEmitter = std::make_shared<Emitter>(this, mData);

    auto ta = std::make_shared<TA>(this);
    AddItem(ta);

    mBackgroundImage = std::make_unique<wxImage>(VarBackground, wxBITMAP_TYPE_ANY);

    mBackground = wxBitmap(VarBackground, wxBITMAP_TYPE_ANY);
}

/**
 * Draw the View on the Graphics Context using Virtual Pixels
 * @param graphics Graphics Context to Draw on
 * @param width Height of the Window
 * @param height Width of the Window
 */
void Game::OnDraw(shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(mWidth);
    auto scaleY = double(height) / double(mHeight);
    mScale = min(scaleX, scaleY);

    mXOffset = width / 2;
    mYOffset = 0;
    if (height > mHeight * mScale) {
        mYOffset = (float)((height - mHeight * mScale) / 2);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);
    if (!mCustomVariant)
    {
        graphics->SetBrush(wxBrush(*wxWHITE_BRUSH));
        graphics->DrawRectangle(-mWidth/2, 0, mWidth, mHeight);
    }
    else
    {
        //mBackground = wxBitmap(VarBackground, wxBITMAP_TYPE_ANY);
        //mBackgroundBitmap = graphics->CreateBitmapFromImage(*mBackgroundImage);
        //graphics->DrawBitmap(mBackgroundBitmap,
                //-mWidth/2,
                //0,
                //mWidth,
                //mHeight);
    }
    for(auto item : mItems)
    {
        item->Draw(graphics);
    }

    mScoreboard->Draw(graphics);

    graphics->PopState();
}

/**
 * Update function of the Game: Handles Animations
 * @param elapsed Time Elapsed since Last OnDraw
 */
void Game::Update(double elapsed)
{
    int index = 0;

    DeleteUMLVisitor deleteVisitor;

    while (index < mItems.size())
    {
        mItems.at(index)->Update(elapsed);
        CheckItemOnScreen(mItems.at(index));
        mItems.at(index)->Accept(&deleteVisitor);
        ++index;
    }

    DeleteUML(deleteVisitor.GetToDelete());

    mEmitter->Create(elapsed);
}

/**
 * Adds an item to the list
 * @param item Item to add to the list
 */
void Game::AddItem(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
 * Convert the X and Y pixel coordinates to virtual
 * pixel coordinates and call each items respective handler
 * @param mouseX X coordinate of Mouse
 * @param mouseY Y coordinate of Mouse
 */
void Game::OnMouseMove(int mouseX, int mouseY)
{
    double virtualX = (mouseX - mXOffset) / mScale;
    double virtualY = (mouseY - mYOffset) / mScale;

    for(auto item : mItems)
    {
        item->HandleMouseMove(virtualX, virtualY);
    }
}

/**
 * Define the mose left down operation
 * @param mouseX X coordinate of Mouse
 * @param mouseY Y coordinate of Mouse
 */
void Game::OnLeftDown(int mouseX, int mouseY)
{
    double virtualX = (mouseX - mXOffset) / mScale;
    double virtualY = (mouseY - mYOffset) / mScale;

    for(auto item : mItems)
    {
        item->HandleMouseDown(virtualX, virtualY);
    }
}

/**
 * HitTest using center point of pen against range of tested object's dimensions
 * @param pen Pen object, center point used
 * @param obj Tested object, dimensions tested
 * @return bool true if collision occurs
 */
bool Game::HitTest(Pen *pen, std::shared_ptr<Item> obj)
{
    if (pen->IsThrown()) {
        double penX = pen->GetX()+(pen->GetWidth()/2);
        double penY = pen->GetY()-(pen->GetHeight()/2);

        double objX = obj->GetX();
        double objY = obj->GetY();
        //TA item should be able to use GetWidth() and GetHeight on its bitmap
        double objWidth = obj->GetWidth();
        double objHeight = obj->GetHeight();

        //HitTest using center point of pen against range of tested object's dimensions
        if (((penX>=(objX-objWidth/2) && penX<=(objX+objWidth/2)) &&
                (penY>=(objY-objHeight/2) && penY<=(objY+objHeight/2))) ||
                ((penX-50>=(objX-objWidth/2) && penX-50<=(objX+objWidth/2)) &&
                (penY>=(objY-objHeight/2) && penY<=(objY+objHeight/2)))
                ) {
            return true;
        }
    }

    return false;
}

/**
 * Tests an item against the bounds of the screen
 * @param item item object being tested
 * @return bool true if item passes bounds of screen
 */
void Game::CheckItemOnScreen(std::shared_ptr<Item> item)
{
    UMLOnScreenVisitor onScreenVisitor;
    item->Accept(&onScreenVisitor);
    if (!onScreenVisitor.IsOnScreen())
    {
        BadUMLVisitor badVisitor;
        item->Accept(&badVisitor);
        if (badVisitor.IsBad())
        {
            mScoreboard->IncMissed();
        }
    }
}

/**
 * Given a pen, iterate through the items and remove
 * all items that return true with hittest. Run a visitor
 * on the item to figure out how to update the scoreboard
 *
 * @param pen Pen pointer
 * @param mTime Cumulative time passed since pen was thrown
 */
void Game::RemoveOnHit(Pen *pen, double mTime)
{
    for(auto item : mItems)
    {
        if (item.get() == pen|| item.get() == mHarold.get())
        {
            continue;
        }

        BadUMLVisitor badVisitor;

        if (HitTest(pen, item))
        {
            UMLHitVisitor hitVisitor;
            item->Accept(&hitVisitor);

            TAHitVisitor taHitVisitor;
            item->Accept(&taHitVisitor);

            if (taHitVisitor.GetHit() && !taHitVisitor.GetSpawned())
            {
                continue;
            }

            auto loc = find(mItems.begin(), mItems.end(), item);
            if (loc != mItems.end())
            {


                item->Accept(&badVisitor);

                if (!taHitVisitor.GetHit())
                {
                    if(!badVisitor.IsBad())
                    {
                        mScoreboard->IncUnfair();
                    }
                    else
                    {
                        mScoreboard->IncCorrect();

                        for (auto item : mItems)
                        {
                            TAScoreVisitor ta;
                            item->Accept(&ta);

                        }

                    }
                }

                pen->SetRecord(true);

                pen->Stop();

                break;
            }
        }
    }
    if (mTime > mTimeToReturn)
    {
        pen->ReturnToHarold();
    }
}

/**
 * Deletes all UML which appear in the parameter list from the
 * main list
 * @param toDelete List of UML Objects to Delete
 */
void Game::DeleteUML(std::vector<UML*> toDelete)
{
    for (auto uml : toDelete)
    {
        auto loc = find_if(mItems.begin(), mItems.end(), [&uml] (auto &item) { return item.get() == uml; });

        if (loc != mItems.end())
        {
            mItems.erase(loc);
        }
    }
}

/**
 * Deletes all UML from the Screen and Increments
 * the Score by the Amount of UML Deleted
 * @param ta TA object to filter out
 */
void Game::DeleteAllBadUML(TA *ta) {
    for(auto item : mItems)
    {

        BadUMLVisitor badVisitor;
        UMLHitVisitor hitVisitor;


        item->Accept(&badVisitor);


        if(badVisitor.IsBad())
        {
            item->Accept(&hitVisitor);
            mScoreboard->IncCorrect();
        }
    }
}
