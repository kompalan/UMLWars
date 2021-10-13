/**
 * @file UMLData.cpp
 * @author Ian Byram
 */

#include "pch.h"
#include "UMLData.h"

using namespace std;

/// File name to load UML data from
const wstring FileName = L"data/uml.xml";

/**
 * Load the contents of an xml file into a UMLData object
 */
void UMLData::LoadData()
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(FileName))
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
        if (name == L"class" || name == L"inherit")
        {
            // Traverse each child of the root node's children
            auto umlChild = child->GetChildren();
            for ( ; umlChild; umlChild=umlChild->GetNext())
            {
                auto umlChildName = umlChild->GetName();

                // If the umlChild information is bad store the reason, otherwise empty
                auto badReason = umlChild->GetAttribute(L"bad");

                // Determine the type of uml class item
                if (umlChildName == L"name")
                {
                    // Determine if the uml class name is good or bad
                    if (badReason != L"")
                    {
                        auto umlName = make_shared<BadUMLName>(umlChild->GetNodeContent().ToStdWstring(),
                                badReason.ToStdWstring());
                        mBadNames.push_back(umlName);
                    }
                    else
                    {
                        auto umlName = make_shared<GoodUMLName>(umlChild->GetNodeContent().ToStdWstring());
                        mGoodNames.push_back(umlName);
                    }
                }
                else if (umlChildName == L"attribute")
                {
                    // Determine if the uml class attribute is good or bad
                    if (badReason != L"")
                    {
                        auto umlAttribute = make_shared<BadUMLAttribute>(umlChild->GetNodeContent().ToStdWstring(),
                                badReason.ToStdWstring());
                        mBadAttributes.push_back(umlAttribute);
                    }
                    else
                    {
                        auto umlAttribute = make_shared<GoodUMLAttribute>(umlChild->GetNodeContent().ToStdWstring());
                        mGoodAttributes.push_back(umlAttribute);
                    }
                }
            }
        }
    }
}

