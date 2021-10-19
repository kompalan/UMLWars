/**
 * @file Emitter.cpp
 * @author Anurag Kompalli
 */

#include "Emitter.h"
#include "GoodUMLName.h"
#include "GoodClassUML.h"

/**
 * Constructor for Emitter
 * Creates two Random Devices to independently choose good and
 * inheritance. Also initializes the UMLData object to create UML
 * @param game Game object
 */
Emitter::Emitter(Game *game, std::shared_ptr<UMLData> data) : mGame(game)
{
    mData = data;
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
 * @return Item Object with UML or Nullptr if nothing should be added
 */
std::shared_ptr<Item> Emitter::Create(double elapsed)
{
    mTotalElapsed += elapsed;

    if(mTotalElapsed > 2) {
        mTotalElapsed = 0;
        std::shared_ptr<Item> uml = Emit(mDistributionGood(mRandomGood), mDistribution(mRandomInheritance));

        if (mBadThreshold < 50) {
            mBadThreshold += 2;
        }

        if (mInheritanceThreshold < 50) {
            mInheritanceThreshold += 2;
        }

        return uml;
    }

    return nullptr;
}

/**
 * Helped function for create. Takes a good and inheritance value
 * and decides whether we should make a class or inheritance uml
 * @param good Random good value
 * @param inheritance Random inheritance value
 * @return Item object
 */
std::shared_ptr<Item> Emitter::Emit(double good, double inheritance)
{
    if (inheritance > mInheritanceThreshold) {
        return MakeClass(good);
    }
    else
    {
        return MakeInheritance(good);
    }
}

/**
 * Helper function for Emit. Makes a Bad UML Class
 * if the good value is above a certain threshold, otherwise
 * make a Good UML Class
 * @param good Random variable
 * @return
 */
std::shared_ptr<Item> Emitter::MakeClass(double good)
{
    if (good > mBadThreshold)
    {
        /// Make Bad Class
        return mData->GenerateBadClassUML();
    }
    else
    {
        /// Make Good Class
        return mData->GenerateGoodClassUML();
    }
}

/**
 * Helper function for Emit. Makes a Bad Inheritance class
 * if the good value is above a certain threshold, otherwise
 * make a Good Inheritance Class
 * @param good Random Variable
 * @return Item object
 */
std::shared_ptr<Item> Emitter::MakeInheritance(double good)
{
    if (good > mBadThreshold)
    {
        /// Make Bad Inheritance
        return mData->GenerateBadInheritance();
    }
    else
    {
        return mData->GenerateGoodInheritance();
    }
}
