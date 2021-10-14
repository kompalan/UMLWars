/**
 * @file UMLInheritanceItem.h
 * @author Ian Byram
 *
 * Base class for inheritance relationships
 */

#ifndef INC_335PROJECT1_UMLINHERITANCEITEM_H
#define INC_335PROJECT1_UMLINHERITANCEITEM_H

/**
 * Base class for inheritance relationships
 */
class UMLInheritanceItem {
private:
    /// The base class of the inheritance relationship
    std::wstring mBase;

    /// The derived class of the inheritance relationship
    std::wstring mDerived;

protected:
    UMLInheritanceItem(std::wstring base, std::wstring derived);

public:
    /// Default constructor (disabled)
    UMLInheritanceItem() = delete;

    /// Copy constructor (disabled)
    UMLInheritanceItem(const UMLInheritanceItem &) = delete;

    /// Assignment operator
    void operator=(const UMLInheritanceItem &) = delete;

    /**
     * Getter for the base class
     * @return the name of the base class
     */
    std::wstring GetBase() { return mBase; }

    /**
     * Getter for the derived class
     * @return the name of the derived class
     */
    std::wstring GetDerived() { return mDerived; }
};

#endif //INC_335PROJECT1_UMLINHERITANCEITEM_H
