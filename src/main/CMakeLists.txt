add_executable(Greeter
    main.cpp
)

target_link_libraries(Greeter PUBLIC
    AppShell
    # Greet
    ${QT_LIBRARIES}
)
