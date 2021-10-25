/**
 * @file UMLTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <UML.h>

TEST(UMLTest, CheckOnScreen)
{
    Game* game;

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    std::shared_ptr<GoodClassUML> uml = std::make_shared<GoodClassUML>(game, name, attributes, operations);

    ASSERT_TRUE(uml->CheckOnScreen());

    uml->SetLocation(-625,0);
    ASSERT_TRUE(uml->CheckOnScreen());

    uml->SetLocation(-626,0);
    ASSERT_FALSE(uml->CheckOnScreen());

    uml->SetLocation(625,0);
    ASSERT_TRUE(uml->CheckOnScreen());

    uml->SetLocation(626,1000);
    ASSERT_FALSE(uml->CheckOnScreen());

    uml->SetLocation(0,1000);
    ASSERT_TRUE(uml->CheckOnScreen());

    uml->SetLocation(0,1001);
    ASSERT_FALSE(uml->CheckOnScreen());

    uml->SetLocation(0,-1);
    ASSERT_FALSE(uml->CheckOnScreen());

}
 
