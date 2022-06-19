set(MODULE_NAME greet)

set(MODULE_SRC
    ${CMAKE_CURRENT_LIST_DIR}/internal/greetingstore.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/greetingstore.h
    ${CMAKE_CURRENT_LIST_DIR}/greetmodule.cpp
    ${CMAKE_CURRENT_LIST_DIR}/greetmodule.h
)

set(MODULE_QRC
    greet.qrc
)

set(MODULE_LINK
    actions
)

include(${PROJECT_SOURCE_DIR}/build/module.cmake)
