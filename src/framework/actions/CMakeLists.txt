set(MODULE_NAME actions)

set(MODULE_SRC
    actiontypes.h
    iactionscontroller.h
    idispatcher.h
    internal/dispatcher.cpp
    internal/dispatcher.h
    istore.h
)

include(${PROJECT_SOURCE_DIR}/build/module.cmake)
