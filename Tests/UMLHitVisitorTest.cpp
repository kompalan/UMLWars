/**
 * @file UMLHitVisitorTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <UMLHitVisitor.h>

TEST(UMLHitVisitorTest, UMLHit)
{
    Game* game;

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    std::shared_ptr<BadClassUML> badUml1 = std::make_shared<BadClassUML>(game, name, attributes, operations, L"");

    std::shared_ptr<BadClassUML> badUml2 = std::make_shared<BadClassUML>(game, name, attributes, operations, L"");

    std::shared_ptr<GoodClassUML> goodUml1 = std::make_shared<GoodClassUML>(game, name, attributes, operations);

    std::shared_ptr<GoodClassUML> goodUml2 = std::make_shared<GoodClassUML>(game, name, attributes, operations);

    UMLHitVisitor hitVisitor;

    badUml1->Accept(&hitVisitor);
    goodUml2->Accept(&hitVisitor);

    ASSERT_TRUE(badUml1->IsHit());
    ASSERT_FALSE(badUml2->IsHit());
    ASSERT_FALSE(goodUml1->IsHit());
    ASSERT_TRUE(goodUml2->IsHit());

}
