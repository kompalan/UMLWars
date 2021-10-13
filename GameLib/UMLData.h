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

public:
    void LoadData();

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
};

#endif //INC_335PROJECT1_UMLDATA_H
