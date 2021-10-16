/**
 * @file BadClassUMLTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <BadClassUML.h>
#include <Game.h>

using namespace std;

TEST(BadClassUMLTest, Construct)
{
    Game game;
    auto name = make_shared<GoodUMLName>(L"");
    vector<shared_ptr<UMLAttribute>> attributes;
    vector<shared_ptr<UMLOperation>> operations;
    wstring reason = L"";

    BadClassUML uml(&game, name, attributes, operations, reason);
}