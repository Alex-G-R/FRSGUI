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
