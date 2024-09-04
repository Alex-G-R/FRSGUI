cmake_minimum_required(VERSION 3.28)
project(FRSGUI)

set(CMAKE_CXX_STANDARD 17)

add_executable(FRSGUI main.cpp
        src/Core/FRSGUI.cpp
        src/Core/FRSGUI.h
        src/Core/GUI.cpp
        src/Core/GUI.h
        src/Core/UI_element.cpp
        src/Core/UI_element.h
        src/Core/UI_element_derived/Button.cpp
        src/Core/UI_element_derived/Button.h
        src/Event_system/Event.cpp
        src/Event_system/Event.h
        src/Event_system/EventDispatcher.cpp
        src/Event_system/EventDispatcher.h
        src/Rendering_layout/Renderer.cpp
        src/Rendering_layout/Renderer.h
        src/Rendering_layout/Layout.cpp
        src/Rendering_layout/Layout.h
        src/Rendering_layout/StyleManager.cpp
        src/Rendering_layout/StyleManager.h
        src/Utility/Style.cpp
        src/Utility/Style.h
        src/Utility/ResourceManager.cpp
        src/Utility/ResourceManager.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/dev/DEVEL/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/dev/DEVEL/SFML/include/SFML)
target_link_libraries(FRSGUI sfml-system sfml-window sfml-graphics sfml-audio)