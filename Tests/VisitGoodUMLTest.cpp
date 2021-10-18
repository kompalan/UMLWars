/**
 * @file VisitGoodUMLTest.cpp
 * @author Joe Getzen
 */
#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <ItemVisitor.h>
#include <UML.h>
#include <GoodClassUML.h>
#include <BadClassUML.h>
#include <GoodUMLVisitor.h>

using namespace std;

class TestVisitor : public ItemVisitor
{
public:
    virtual void VisitGoodUML(GoodClassUML* goodUML) override { mIsGood=true; }

    bool mIsGood=false;
};

TEST(VisitGoodUMLTest, Constructor)
{
   GoodUMLVisitor real;
   TestVisitor test;
}
