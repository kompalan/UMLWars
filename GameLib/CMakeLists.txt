project(GameLib)

set(SOURCE_FILES Vector.cpp Vector.h Game.cpp Game.h WarsView.cpp WarsView.h MainFrame.cpp MainFrame.h pch.h Item.cpp Item.h Harold.cpp Harold.h Game.cpp Game.h WarsView.cpp WarsView.h MainFrame.cpp MainFrame.h pch.h Item.cpp Item.h Harold.cpp Harold.h UMLData.cpp UMLData.h UMLAttribute.cpp UMLAttribute.h UMLName.cpp UMLName.h GoodUMLName.cpp GoodUMLName.h BadUMLName.cpp BadUMLName.h UMLClassItem.cpp UMLClassItem.h GoodUMLAttribute.cpp GoodUMLAttribute.h BadUMLAttribute.cpp BadUMLAttribute.h UMLOperation.cpp UMLOperation.h GoodUMLOperation.cpp GoodUMLOperation.h BadUMLOperation.cpp BadUMLOperation.h ItemVisitor.cpp ItemVisitor.h UMLInheritanceItem.cpp UMLInheritanceItem.h GoodInheritanceItem.cpp GoodInheritanceItem.h BadInheritanceItem.cpp BadInheritanceItem.h Scoreboard.cpp Scoreboard.h Pen.cpp Pen.h UML.cpp UML.h Inheritance.cpp Inheritance.h GoodInheritance.cpp GoodInheritance.h BadInheritance.cpp BadInheritance.h GoodClassUML.cpp GoodClassUML.h BadClassUML.cpp BadClassUML.h GoodUMLVisitor.cpp GoodUMLVisitor.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)