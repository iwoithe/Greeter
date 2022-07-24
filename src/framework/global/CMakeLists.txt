set(MODULE_NAME global)

include(${CMAKE_CURRENT_LIST_DIR}/modularity/modularity.cmake)

set(MODULE_SRC
    ${MODULARITY_SRC}
    # TODO: Move engines.[cpp,h] to the ui module
    engines.cpp
    engines.h
    ret.cpp
    ret.h
)

include(${PROJECT_SOURCE_DIR}/build/module.cmake)
