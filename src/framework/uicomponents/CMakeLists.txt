set(MODULE_NAME uicomponents)

set(MODULE_SRC
    ${CMAKE_CURRENT_LIST_DIR}/view/dialogview.cpp
    ${CMAKE_CURRENT_LIST_DIR}/view/dialogview.h
    ${CMAKE_CURRENT_LIST_DIR}/uicomponentsmodule.cpp
    ${CMAKE_CURRENT_LIST_DIR}/uicomponentsmodule.h
)

include(${PROJECT_SOURCE_DIR}/build/module.cmake)
