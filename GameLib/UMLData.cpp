/**
 * @file UMLData.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "UMLData.h"

using namespace std;

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
 * @return a good class UML object
 */
shared_ptr<GoodClassUML> UMLData::GenerateGoodClassUML()
{
    auto name = make_shared<GoodUMLName>(L"");
    vector<shared_ptr<UMLAttribute>> attributes;
    vector<shared_ptr<UMLOperation>> operations;

    return make_shared<GoodClassUML>(mGame, name, attributes, operations);
}

/**
 * Creates a bad class UML object
 * @return a bad class UML object
 */
std::shared_ptr<BadClassUML> UMLData::GenerateBadClassUML()
{
    auto name = make_shared<GoodUMLName>(L"");
    vector<shared_ptr<UMLAttribute>> attributes;
    vector<shared_ptr<UMLOperation>> operations;
    wstring reason = L"";

    return make_shared<BadClassUML>(mGame, name, attributes, operations, reason);
}

/**
 * Creates a good inheritance object
 * @return a good inheritance object
 */
std::shared_ptr<GoodInheritance> UMLData::GenerateGoodInheritance()
{
    shared_ptr<GoodClassUML> goodUml1 = GenerateGoodClassUML();
    shared_ptr<GoodClassUML> goodUml2 = GenerateGoodClassUML();

    return make_shared<GoodInheritance>(mGame, goodUml1, goodUml2);
}

/**
 * Creates a bad inheritance object
 * @return a bad inheritance object
 */
std::shared_ptr<BadInheritance> UMLData::GenerateBadInheritance()
{
    std::shared_ptr<GoodClassUML> goodUml1 = GenerateGoodClassUML();
    std::shared_ptr<GoodClassUML> goodUml2 = GenerateGoodClassUML();

    wstring reason = L"";
    bool down;

    return make_shared<BadInheritance>(mGame, goodUml1, goodUml2, reason, down);
}