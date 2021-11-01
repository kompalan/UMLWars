/**
 * @file TestsForHitTest.cpp
 * @author Joe Getzen
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <Pen.h>
#include <TA.h>


TEST(GameTest, HitTest)
{
    Game game;

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    std::shared_ptr<Pen> pen = std::make_shared<Pen>(&game);
    pen->SetLocation(0,100);
    std::shared_ptr<GoodClassUML> uml= std::make_shared<GoodClassUML>(&game,name,attributes,operations);
    uml->SetHeight(20); //< Set UML height for testing
    uml->SetWidth(100); //< Set UML width for testing
    pen->ThrowPen();
    std::cout<<(pen->GetHeight())<<"\n";
    std::cout<<(pen->GetWidth())<<"\n";
    //Pen height is 7, Width is 50
    ASSERT_TRUE(pen->IsThrown());
    uml->SetLocation(0,100);
    ASSERT_TRUE(game.HitTest(pen.get(),uml));
    uml->SetLocation(0,105);
    ASSERT_TRUE(game.HitTest(pen.get(),uml));
    uml->SetLocation(0,111);
    ASSERT_TRUE(!game.HitTest(pen.get(),uml));
    uml->SetLocation(5,105);
    ASSERT_TRUE(game.HitTest(pen.get(),uml));
    uml->SetLocation(100,105);
    ASSERT_TRUE(!game.HitTest(pen.get(),uml));
    uml->SetLocation(0,105);
    ASSERT_TRUE(game.HitTest(pen.get(),uml));
    uml->SetLocation(-51,110);
    ASSERT_TRUE(!game.HitTest(pen.get(),uml));
    uml->SetLocation(50,90);
    ASSERT_TRUE(game.HitTest(pen.get(),uml));
    uml->SetLocation(50,75);
    ASSERT_TRUE(!game.HitTest(pen.get(),uml));
    uml->SetLocation(-75,89);
    ASSERT_TRUE(game.HitTest(pen.get(),uml));
    uml->SetLocation(-76,89);
    ASSERT_TRUE(!game.HitTest(pen.get(),uml));
}
TEST(GameTest, TAHitTest)
{
    Game game;

    std::shared_ptr<Pen> pen = std::make_shared<Pen>(&game);
    pen->SetLocation(0,400);
    pen->ThrowPen();

    std::shared_ptr<TA> ta = std::make_shared<TA>(&game);
    ta->SetLocation(0,400);

    std::cout<<(ta->GetX())<<"\n";
    std::cout<<(ta->GetY())<<"\n";
    std::cout<<(ta->GetHeight())<<"\n";
    std::cout<<(ta->GetWidth())<<"\n";

    ta->SetSpawned();
    ASSERT_TRUE(ta->IsSpawned());

    ASSERT_TRUE(game.HitTest(pen.get(),ta));
    pen->SetLocation(0,460);
    ASSERT_TRUE(game.HitTest(pen.get(),ta));
}