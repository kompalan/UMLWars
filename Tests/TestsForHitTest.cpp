/**
 * @file TestsForHitTest.cpp
 * @author Joe Getzen
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <Pen.h>


TEST(HitTest, callHitTest)
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
}
TEST(HitTest, TestingHitTest)
{
    Game game;

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    std::shared_ptr<Pen> pen = std::make_shared<Pen>(&game);
    pen->SetLocation(0,100);
    std::shared_ptr<GoodClassUML> uml= std::make_shared<GoodClassUML>(&game,name,attributes,operations);
    uml->SetLocation(0,150);

    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(0,151);
    ASSERT_TRUE(!game.HitTest(pen,uml));
    uml->SetLocation(50,150);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(51,150);
    ASSERT_TRUE(!game.HitTest(pen,uml));
    uml->SetLocation(-50,150);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(-51,150);
    ASSERT_TRUE(!game.HitTest(pen,uml));
    uml->SetLocation(50,50);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(50,49);
    ASSERT_TRUE(!game.HitTest(pen,uml));
    uml->SetLocation(-50,50);
    ASSERT_TRUE(game.HitTest(pen,uml));
    uml->SetLocation(-50,49);
    ASSERT_TRUE(!game.HitTest(pen,uml));
}