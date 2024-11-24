cmake_minimum_required(VERSION 3.28)
project(FRSGUI)

set(CMAKE_CXX_STANDARD 17)

add_executable(FRSGUI main.cpp
        FRSGUI/Source/Core/FRSGUI.cpp
        FRSGUI/Source/Core/FRSGUI.h
        FRSGUI/Source/Core/GUI.cpp
        FRSGUI/Source/Core/GUI.h
        FRSGUI/Source/Core/UIElement.cpp
        FRSGUI/Source/Core/UIElement.h
        FRSGUI/Source/Core/UIElement_derived/Button.cpp
        FRSGUI/Source/Core/UIElement_derived/Button.h
        FRSGUI/Source/Event_system/EventDispatcher.cpp
        FRSGUI/Source/Event_system/EventDispatcher.h
        FRSGUI/Source/Rendering_layout/Renderer.cpp
        FRSGUI/Source/Rendering_layout/Renderer.h
        FRSGUI/Source/Rendering_layout/Layout.cpp
        FRSGUI/Source/Rendering_layout/Layout.h
        FRSGUI/Source/Rendering_layout/StyleManager.cpp
        FRSGUI/Source/Rendering_layout/StyleManager.h
        FRSGUI/Source/Utility/Style.cpp
        FRSGUI/Source/Utility/Style.h
        FRSGUI/Source/Utility/ResourceManager.cpp
        FRSGUI/Source/Utility/ResourceManager.h
        FRSGUI/FRSGUI.hpp
        FRSGUI/Source/Rendering_layout/StyleSheet.cpp
        FRSGUI/Source/Rendering_layout/StyleSheet.h
        FRSGUI/Source/Utility/ApplyBy.h
        FRSGUI/Source/Utility/StyleVec.h
        FRSGUI/Source/Utility/StyleVec.cpp
        FRSGUI/Source/Core/UIElement_derived/Slider.cpp
        FRSGUI/Source/Core/UIElement_derived/Slider.h
        FRSGUI/Source/Utility/HelperFunctions.hpp
        FRSGUI/Source/Utility/KEY.h
        FRSGUI/Source/Core/UIElement_derived/Input.cpp
        FRSGUI/Source/Core/UIElement_derived/Input.h
        FRSGUI/Source/Utility/Constructor_overloads/InputOverloads.h
        FRSGUI/Source/Utility/Constructor_overloads/ButtonOverloads.h
        FRSGUI/Source/Utility/Constructor_overloads/UIElementOverloads.h
        FRSGUI/Source/Core/UIElement_derived/TextBlock.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/dev/DEVEL/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/dev/DEVEL/SFML/include/SFML)
target_link_libraries(FRSGUI sfml-system sfml-window sfml-graphics sfml-audio)