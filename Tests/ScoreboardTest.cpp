/**
 * @file ScoreboardTest.cpp
 * @author Joe Getzen
 */

#include <pch.h>
#include <iostream>
#include <Scoreboard.h>
#include <Game.h>
#include <wx/wx.h>
#include <WarsView.h>
#include <MainFrame.h>
#include "../UMLWarsApp.h"
#include "gtest/gtest.h"

TEST(ScoreboardTest, Constructor)
{
    Game game = Game();
    Scoreboard sb = Scoreboard(&game);
}

TEST(ScoreboardText, IncFunctions)
{
    Game game = Game();
    Scoreboard sb = Scoreboard(&game);
    sb.IncCorrect();
    ASSERT_TRUE(sb.GetCorrect()==1);
    sb.IncMissed();
    ASSERT_TRUE(sb.GetMissed()==1);
    sb.IncUnfair();
    ASSERT_TRUE(sb.GetUnfair()==1);
}

