/**
 * @file UMLData.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "UMLData.h"
#include "Game.h"
#include <algorithm>
#include <random>

using namespace std;

/// Minimum number of attributes in a UML object
const int MinAttributes = 0;

/// Maximum number of attributes in a UML object
const int MaxAttributes = 3;

/// Minimum number of operations in a UML object
const int MinOperations = 0;

/// Maximum number of operations in a UML object
const int MaxOperations = 3;

/// Message to Display when we hit a good UML
const wstring GoodUMLMessage = L"Unfair!";

/**
 * Constructor
 * @param game The game the UMLData is stored in
 */
UMLData::UMLData(Game* game) : mGame(game)
{

}

/**
 * Load the contents of an xml file into a UMLData object
 * @param filename The name of the file the data will be loaded from
 */
void UMLData::LoadData(const std::wstring &filename)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load UML file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    // Traverse the children of the root node
    auto child = root->GetChildren();
    for ( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if (name == L"class" || name == L"inheritance")
        {
            // Traverse each child of the root node's children
            auto umlChild = child->GetChildren();
            for ( ; umlChild; umlChild=umlChild->GetNext())
            {
                auto umlChildName = umlChild->GetName();

                // Determine the type of uml class item
                if (umlChildName == L"name")
                {
                    XmlName(umlChild);
                }
                else if (umlChildName == L"attribute")
                {
                    XmlAttribute(umlChild);
                }
                else if (umlChildName == L"operation")
                {
                    XmlOperation(umlChild);
                }
                else if (umlChildName == L"inherit")
                {
                    XmlInheritance(umlChild);
                }
            }
        }
    }
}

/**
 * Handle a node of type name
 * @param node XML node
 */
void UMLData::XmlName(wxXmlNode *node)
{
    // The uml class name
    wstring name = node->GetNodeContent().ToStdWstring();

    // If the uml name is bad store the reason, otherwise empty
    wstring badReason = node->GetAttribute(L"bad").ToStdWstring();

    // Determine if the uml class name is good or bad
    if (badReason != L"")
    {
        auto umlName = make_shared<BadUMLName>(name, badReason);
        mBadNames.push_back(umlName);
    }
    else
    {
        auto umlName = make_shared<GoodUMLName>(name);
        mGoodNames.push_back(umlName);
    }
}

/**
 * Handle a node of type attribute
 * @param node XML node
 */
void UMLData::XmlAttribute(wxXmlNode *node)
{
    // The uml class name
    wstring attribute = node->GetNodeContent().ToStdWstring();

    // If the uml name is bad store the reason, otherwise empty
    wstring badReason = node->GetAttribute(L"bad").ToStdWstring();

    // Determine if the uml class attribute is good or bad
    if (badReason != L"")
    {
        auto umlAttribute = make_shared<BadUMLAttribute>(attribute, badReason);
        mBadAttributes.push_back(umlAttribute);
    }
    else
    {
        auto umlAttribute = make_shared<GoodUMLAttribute>(attribute);
        mGoodAttributes.push_back(umlAttribute);
    }
}

/**
 * Handle a node of type operation
 * @param node XML node
 */
void UMLData::XmlOperation(wxXmlNode *node)
{
    // The uml class name
    wstring operation = node->GetNodeContent().ToStdWstring();

    // If the uml name is bad store the reason, otherwise empty
    wstring badReason = node->GetAttribute(L"bad").ToStdWstring();

    // Determine if the uml class operation is good or bad
    if (badReason != L"")
    {
        auto umlOperation = make_shared<BadUMLOperation>(operation, badReason);
        mBadOperations.push_back(umlOperation);
    }
    else
    {
        auto umlOperation = make_shared<GoodUMLOperation>(operation);
        mGoodOperations.push_back(umlOperation);
    }
}

/**
 * Handle a node of type inheritance
 * @param node XML node
 */
void UMLData::XmlInheritance(wxXmlNode *node)
{
    // The base and derived classes for the inheritance relationship
    wstring base = node->GetAttribute(L"base").ToStdWstring();
    wstring derived = node->GetAttribute(L"derived").ToStdWstring();

    wstring badReason = node->GetAttribute(L"bad").ToStdWstring();

    // Determine if the uml inheritance is good or bad
    if (badReason != L"")
    {
        // Determine if the inheritance is upside down
        if (node->GetAttribute(L"direction") != L"")
        {
            auto umlInheritance = make_shared<BadInheritanceItem>(base, derived, badReason, true);
            mBadInheritances.push_back(umlInheritance);
        }
        else
        {
            auto umlInheritance = make_shared<BadInheritanceItem>(base, derived, badReason, false);
            mBadInheritances.push_back(umlInheritance);
        }
    }
    else
    {
        auto umlInheritance = make_shared<GoodInheritanceItem>(base, derived);
        mGoodInheritances.push_back(umlInheritance);
    }
}

/**
 * Creates a good class UML object
 * @param name optional name to make the good class UML with
 * @return a good class UML object
 */
shared_ptr<GoodClassUML> UMLData::GenerateGoodClassUML(std::wstring name)
{
    // Random number distribution between the min and max number of attributes for a UML object
    std::uniform_int_distribution<> DistributionAttributes(MinAttributes, MaxAttributes);

    // Random number distribution between the min and max number of operations for a UML object
    std::uniform_int_distribution<> DistributionOperations(MinOperations, MaxOperations);

    auto umlName = make_shared<GoodUMLName>(name);

    // Select a random name from the list of good names if one is not provided
    if (name == L"")
    {
        shuffle(mGoodNames.begin(), mGoodNames.end(), mGame->GetRandom());
        umlName = mGoodNames[0];
    }

    vector<shared_ptr<UMLAttribute>> attributes; //< Create empty list of attributes

    // Shuffle list of good attributes and pick a random number between the min and max number of items
    shuffle(mGoodAttributes.begin(), mGoodAttributes.end(), mGame->GetRandom());
    int numAttributes = DistributionAttributes(mGame->GetRandom());

    // Push random number of attributes from good attributes list onto attributes
    for (int i=0; i < numAttributes; i++)
    {
        attributes.push_back(mGoodAttributes[i]);
    }

    vector<shared_ptr<UMLOperation>> operations; //< Create empty list of operations

    // Shuffle list of good operations and pick a random number between the min and max number of items
    shuffle(mGoodOperations.begin(), mGoodOperations.end(), mGame->GetRandom());
    int numOperations = DistributionOperations(mGame->GetRandom());

    // Push random number of operations from good operations list onto operations
    for (int i=0; i < numOperations; i++)
    {
        operations.push_back(mGoodOperations[i]);
    }

    // Make a good class UML object from the selected name, attributes, and operations
    auto goodUml = make_shared<GoodClassUML>(mGame, umlName, attributes, operations);

    // Set the display message for the UML
    goodUml->SetMessage(GoodUMLMessage);

    return goodUml;
}

/**
 * Creates a bad class UML object
 * @return a bad class UML object
 */
std::shared_ptr<BadClassUML> UMLData::GenerateBadClassUML()
{
    // Random number distribution between the min and max number of attributes for a UML object
    std::uniform_int_distribution<> DistributionAttributes(MinAttributes, MaxAttributes);

    // Random number distribution between the min and max number of operations for a UML object
    std::uniform_int_distribution<> DistributionOperations(MinOperations, MaxOperations);

    // Random number distribution between 0 and 1 which correspond to two choices
    std::uniform_int_distribution<> DistributionTwoChoices(0,1);

    // Random number distribution between 0 and 2 which correspond to three choices
    std::uniform_int_distribution<> DistributionThreeChoices(0,2);

    int numAttributes = DistributionAttributes(mGame->GetRandom()); //< Pick random number of attributes
    int numOperations = DistributionOperations(mGame->GetRandom()); //< Pick random number of operations

    // Create an empty bad class UML object which will be assigned later
    shared_ptr<BadClassUML> badUml;

    // Integer representing a choice that will be used in switch statements to create a certain type of bad class UML
    int choice;

    // Conditional statements to determine the possible ways the class UML can be bad.
    // For example, if the number of attributes is 0, then the class UML can't be bad due to a bad attribute.
    if (numAttributes > 0 && numOperations > 0)
    {
        // Choice which will determine if the class is bad because of a bad name, attribute or operation
        choice = DistributionThreeChoices(mGame->GetRandom());

        // Generates a bad class UML by calling a specific function based on the randomly generated choice.
        // Case 0 corresponds to a bad name, case 1 to a bad attribute, and case 2 to a bad operation.
        switch (choice)
        {
        case 0:
            badUml = MakeUMLWithBadName(numAttributes, numOperations);
            break;
        case 1:
            badUml = MakeUMLWithBadAttribute(numAttributes, numOperations);
            break;
        case 2:
            badUml = MakeUMLWithBadOperation(numAttributes, numOperations);
        }
    }
    else if (numAttributes > 0)
    {
        // Choice which will determine if the class is bad because of a bad name or attribute
        choice = DistributionTwoChoices(mGame->GetRandom());

        // Generates a bad class UML by calling a specific function based on the randomly generated choice.
        // Case 0 corresponds to a bad name and case 1 to a bad attribute.
        switch (choice)
        {
        case 0:
            badUml = MakeUMLWithBadName(numAttributes, numOperations);
            break;
        case 1:
            badUml = MakeUMLWithBadAttribute(numAttributes, numOperations);
        }
    }
    else if (numOperations > 0)
    {
        // Choice which will determine if the class is bad because of a bad name or attribute
        choice = DistributionTwoChoices(mGame->GetRandom());

        // Generates a bad class UML by calling a specific function based on the randomly generated choice.
        // Case 0 corresponds to a bad name and case 1 to a bad operation.
        switch (choice)
        {
        case 0:
            badUml = MakeUMLWithBadName(numAttributes, numOperations);
            break;
        case 1:
            badUml = MakeUMLWithBadOperation(numAttributes, numOperations);
        }
    }
    else
    {
        // Generates a bad class UML with a bad name because there are no attributes or operations in the class
        badUml = MakeUMLWithBadName(numAttributes, numOperations);
    }

    // Set the display message for the UML
    badUml->SetMessage(badUml->GetReason());

    return badUml;
}

/**
 * Creates a good inheritance object
 * @return a good inheritance object
 */
std::shared_ptr<GoodInheritance> UMLData::GenerateGoodInheritance()
{
    // Shuffle the list of good inheritance relationships
    shuffle(mGoodInheritances.begin(), mGoodInheritances.end(), mGame->GetRandom());
    auto inheritance = mGoodInheritances[0];

    // Create two good UML classes to be the base and derived classes of the inheritance
    // Make the second parameter true to indicate that the generated classes are part of an inheritance
    shared_ptr<GoodClassUML> baseClass = GenerateGoodClassUML(inheritance->GetBase());
    shared_ptr<GoodClassUML> derivedClass = GenerateGoodClassUML(inheritance->GetDerived());

    // Make a good inheritance object from the created base and derived classes
    auto goodInheritance = make_shared<GoodInheritance>(mGame, baseClass, derivedClass);

    // Set the display message for the UML
    goodInheritance->SetMessage(GoodUMLMessage);

    return goodInheritance;
}

/**
 * Creates a bad inheritance object
 * @return a bad inheritance object
 */
std::shared_ptr<BadInheritance> UMLData::GenerateBadInheritance()
{
    // Shuffle the list of good inheritance relationships
    shuffle(mBadInheritances.begin(), mBadInheritances.end(), mGame->GetRandom());
    auto inheritance = mBadInheritances[0];

    // Create two good UML classes to be the base and derived classes of the inheritance
    // Make the second parameter true to indicate that the generated classes are part of an inheritance
    shared_ptr<GoodClassUML> baseClass = GenerateGoodClassUML(inheritance->GetBase());
    shared_ptr<GoodClassUML> derivedClass = GenerateGoodClassUML(inheritance->GetDerived());


    wstring reason = inheritance->GetReason(); //< get the reason the inheritance is bad
    bool down = inheritance->IsDown(); //< get if the inheritance is upside down

    // Make a bad inheritance object from the created base and derived classes
    auto badInheritance = make_shared<BadInheritance>(mGame, baseClass, derivedClass, reason, down);

    // Set the display message for the UML
    badInheritance->SetMessage(badInheritance->GetReason());

    return badInheritance;
}

/**
 * Creates a bad class UML object with bad UML name
 * @param numAttributes the number of attributes of the bad class UML
 * @param numOperations the number of operations of the bad class UML
 * @return a bad class UML object with a bad name
 */
std::shared_ptr<BadClassUML> UMLData::MakeUMLWithBadName(int numAttributes, int numOperations)
{
    // Shuffle the list of bad UML names to avoid repeats
    shuffle(mBadNames.begin(), mBadNames.end(), mGame->GetRandom());

    // Assign the bad UML name and its corresponding reason for being bad
    auto name = mBadNames[0];
    wstring reason = name->GetReason();

    vector<shared_ptr<UMLAttribute>> attributes; //< Empty list of attributes to push attributes onto

    // Shuffle the list of good UML attributes to avoid repeats
    shuffle(mGoodAttributes.begin(), mGoodAttributes.end(), mGame->GetRandom());

    // Push random number of attributes from good attributes list onto attributes
    for (int i = 0; i < numAttributes; i++)
    {
        attributes.push_back(mGoodAttributes[i]);
    }

    vector<shared_ptr<UMLOperation>> operations; //< Create an empty list of operations to push operations onto

    // Shuffle the list of good UML operations to avoid repeats
    shuffle(mGoodOperations.begin(), mGoodOperations.end(), mGame->GetRandom());

    // Push random number of operations from good operations list onto operations
    for (int i = 0; i < numOperations; i++)
    {
        operations.push_back(mGoodOperations[i]);
    }

    // Create the bad class UML object with a name, lists of attributes and operations, and a reason for being bad
    auto badUml = make_shared<BadClassUML>(mGame, name, attributes, operations, reason);

    return badUml;
}

/**
 * Creates a bad class UML object with bad UML attribute
 * @param numAttributes the number of attributes of the bad class UML
 * @param numOperations the number of operations of the bad class UML
 * @return a bad class UML object with a bad attribute
 */
std::shared_ptr<BadClassUML> UMLData::MakeUMLWithBadAttribute(int numAttributes, int numOperations)
{
    // Shuffle the list of good UML names to avoid repeats
    shuffle(mGoodNames.begin(), mGoodNames.end(), mGame->GetRandom());
    auto name = mGoodNames[0];

    vector<shared_ptr<UMLAttribute>> attributes; //< Empty list of attributes to push attributes onto

    // Shuffle the list of bad UML attributes to avoid repeats
    shuffle(mBadAttributes.begin(), mBadAttributes.end(), mGame->GetRandom());

    // Push the first bad attribute onto the attributes list and assign the corresponding reason for being bad
    attributes.push_back(mBadAttributes[0]);
    wstring reason = mBadAttributes[0]->GetReason();

    // Shuffle the list of good attributes to avoid repeats
    shuffle(mGoodAttributes.begin(), mGoodAttributes.end(), mGame->GetRandom());

    // Fill the remaining number of attributes in the class object with good attributes
    for (int i=0; i < numAttributes-1; i++)
    {
        attributes.push_back(mGoodAttributes[i]);
    }

    vector<shared_ptr<UMLOperation>> operations; //< Empty list of operations to push operations onto

    // Shuffle the list of good UML operations to avoid repeats
    shuffle(mGoodOperations.begin(), mGoodOperations.end(), mGame->GetRandom());

    // Push random number of operations from good operations list onto operations
    for (int i=0; i < numOperations; i++)
    {
        operations.push_back(mGoodOperations[i]);
    }

    // Shuffle the list of attributes so the bad attribute isn't always at the front of the list
    shuffle(attributes.begin(), attributes.end(), mGame->GetRandom());

    // Create the bad class UML object with a name, lists of attributes and operations, and a reason for being bad
    auto badUml = make_shared<BadClassUML>(mGame, name, attributes, operations, reason);

    return badUml;
}

/**
 * Creates a bad class UML object with bad UML operation
 * @param numAttributes the number of attributes of the bad class UML
 * @param numOperations the number of operations of the bad class UML
 * @return a bad class UML object with a bad operation
 */
std::shared_ptr<BadClassUML> UMLData::MakeUMLWithBadOperation(int numAttributes, int numOperations)
{
    // Shuffle the list of good UML names to avoid repeats
    shuffle(mGoodNames.begin(), mGoodNames.end(), mGame->GetRandom());
    auto name = mGoodNames[0];

    vector<shared_ptr<UMLAttribute>> attributes; //< Empty list of attributes to push attributes onto

    // Shuffle the list of good UML attributes to avoid repeats
    shuffle(mGoodAttributes.begin(), mGoodAttributes.end(), mGame->GetRandom());

    // Push random number of attributes from good attributes list onto attributes
    for (int i=0; i < numAttributes; i++)
    {
        attributes.push_back(mGoodAttributes[i]);
    }

    // Shuffle the list of bad UML operations to avoid repeats
    shuffle(mBadAttributes.begin(), mBadAttributes.end(), mGame->GetRandom());

    vector<shared_ptr<UMLOperation>> operations; //< Empty list of operations to push operations onto

    // Push the first bad operation onto the operations list and assign the corresponding reason for being bad
    operations.push_back(mBadOperations[0]);
    wstring reason = mBadOperations[0]->GetReason();

    // Shuffle the list of good UML operations to avoid repeats
    shuffle(mGoodOperations.begin(), mGoodOperations.end(), mGame->GetRandom());

    // Fill the remaining number of operations in the class object with good operations
    for (int i=0; i < numOperations-1; i++)
    {
        operations.push_back(mGoodOperations[i]);
    }

    // Shuffle the list of operations so the bad operation isn't always at the front of the list
    shuffle(operations.begin(), operations.end(), mGame->GetRandom());

    // Create the bad class UML object with a name, lists of attributes and operations, and a reason for being bad
    auto badUml = make_shared<BadClassUML>(mGame, name, attributes, operations, reason);

    return badUml;
}