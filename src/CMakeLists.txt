add_executable(lys-ui
    main.cpp
    webview.hpp
)

target_link_libraries(lys-ui
    PRIVATE
    webview
    stdc++fs
)