/**
 * @file GoodInheritanceTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <GoodInheritance.h>
#include <Game.h>
#include <GoodClassUML.h>
#include <BadClassUML.h>

using namespace std;

TEST(GoodInheritanceTest, Construct)
{
    Game game;
    wstring name = L"";
    vector<shared_ptr<UMLAttribute>> attributes;
    vector<shared_ptr<UMLOperation>> operations;

    shared_ptr<GoodClassUML> goodUml1;
    goodUml1 = make_shared<GoodClassUML>(&game, name, attributes, operations);

    shared_ptr<GoodClassUML> goodUml2;
    goodUml2 = make_shared<GoodClassUML>(&game, name, attributes, operations);

    GoodInheritance inheritance(&game, goodUml1, goodUml2);
}