/**
 * @file Emitter.h
 * @author Anurag
 *
 *
 */

#ifndef INC_335PROJECT1_EMITTER_H
#define INC_335PROJECT1_EMITTER_H

#include <random>
#include "ClassUML.h"
#include "UMLData.h"

class Game;

/**
 * Class for the UML Emitter. Objects of this class function
 * to create bad and good uml based on time and random generation and output
 * them to the screen.
 */
class Emitter {
private:
    /// Overall elapsed time. Used to decide whether to generate UML
    double mCreateTime = 0;

    /// The time since the speed of objects being emitted was increased
    double mIncreaseSpeedTime = 0;

    /// The y speed of the objects being emitted
    double mYSpeed;

    /// The UML data object
    std::shared_ptr<UMLData> mData;

    /// Random Variable to decide whether a good UML should be emitted
    std::mt19937 mRandomGood;

    /// Random Variable to decide whether an Inheritance or Class UML should be emitted
    std::mt19937 mRandomInheritance;

    /// Random Variable to decide the Size of the UML
    std::mt19937 mSize;

    /// Game object for forward reference
    Game *mGame;

    /// Threshold of good versus bad, limits which UML is created
    int mBadThreshold = 0;

    /// Threshold of Inheritance vs Class, limits Inheritance UML Creation
    int mInheritanceThreshold = 0;

    /// Uniform Distribution to filter mRandomInheritance to a value between 0 and 100
    std::uniform_real_distribution<> mDistribution = std::uniform_real_distribution<>(0, 100);

    /// Uniform Distribution to filter mRandomGood to a value between 0 and 100
    std::uniform_real_distribution<> mDistributionGood = std::uniform_real_distribution<>(0, 100);
public:
    Emitter(Game *game, std::shared_ptr<UMLData> data);
    void Create(double elapsed);
    void Emit(double good, double inheritance);
    std::shared_ptr<Inheritance> MakeInheritance(double good);
    std::shared_ptr<ClassUML> MakeClass(double good);

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
