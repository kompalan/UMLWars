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
class Inheritance;
class GoodClassUML;
class BadClassUML;

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
     * Visit class UML object
     * @param uml UML object we are visitng
     */
    virtual void VisitUML(UML* uml) {}

    /**
     * Visit Inheritance object
     * @param uml Inheritance UML object we are visitng
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

};

#endif //INC_335PROJECT1_ITEMVISITOR_H
