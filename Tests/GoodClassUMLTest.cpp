/**
 * @file GoodClassUMLTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <GoodClassUML.h>
#include <Game.h>

using namespace std;

TEST(GoodClassUMLTest, Construct)
{
   Game game;
   wstring name;
   vector<shared_ptr<UMLAttribute>> attributes;
   vector<shared_ptr<UMLOperation>> operations;

   GoodClassUML uml(&game, name, attributes, operations);
}