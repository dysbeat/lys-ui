add_executable(lys-ui
    main.cpp
)

target_link_libraries(lys-ui
    PRIVATE
    webview
)