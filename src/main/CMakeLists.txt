add_executable(Greet
    main.cpp
)

target_link_libraries(Greet PUBLIC
    AppShell
    # Greet
    ${QT_LIBRARIES}
)
