/**
 * @file TestsForHitTest.cpp
 * @author Joe Getzen
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <Pen.h>


TEST(GameTest, HitTest)
{
    Game game;

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    std::shared_ptr<Pen> pen = std::make_shared<Pen>(&game);
    pen->SetLocation(0,100);
    std::shared_ptr<GoodClassUML> uml= std::make_shared<GoodClassUML>(&game,name,attributes,operations);

    uml->SetLocation(0,100);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(0,110);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(0,111);
    ASSERT_TRUE(!game.HitTest(pen,uml));
    uml->SetLocation(50,110);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(51,110);
    ASSERT_TRUE(!game.HitTest(pen,uml));
    uml->SetLocation(-50,110);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(-51,110);
    ASSERT_TRUE(!game.HitTest(pen,uml));
    uml->SetLocation(50,90);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(50,89);
    ASSERT_TRUE(!game.HitTest(pen,uml));
    uml->SetLocation(-50,90);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(-50,89);
    ASSERT_TRUE(!game.HitTest(pen,uml));
}