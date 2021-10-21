/**
 * @file UMLData.h
 * @author Ian Byram
 *
 * Class to store the data from the uml.xml file
 */

#ifndef INC_335PROJECT1_UMLDATA_H
#define INC_335PROJECT1_UMLDATA_H

#include "GoodUMLName.h"
#include "BadUMLName.h"
#include "GoodUMLAttribute.h"
#include "BadUMLAttribute.h"
#include "GoodUMLOperation.h"
#include "BadUMLOperation.h"
#include "GoodInheritanceItem.h"
#include "BadInheritanceItem.h"
#include "GoodClassUML.h"
#include "BadClassUML.h"
#include "GoodInheritance.h"
#include "BadInheritance.h"
#include <wx/xml/xml.h>

class Game;

/**
 * Class to store the data from the uml.xml file
 */
class UMLData {
private:
    /// The list of good UML names
    std::vector<std::shared_ptr<GoodUMLName>> mGoodNames;

    /// The list of bad UML names
    std::vector<std::shared_ptr<BadUMLName>> mBadNames;

    /// The list of good UML attributes
    std::vector<std::shared_ptr<GoodUMLAttribute>> mGoodAttributes;

    /// The list of bad UML attributes
    std::vector<std::shared_ptr<BadUMLAttribute>> mBadAttributes;

    /// The list of good UML operations
    std::vector<std::shared_ptr<GoodUMLOperation>> mGoodOperations;

    /// The list of bad UML operations
    std::vector<std::shared_ptr<BadUMLOperation>> mBadOperations;

    /// The list of good inheritance relationships
    std::vector<std::shared_ptr<GoodInheritanceItem>> mGoodInheritances;

    /// The list of bad inheritance relationships
    std::vector<std::shared_ptr<BadInheritanceItem>> mBadInheritances;

    /// The game this data is stored in
    Game *mGame;

    void XmlName(wxXmlNode *node);
    void XmlAttribute(wxXmlNode *node);
    void XmlOperation(wxXmlNode *node);
    void XmlInheritance(wxXmlNode *node);

public:
    /// Default constructor (disabled)
    UMLData() = delete;

    /// Copy constructor (disabled)
    UMLData(const UMLData &) = delete;

    /// Assignment operator
    void operator=(const UMLData &) = delete;

    UMLData(Game *game);

    void LoadData(const std::wstring &filename);

    std::shared_ptr<GoodClassUML> GenerateGoodClassUML(std::wstring name = L"", bool partOfInheritance = false);

    std::shared_ptr<BadClassUML> GenerateBadClassUML();

    std::shared_ptr<GoodInheritance> GenerateGoodInheritance();

    std::shared_ptr<BadInheritance> GenerateBadInheritance();

    std::shared_ptr<BadClassUML> MakeUMLWithBadName(int numAttributes, int numOperations);

    std::shared_ptr<BadClassUML> MakeUMLWithBadAttribute(int numAttributes, int numOperations);

    std::shared_ptr<BadClassUML> MakeUMLWithBadOperation(int numAttributes, int numOperations);

    /**
     * Getter for the list of bad UML class names
     * @return the list of bad UML class names
     */
    std::vector<std::shared_ptr<BadUMLName>> GetBadNames() { return mBadNames; }

    /**
     * Getter for the list of good UML class names
     * @return the list of good UML class names
     */
    std::vector<std::shared_ptr<GoodUMLName>> GetGoodNames() { return mGoodNames; }

    /**
     * Getter for the list of bad UML class attributes
     * @return the list of bad UML class attributes
     */
    std::vector<std::shared_ptr<BadUMLAttribute>> GetBadAttributes() { return mBadAttributes; }

    /**
     * Getter for the list of good UML class attributes
     * @return the list of good UML class attributes
     */
    std::vector<std::shared_ptr<GoodUMLAttribute>> GetGoodAttributes() { return mGoodAttributes; }

    /**
     * Getter for the list of bad UML class operations
     * @return the list of bad UML class operations
     */
    std::vector<std::shared_ptr<BadUMLOperation>> GetBadOperations() { return mBadOperations; }

    /**
     * Getter for the list of good UML class operations
     * @return the list of good UML class operations
     */
    std::vector<std::shared_ptr<GoodUMLOperation>> GetGoodOperations() { return mGoodOperations; }

    /**
     * Getter for the list of good inheritances
     * @return the list of good inheritances
     */
    std::vector<std::shared_ptr<GoodInheritanceItem>> GetGoodInheritances() { return mGoodInheritances; }

    /**
     * Getter for the list of bad inheritances
     * @return the list of bad inheritances
     */
    std::vector<std::shared_ptr<BadInheritanceItem>> GetBadInheritances() { return mBadInheritances; }
};

#endif //INC_335PROJECT1_UMLDATA_H
