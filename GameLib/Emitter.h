/**
 * @file Emitter.h
 * @author Anurag
 *
 *
 */

#ifndef INC_335PROJECT1_EMITTER_H
#define INC_335PROJECT1_EMITTER_H

#include <random>
#include "UML.h"
#include "UMLData.h"

class Game;

class Emitter {
private:
    /// Overall elapsed time. Used to decide whether to generate UML
    double mTotalElapsed = 0;

    std::shared_ptr<UMLData> mData;

    /// Random Variable to decide whether a good UML should be emitted
    std::mt19937 mRandomGood;

    /// Random Variable to decide whether an Inheritance or Class UML should be emitted
    std::mt19937 mRandomInheritance;

    std::mt19937 mSize;

    /// Game object for forward reference
    Game *mGame;

    /// Threshold of good versus bad, limits which UML is created
    int mBadThreshold = 0;

    /// Threshold of Inheritance vs Class, limits Inheritance UML Creation
    int mInheritanceThreshold = 0;

    /// Uniform Distribution to filter mRandom to a value between 0 and 100
    std::uniform_real_distribution<> mDistribution = std::uniform_real_distribution<>(0, 100);
    std::uniform_real_distribution<> mDistributionGood = std::uniform_real_distribution<>(0, 100);
public:
    Emitter(Game *game, std::shared_ptr<UMLData> data);
    std::shared_ptr<Item> Create(double elapsed);
    std::shared_ptr<Item> Emit(double good, double inheritance);
    std::shared_ptr<Item> MakeInheritance(double good);
    std::shared_ptr<Item> MakeClass(double good);

    /**
     * Get The Good Random Variable
     * @return Random Good Variable
     */
    std::mt19937 &GetRandomGood() {return mRandomGood;}

    /**
     * Get The Inheritance Random Variable
     * @return Inheritance Random Variable
     */
    std::mt19937 &GetRandomInheritance() {return mRandomInheritance;}

    /**
     * Set the Bad Threshold Manually, used for testing
     * @param bad threshold to set
     */
    void SetBadThreshold(int bad) { mBadThreshold = bad; }

    /**
     * Set the Inheritance Threshold Manually, used for testing
     * @param inheritance threshold to set
     */
    void SetInheritanceThreshold(int inheritance) { mInheritanceThreshold = inheritance; }
};

#endif //INC_335PROJECT1_EMITTER_H
