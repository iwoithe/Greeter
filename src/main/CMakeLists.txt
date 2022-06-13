add_executable(Greeter
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(Greeter PRIVATE
    ${QT_LIBRARIES}
    appshell
    greet
)
