/**
 * @file BadInheritanceTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <BadInheritance.h>
#include <Game.h>
#include <GoodClassUML.h>
#include <BadClassUML.h>

using namespace std;

TEST(BadInheritanceTest, Construct)
{
    Game game;
    auto name = make_shared<GoodUMLName>(L"");
    vector<shared_ptr<UMLAttribute>> attributes;
    vector<shared_ptr<UMLOperation>> operations;

    shared_ptr<GoodClassUML> goodUml1;
    goodUml1 = make_shared<GoodClassUML>(&game, name, attributes, operations);

    shared_ptr<GoodClassUML> goodUml2;
    goodUml2 = make_shared<GoodClassUML>(&game, name, attributes, operations);

    wstring reason = L"";
    bool down = false;

    BadInheritance inheritance(&game, goodUml1, goodUml2, reason, down);
}