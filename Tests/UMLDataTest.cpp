/**
 * @file UMLDataTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <UMLData.h>

using namespace std;

/// XML file to read the UML data from
const std::wstring Filename = L"data/uml.xml";

TEST(UMLDataTest, Constructor)
{
    UMLData data;
}

TEST(UMLDataTest, LoadFile)
{
    // Load the UML data
    UMLData data;
    data.LoadData(Filename);

    // Get the good and bad class names from the data
    std::vector<std::shared_ptr<BadUMLName>> badNames = data.GetBadNames();
    std::vector<std::shared_ptr<GoodUMLName>> goodNames = data.GetGoodNames();

    // Create a test list of what the bad UML name objects should be
    std::vector<std::shared_ptr<BadUMLName>> testBadNames;
    auto badName1 = make_shared<BadUMLName>(L"employer",L"Should be capitalized");
    auto badName2 = make_shared<BadUMLName>(L"",L"Missing class name");
    auto badName3 = make_shared<BadUMLName>(L"movie",L"Should be capitalized");
    auto badName4 = make_shared<BadUMLName>(L"Bank  Account",L"No spaces in names");

    testBadNames.push_back(badName1);
    testBadNames.push_back(badName2);
    testBadNames.push_back(badName3);
    testBadNames.push_back(badName4);

    // Check that each bad UML name object is what it should be
    for (int i=0; i < badNames.size(); i++)
    {
        wstring testBadName = testBadNames[i]->GetItem();
        wstring testBadNameReason = testBadNames[i]->GetReason();

        wstring badName = badNames[i]->GetItem();
        wstring badNameReason = badNames[i]->GetReason();

        ASSERT_EQ(badName, testBadName);
        ASSERT_EQ(badNameReason, testBadNameReason);
    }

    // Create a test list of what good UML name objects should be
    std::vector<std::shared_ptr<GoodUMLName>> testGoodNames;
    auto goodName1 = make_shared<GoodUMLName>(L"Employer");
    auto goodName2 = make_shared<GoodUMLName>(L"Timeline");
    auto goodName3 = make_shared<GoodUMLName>(L"Picture");
    auto goodName4 = make_shared<GoodUMLName>(L"Actor");

    testGoodNames.push_back(goodName1);
    testGoodNames.push_back(goodName2);
    testGoodNames.push_back(goodName3);
    testGoodNames.push_back(goodName4);

    // Check that each good UML name object is what it should be
    for (int i=0; i < badNames.size(); i++)
    {
        wstring testGoodName = testGoodNames[i]->GetItem();
        wstring goodName = goodNames[i]->GetItem();

        ASSERT_EQ(goodName, testGoodName);
    }

    // Get the good and bad class attributes from the data
    std::vector<std::shared_ptr<BadUMLAttribute>> badAttributes = data.GetBadAttributes();
    std::vector<std::shared_ptr<GoodUMLAttribute>> goodAttributes = data.GetGoodAttributes();

    // Create a test list of what the first 4 bad UML name objects should be
    std::vector<std::shared_ptr<BadUMLAttribute>> testBadAttributes;
    auto badAttribute1 = make_shared<BadUMLAttribute>(L"mAge: int",L"Language artifact");
    auto badAttribute2 = make_shared<BadUMLAttribute>(L"cofefe",L"Missing type");
    auto badAttribute3 = make_shared<BadUMLAttribute>(L"is  empty: boolean",L"No spaces in names");
    auto badAttribute4 = make_shared<BadUMLAttribute>(L"framerate: int",L"Use camelCase");

    testBadAttributes.push_back(badAttribute1);
    testBadAttributes.push_back(badAttribute2);
    testBadAttributes.push_back(badAttribute3);
    testBadAttributes.push_back(badAttribute4);

    // Check that the first 4 bad UML attribute object are what they should be
    for (int i=0; i < 4; i++)
    {
        wstring testBadAttribute = testBadAttributes[i]->GetItem();
        wstring testBadAttributeReason = testBadAttributes[i]->GetReason();

        wstring badAttribute = badAttributes[i]->GetItem();
        wstring badAttributeReason = badAttributes[i]->GetReason();

        ASSERT_EQ(badAttribute, testBadAttribute);
        ASSERT_EQ(badAttributeReason, testBadAttributeReason);
    }

    // Create a test list of what the first 4 bad UML name objects should be
    std::vector<std::shared_ptr<GoodUMLAttribute>> testGoodAttributes;
    auto goodAttribute1 = make_shared<GoodUMLAttribute>(L"age: int");
    auto goodAttribute2 = make_shared<GoodUMLAttribute>(L"location: string");
    auto goodAttribute3 = make_shared<GoodUMLAttribute>(L"description: string");
    auto goodAttribute4 = make_shared<GoodUMLAttribute>(L"time: double");

    testGoodAttributes.push_back(goodAttribute1);
    testGoodAttributes.push_back(goodAttribute2);
    testGoodAttributes.push_back(goodAttribute3);
    testGoodAttributes.push_back(goodAttribute4);

    // Check that the first 4 good UML attribute object are what they should be
    for (int i=0; i < 4; i++)
    {
        wstring testGoodAttribute = testGoodAttributes[i]->GetItem();
        wstring goodAttribute = goodAttributes[i]->GetItem();

        ASSERT_EQ(goodAttribute, testGoodAttribute);
    }

    // Get the good and bad class operations from the data
    std::vector<std::shared_ptr<BadUMLOperation>> badOperations = data.GetBadOperations();
    std::vector<std::shared_ptr<GoodUMLOperation>> goodOperations = data.GetGoodOperations();

    // Create a test list of what the bad UML operation objects should be
    std::vector<std::shared_ptr<BadUMLOperation>> testBadOperations;
    auto badOperation1 = make_shared<BadUMLOperation>(L"GetActors(): vector<Actor>",L"Language artifact");
    auto badOperation2 = make_shared<BadUMLOperation>(L"Draw(graphics)",L"Missing type");
    auto badOperation3 = make_shared<BadUMLOperation>(L"Launchrocket(): bool",L"Use camelCase");

    testBadOperations.push_back(badOperation1);
    testBadOperations.push_back(badOperation2);
    testBadOperations.push_back(badOperation3);

    // Check that the first 3 bad UML operation object are what they should be
    for (int i=0; i < 3; i++)
    {
        wstring testBadOperation = testBadOperations[i]->GetItem();
        wstring testBadOperationReason = testBadOperations[i]->GetReason();

        wstring badOperation = badOperations[i]->GetItem();
        wstring badOperationReason = badOperations[i]->GetReason();

        ASSERT_EQ(badOperation, testBadOperation);
        ASSERT_EQ(badOperationReason, testBadOperationReason);
    }

    // Create a test list of what good UML operations objects should be
    std::vector<std::shared_ptr<GoodUMLOperation>> testGoodOperations;
    auto goodOperation1 = make_shared<GoodUMLOperation>(L"Save(filename: string)");
    auto goodOperation2 = make_shared<GoodUMLOperation>(L"Load(filename: string)");
    auto goodOperation3 = make_shared<GoodUMLOperation>(L"Save(image: Image, filename: string)");

    testGoodOperations.push_back(goodOperation1);
    testGoodOperations.push_back(goodOperation2);
    testGoodOperations.push_back(goodOperation3);

    // Check that the first 3 good UML operation objects are what they should be
    for (int i=0; i < 3; i++)
    {
        wstring testGoodOperation = testGoodOperations[i]->GetItem();
        wstring goodOperation = goodOperations[i]->GetItem();

        ASSERT_EQ(goodOperation, testGoodOperation);
    }

    // Get the good and bad inheritances from the data
    std::vector<std::shared_ptr<BadInheritanceItem>> badInheritances = data.GetBadInheritances();
    std::vector<std::shared_ptr<GoodInheritanceItem>> goodInheritances = data.GetGoodInheritances();

    // Create a test list of what the bad inheritance objects should be
    std::vector<std::shared_ptr<BadInheritanceItem>> testBadInheritances;
    auto badInheritance1 = make_shared<BadInheritanceItem>(L"StinkyFish",L"Fish",L"Can't say 'is a'", false);
    auto badInheritance2 = make_shared<BadInheritanceItem>(L"Fish",L"StinkyFish",L"Upside down",true);
    auto badInheritance3 = make_shared<BadInheritanceItem>(L"Insect",L"Fruit",L"Can't say 'is a'", false);

    testBadInheritances.push_back(badInheritance1);
    testBadInheritances.push_back(badInheritance2);
    testBadInheritances.push_back(badInheritance3);

    // Check that the first 3 bad inheritance objects are what they should be
    for (int i=0; i < 3; i++)
    {
        wstring testBadInheritanceBase = testBadInheritances[i]->GetBase();
        wstring testBadInheritanceDerived = testBadInheritances[i]->GetDerived();
        wstring testBadInheritanceReason = testBadInheritances[i]->GetReason();
        bool testBadInheritanceDown = testBadInheritances[i]->IsDown();

        wstring badInheritanceBase = badInheritances[i]->GetBase();
        wstring badInheritanceDerived = badInheritances[i]->GetDerived();
        wstring badInheritanceReason = badInheritances[i]->GetReason();
        bool badInheritanceDown = badInheritances[i]->IsDown();

        ASSERT_EQ(badInheritanceBase, testBadInheritanceBase);
        ASSERT_EQ(badInheritanceDerived, testBadInheritanceDerived);
        ASSERT_EQ(badInheritanceReason, testBadInheritanceReason);
        ASSERT_EQ(badInheritanceDown, testBadInheritanceDown);
    }

    // Create a test list of what the good inheritance objects should be
    std::vector<std::shared_ptr<GoodInheritanceItem>> testGoodInheritances;
    auto goodInheritance1 = make_shared<GoodInheritanceItem>(L"Drawable",L"ImageDrawable");
    auto goodInheritance2 = make_shared<GoodInheritanceItem>(L"Employee",L"Manager");
    auto goodInheritance3 = make_shared<GoodInheritanceItem>(L"Fish",L"StinkyFish");

    testGoodInheritances.push_back(goodInheritance1);
    testGoodInheritances.push_back(goodInheritance2);
    testGoodInheritances.push_back(goodInheritance3);

    // Check that the first 3 good inheritance objects are what they should be
    for (int i=0; i < 3; i++)
    {
        wstring testGoodInheritanceBase = testGoodInheritances[i]->GetBase();
        wstring testGoodInheritanceDerived = testGoodInheritances[i]->GetDerived();

        wstring goodInheritanceBase = goodInheritances[i]->GetBase();
        wstring goodInheritanceDerived = goodInheritances[i]->GetDerived();

        ASSERT_EQ(goodInheritanceBase, testGoodInheritanceBase);
        ASSERT_EQ(goodInheritanceDerived, testGoodInheritanceDerived);
    }
}
