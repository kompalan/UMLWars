/**
 * @file ItemVisitor.h
 * @author Kristian Rica
 *
 *
 */

#pragma once

#ifndef INC_335PROJECT1_ITEMVISITOR_H
#define INC_335PROJECT1_ITEMVISITOR_H


// Forward references to all Item types
class Harold;
class Scoreboard;
class UML;
class ClassUML;
class Inheritance;
class GoodClassUML;
class BadClassUML;
class GoodInheritance;
class BadInheritance;
/** Item visitor base class */
class ItemVisitor {
public:
    virtual ~ItemVisitor() {}

    /**
     * Visit Harold object
     * @param harold Harold object we are visiting
     */
    virtual void VisitHarold(Harold* harold) {}

    /**
     * Visit UML object
     * @param uml UML object we are visiting
     */
    virtual void VisitUML(UML* uml) {}

    /**
     * Visit class UML object
     * @param uml class UML object we are visiting
     */
    virtual void VisitClassUML(ClassUML* uml) {}

    /**
     * Visit Inheritance object
     * @param uml Inheritance UML object we are visiting
     */
    virtual void VisitInheritance(Inheritance* uml) {}

    /**
     * Visit Good UML object
     * @param goodUML GoodClassUML object being visited
     */
     virtual void VisitGoodUML(GoodClassUML* goodUML) {}

    /**
     * Visit Bad UML object
     * @param badUML BadClassUML object being visited
     */
    virtual void VisitBadUML(BadClassUML* badUML) {}
    /**
    * Visit Good Inheritance UML object
    * @param badUML GoodInheritanceItem object being visited
    */
    virtual void VisitGoodInheritance(GoodInheritance* goodUML) {}
    /**
    * Visit Good Inheritance UML object
    * @param badUML BadInheritanceItem object being visited
    */
    virtual void VisitBadInheritance(BadInheritance* badUML) {}


};

#endif //INC_335PROJECT1_ITEMVISITOR_H
