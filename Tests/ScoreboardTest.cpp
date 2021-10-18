/**
 * @file ScoreboardTest.cpp
 * @author Joe Getzen
 */

#include <pch.h>
#include <iostream>
#include <Scoreboard.h>
#include <Game.h>
#include <gtest/gtest.h>


TEST(ScoreboardTest, Constructor)
{
    Scoreboard sb = Scoreboard();
}

TEST(ScoreboardText, IncFunctions)
{
    Scoreboard sb = Scoreboard();
    sb.IncCorrect();
    ASSERT_TRUE(sb.GetCorrect()==1);
    sb.IncMissed();
    ASSERT_TRUE(sb.GetMissed()==1);
    sb.IncUnfair();
    ASSERT_TRUE(sb.GetUnfair()==1);
}

