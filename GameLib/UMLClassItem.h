/**
 * @file UMLClassItem.h
 * @author Ian Byram
 *
 * Base class for any UML class items
 */

#ifndef INC_335PROJECT1_UMLCLASSITEM_H
#define INC_335PROJECT1_UMLCLASSITEM_H

/**
 * Base class for any UML class items
 */
class UMLClassItem {
private:
    /// The UML class item
    std::wstring mItem;

protected:
    /**
     * Constructor
     * @param item the UML class item
     */
    UMLClassItem(std::wstring item) { mItem = item; }
public:
    /// Default constructor (disabled)
    UMLClassItem() = delete;

    /// Copy constructor (disabled)
    UMLClassItem(const UMLClassItem &) = delete;

    /// Assignment operator
    void operator=(const UMLClassItem &) = delete;

    /**
     * Getter for the UML class item
     * @return the UML class item
     */
     std::wstring GetItem() { return mItem; }
};

#endif //INC_335PROJECT1_UMLCLASSITEM_H
