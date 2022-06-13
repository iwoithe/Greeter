set(MODULE_NAME actions)

set(MODULE_SRC
    actioncontroller.h
    actiontypes.h
    iactionsdispatcher.h
    internal/actionsdispatcher.cpp
    internal/actionsdispatcher.h
)

include(${PROJECT_SOURCE_DIR}/build/module.cmake)
