/**
 * @file HaroldTest.cpp
 * @author Anurag Kompalli
 */
#include <pch.h>
#include "gtest/gtest.h"
#include <Harold.h>
#include <Game.h>

/// Harold Filename
const std::wstring HaroldImageName = L"images/harold.png";

TEST(HaroldTest, Construct)
{
    Game game = Game();
    Harold harold = Harold(&game);
}

TEST(HaroldTest, MouseMove)
{
    Game game = Game();
    Harold harold = Harold(&game);

    harold.HandleMouseMove(0, 0);
    double rotation = harold.GetRotation();
    double expected = atan2(0 - harold.GetY(), 0 - harold.GetX()) + 1.078;
    ASSERT_NEAR(rotation, expected, 0.001);

    harold.HandleMouseMove(0, 1200);
    rotation = harold.GetRotation();
    expected = atan2(1200 - harold.GetY(), 0 - harold.GetX()) + 1.078;
    ASSERT_NEAR(rotation, expected, 0.001);
}