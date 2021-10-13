/**
 * @file UMLDataTest.cpp
 * @author Ian Byram
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <UMLData.h>

using namespace std;

TEST(UMLDataTest, LoadFile)
{
    // Load the UML data
    UMLData data;
    data.LoadData();

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
        wstring testBadReason = testBadNames[i]->GetReason();
        wstring badName = badNames[i]->GetItem();
        wstring badReason = badNames[i]->GetReason();

        ASSERT_EQ(badName, testBadName);
        ASSERT_EQ(badReason, testBadReason);
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
}
