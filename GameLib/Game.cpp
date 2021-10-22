/**
 * @file Game.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Game.h"
#include "Harold.h"
#include "Pen.h"
#include "Emitter.h"
#include "GoodUMLVisitor.h"

using namespace std;

/// XML file to read the UML data from
const std::wstring Filename = L"data/uml.xml";

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
    while (index < mItems.size()) {
        mItems.at(index)->Update(elapsed);
        ++index;
    }

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
    double penX=pen->GetX();
    double penY=pen->GetY();

    double objX=obj->GetX();
    double objY=obj->GetY();
    //TA item should be able to use GetWidth() and GetHeight on its bitmap
    double objWidth=obj->GetWidth();
    double objHeight=obj->GetHeight();

    //HitTest using center point of pen against range of tested object's dimensions
    if((penX>=(objX-objWidth/2) && penX<=(objX+objWidth/2)) &&
    (penY>=(objY-objHeight/2) && penY<=(objY+objHeight/2)))
    {
        return true;
    }

    return false;
}
/**
 * Tests an item against the bounds of the screen
 * @param item Item object being tested
 * @return bool true if item passes bounds of screen
 */
bool Game::CheckItemOnScreen(std::shared_ptr<Item> item)
{
    double xVal = item->GetX();
    double yVal = item->GetY();
    vector<std::shared_ptr<Item>>::iterator out;
    if((xVal > mHeight) || (xVal < -10))
    {
        out = remove(mItems.begin(), mItems.end(), item);
        return false;
    }
    else if ((yVal > mWidth) || (yVal < 0)){
        out = remove(mItems.begin(), mItems.end(), item);
        return false;
    }
    return true;
}

/**
 * Given a pen, iterate through the items and remove
 * all items that return true with hittest. Run a visitor
 * on the item to figure out how to update the scoreboard
 *
 * @param pen Pen pointer
 */
void Game::RemoveOnHit(Pen *pen, double mTime)
{
    for(auto item : mItems)
    {
        if (item.get() == pen|| item.get() == mHarold.get()) {

            continue;
        }

        GoodUMLVisitor visitor;

        if (HitTest(pen, item))
        {

            auto loc = find(mItems.begin(), mItems.end(), item);

            if (loc != mItems.end())
            {

                item->Accept(&visitor);

                mItems.erase(loc);

                if(visitor.IsGood()) {
                    mScoreboard->IncUnfair();
                } else {
                    mScoreboard->IncCorrect();
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

