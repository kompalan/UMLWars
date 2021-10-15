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
     * Visit Scoreboard object
     * @param scoreboard Scoreboard object we are visiting
     */
    virtual void VisitScoreboard(Scoreboard* scoreboard) {}

    /**
     * Visit UML object
     * @param uml UML object we are visitng
     */
    virtual void VisitUML(UML* uml) {}

};

#endif //INC_335PROJECT1_ITEMVISITOR_H
