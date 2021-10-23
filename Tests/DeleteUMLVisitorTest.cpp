/**
 * @file DeleteUMLVisitorTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <DeleteUMLVisitor.h>

TEST(DeleteUMLVisitorTest, DeleteUML)
{
    Game* game;

    std::shared_ptr<UMLName> name;
    std::vector<std::shared_ptr<UMLAttribute>> attributes;
    std::vector<std::shared_ptr<UMLOperation>> operations;

    std::shared_ptr<BadClassUML> badUml1 = std::make_shared<BadClassUML>(game, name, attributes, operations, L"");

    std::shared_ptr<BadClassUML> badUml2 = std::make_shared<BadClassUML>(game, name, attributes, operations, L"");

    std::shared_ptr<GoodClassUML> goodUml1 = std::make_shared<GoodClassUML>(game, name, attributes, operations);

    std::shared_ptr<GoodClassUML> goodUml2 = std::make_shared<GoodClassUML>(game, name, attributes, operations);

    DeleteUMLVisitor deleteVisitor;

    ASSERT_EQ(deleteVisitor.GetToDelete().size(), 0);

    badUml1->SetIsHit(true);
    goodUml2->SetIsHit(true);

    badUml1->SetTimeHit(1.1);
    goodUml2->SetTimeHit(0.8);

    badUml1->Accept(&deleteVisitor);
    badUml2->Accept(&deleteVisitor);
    goodUml1->Accept(&deleteVisitor);
    goodUml2->Accept(&deleteVisitor);

    ASSERT_EQ(deleteVisitor.GetToDelete().size(), 1);

    goodUml2->SetTimeHit(1);

    badUml2->Accept(&deleteVisitor);
    goodUml1->Accept(&deleteVisitor);
    goodUml2->Accept(&deleteVisitor);

    ASSERT_EQ(deleteVisitor.GetToDelete().size(), 2);
}

