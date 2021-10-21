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
#include <GoodInheritanceItem.h>
#include <BadInheritanceItem.h>


const std::wstring Filename = L"data/uml.xml";

using namespace std;

class TestVisitor : public ItemVisitor
{
public:
    virtual void VisitGoodUML(GoodClassUML* goodUML) override { mIsGood=true; }

    virtual void VisitBadUML(BadClassUML* badUML) override { mIsGood=false; }

    bool mIsGood=false;

    bool IsGood() {return mIsGood;}
};

TEST(VisitGoodUMLTest, Constructor)
{
   GoodUMLVisitor real;
   TestVisitor test;
}

TEST(VisitGoodUMLTest, VisitAccept)
{
    Game game;
    UMLData data(&game);
    data.LoadData(Filename);

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    GoodUMLVisitor real;
    TestVisitor test;

    GoodClassUML GCUML(&game,name,attributes,operations);

    GCUML.Accept(&real);
    GCUML.Accept(&test);
}
TEST(VisitGoodUMLTest, VisitIsGood)
{
    Game game;
    UMLData data(&game);
    data.LoadData(Filename);

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    GoodUMLVisitor real;
    TestVisitor test;

    GoodClassUML GCUML(&game,name,attributes,operations);

    ASSERT_TRUE(!real.IsGood());
    ASSERT_TRUE(!test.IsGood());

    GCUML.Accept(&real);
    GCUML.Accept(&test);

    ASSERT_TRUE(real.IsGood());
    ASSERT_TRUE(test.IsGood());

    wstring reason;
    BadClassUML BCUML(&game,name,attributes,operations,reason);

    GoodUMLVisitor realBad;
    TestVisitor testBad;

    ASSERT_TRUE(!realBad.IsGood());
    ASSERT_TRUE(!testBad.IsGood());

    BCUML.Accept(&realBad);
    BCUML.Accept(&testBad);

    ASSERT_TRUE(!realBad.IsGood());
    ASSERT_TRUE(!testBad.IsGood());

    GCUML.Accept(&realBad);
    GCUML.Accept(&testBad);

    ASSERT_TRUE(realBad.IsGood());
    ASSERT_TRUE(testBad.IsGood());

    BCUML.Accept(&realBad);
    BCUML.Accept(&testBad);

    ASSERT_TRUE(!(realBad.IsGood()));
    ASSERT_TRUE(!(testBad.IsGood()));
}
TEST(VisitGoodUMLTest, VisitInheritance)
{
    Game game;
    UMLData data(&game);
    data.LoadData(Filename);

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    GoodUMLVisitor real;

    std::shared_ptr<GoodClassUML> GoodUml= std::make_shared<GoodClassUML>(&game,name,attributes,operations);
    wstring reason;

    GoodInheritance goodInheritance(&game,GoodUml,GoodUml);
    BadInheritance badInheritance(&game, GoodUml, GoodUml, reason, false);

    ASSERT_FALSE(real.IsGood());
    goodInheritance.Accept(&real);
    ASSERT_TRUE(real.IsGood());
    badInheritance.Accept(&real);
    ASSERT_FALSE(real.IsGood());
    GoodUml->Accept(&real);
    ASSERT_TRUE(real.IsGood());
}