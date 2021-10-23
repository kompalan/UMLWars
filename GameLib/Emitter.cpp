/**
 * @file Emitter.cpp
 * @author Anurag Kompalli
 */
#include "pch.h"
#include "Emitter.h"
#include "GoodUMLName.h"
#include "GoodClassUML.h"
#include "Game.h"

/// The minimum x speed of the objects being emitted
const double MinSpeedX = 0;

/// The maximum x speed of the objects being emitted
const double MaxSpeedX = 50;

/// The initial y speed of the objects being emitted
const double InitialSpeedY = 40;

/// The maximum y speed of the objects being emitted
const double MaxSpeedY = 100;

/// The amount to increase the y speed each time
const double SpeedYIncrement = 5;

/// The time between each object creation
const double TimeToCreate = 2;

/// The time between each speed increase
const double TimeToIncreaseSpeed = 30;

/// The y coordinate the objects are emitted at
const double EmitPositionY = 0;

/// The minimum x coordinate the objects are emitted at
const double MinEmitPositionX = -300;

/// The maximum x coordinate the objects are emitted at
const double MaxEmitPositionX = 300;

/**
 * Constructor for Emitter
 * Creates two Random Devices to independently choose good and
 * inheritance. Also initializes the UMLData object to create UML
 * @param game Game object
 */
Emitter::Emitter(Game *game, std::shared_ptr<UMLData> data) : mGame(game)
{
    mData = data;
    mYSpeed = InitialSpeedY;
    std::random_device rdGood;
    std::random_device rdInheritance;
    std::random_device rdSize;

    mRandomGood.seed(rdGood());
    mRandomInheritance.seed(rdInheritance());
    mSize.seed(rdSize());
}

/**
 * Creates the UML to Add to the Game
 * @param elapsed Time elapsed since last onPaint call
 * @return
 */
void Emitter::Create(double elapsed)
{
    mCreateTime += elapsed;
    mIncreaseSpeedTime += elapsed;

    if(mCreateTime > TimeToCreate)
    {
        mCreateTime = 0;

        if (mIncreaseSpeedTime > TimeToIncreaseSpeed && mYSpeed < MaxSpeedY)
        {
            mYSpeed += SpeedYIncrement;
            mIncreaseSpeedTime = 0;
        }

        Emit(mDistributionGood(mRandomGood), mDistribution(mRandomInheritance));

        if (mBadThreshold < 50) {
            mBadThreshold += 2;
        }

        if (mInheritanceThreshold < 50) {
            mInheritanceThreshold += 2;
        }
    }
}

/**
 * Helper function for create. Takes a good and inheritance value
 * and decides whether we should make a class or inheritance uml
 * @param good Random good value
 * @param inheritance Random inheritance value
 * @return
 */
void Emitter::Emit(double good, double inheritance)
{
    std::shared_ptr<Item> uml;

    if (inheritance > mInheritanceThreshold) {
        uml = MakeClass(good);
    }
    else
    {
        uml = MakeInheritance(good);
    }
    std::uniform_real_distribution<> DistributionXPos(MinEmitPositionX, MaxEmitPositionX);
    std::uniform_real_distribution<> DistributionXSpeed(MinSpeedX, MaxSpeedX);

    double xPosition = DistributionXPos(mGame->GetRandom());
    double xSpeed = DistributionXSpeed(mGame->GetRandom());

    uml->SetLocation(xPosition,EmitPositionY);

    if (xPosition < 0)
    {
        uml->SetSpeed(xSpeed,mYSpeed);
    }
    else
    {
        uml->SetSpeed(-xSpeed,mYSpeed);
    }
    mGame->AddItem(uml);
}

/**
 * Helper function for Emit. Makes a Bad UML Class
 * if the good value is above a certain threshold, otherwise
 * make a Good UML Class
 * @param good Random variable
 * @return a UML class object
 */
std::shared_ptr<ClassUML> Emitter::MakeClass(double good)
{
    std::shared_ptr<ClassUML> uml;
    if (good > mBadThreshold)
    {
        /// Make Bad Class
        uml = mData->GenerateBadClassUML();
    }
    else
    {
        /// Make Good Class
        uml = mData->GenerateGoodClassUML();
    }
    return uml;
}

/**
 * Helper function for Emit. Makes a Bad Inheritance class
 * if the good value is above a certain threshold, otherwise
 * make a Good Inheritance Class
 * @param good Random Variable
 * @return an Inheritance object
 */
std::shared_ptr<Inheritance> Emitter::MakeInheritance(double good)
{
    std::shared_ptr<Inheritance> inheritance;
    if (good > mBadThreshold)
    {
        /// Make Bad Inheritance
        inheritance = mData->GenerateBadInheritance();
    }
    else
    {
        // Make good inheritance
        inheritance = mData->GenerateGoodInheritance();
    }
    return inheritance;
}
