/**
 * @file UMLData.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "UMLData.h"

using namespace std;

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

                // If the umlChild information is bad store the reason, otherwise empty
                wstring badReason = umlChild->GetAttribute(L"bad").ToStdWstring();

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