/**
 * @file VisitGoodUMLTest.cpp
 * @author Joe Getzen
 */
#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Item.h>
#include <ItemVisitor.h>
#include <ClassUML.h>
#include <GoodClassUML.h>
#include <BadClassUML.h>
#include <BadUMLVisitor.h>
#include <GoodInheritanceItem.h>
#include <BadInheritanceItem.h>


const std::wstring Filename = L"data/uml1.xml";

using namespace std;

class TestVisitor : public ItemVisitor
{
public:
    virtual void VisitGoodUML(GoodClassUML* goodUML) override { mIsBad=false; }

    virtual void VisitBadUML(BadClassUML* badUML) override { mIsBad=true; }

    bool mIsBad=false;

    bool IsBad() {return mIsBad;}
};

TEST(VisitBadUMLTest, Constructor)
{
   BadUMLVisitor real;
   TestVisitor test;
}

TEST(VisitBadUMLTest, VisitAccept)
{
    Game game;
    UMLData data(&game);
    data.LoadData(Filename);

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    BadUMLVisitor real;
    TestVisitor test;

    GoodClassUML GCUML(&game,name,attributes,operations);

    GCUML.Accept(&real);
    GCUML.Accept(&test);
}
TEST(VisitBadUMLTest, VisitIsGood)
{
    Game game;
    UMLData data(&game);
    data.LoadData(Filename);

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    BadUMLVisitor real;
    TestVisitor test;

    GoodClassUML GCUML(&game,name,attributes,operations);

    ASSERT_TRUE(!real.IsBad());
    ASSERT_TRUE(!test.IsBad());

    GCUML.Accept(&real);
    GCUML.Accept(&test);

    ASSERT_TRUE(!real.IsBad());
    ASSERT_TRUE(!test.IsBad());

    wstring reason;
    BadClassUML BCUML(&game,name,attributes,operations,reason);

    BadUMLVisitor realBad;
    TestVisitor testBad;

    ASSERT_TRUE(!realBad.IsBad());
    ASSERT_TRUE(!testBad.IsBad());

    BCUML.Accept(&realBad);
    BCUML.Accept(&testBad);

    ASSERT_TRUE(realBad.IsBad());
    ASSERT_TRUE(testBad.IsBad());

    GCUML.Accept(&realBad);
    GCUML.Accept(&testBad);

    ASSERT_TRUE(!realBad.IsBad());
    ASSERT_TRUE(!testBad.IsBad());

    BCUML.Accept(&realBad);
    BCUML.Accept(&testBad);

    ASSERT_TRUE((realBad.IsBad()));
    ASSERT_TRUE((testBad.IsBad()));
}

TEST(VisitBadUMLTest, VisitInheritance)
{
    Game game;
    UMLData data(&game);
    data.LoadData(Filename);

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    BadUMLVisitor real;

    std::shared_ptr<GoodClassUML> GoodUml= std::make_shared<GoodClassUML>(&game,name,attributes,operations);
    wstring reason;

    GoodInheritance goodInheritance(&game,GoodUml,GoodUml);
    BadInheritance badInheritance(&game, GoodUml, GoodUml, reason, false);

    ASSERT_FALSE(real.IsBad());
    goodInheritance.Accept(&real);
    ASSERT_TRUE(!real.IsBad());
    badInheritance.Accept(&real);
    ASSERT_FALSE(!real.IsBad());
    GoodUml->Accept(&real);
    ASSERT_TRUE(!real.IsBad());
}