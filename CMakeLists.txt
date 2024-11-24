cmake_minimum_required(VERSION 3.28)
project(FRSGUI)

set(CMAKE_CXX_STANDARD 17)

add_executable(FRSGUI main.cpp
        FRSGUI/Source/Core/FRSGUI.cpp
        FRSGUI/Source/Core/FRSGUI.h
        FRSGUI/Source/GUI/GUI.cpp
        FRSGUI/Source/GUI/GUI.h
        FRSGUI/Source/GUI/UIElement.cpp
        FRSGUI/Source/GUI/UIElement.h
        FRSGUI/Source/GUI/UIElement_derived/Button.cpp
        FRSGUI/Source/GUI/UIElement_derived/Button.h
        FRSGUI/Source/GUI/Events/EventDispatcher.cpp
        FRSGUI/Source/GUI/Events/EventDispatcher.h
        FRSGUI/Source/Core/Rendering/Renderer.cpp
        FRSGUI/Source/Core/Rendering/Renderer.h
        FRSGUI/Source/GUI/Styling/StyleManager.cpp
        FRSGUI/Source/GUI/Styling/StyleManager.h
        FRSGUI/Source/GUI/Styling/Style.cpp
        FRSGUI/Source/GUI/Styling/Style.h
        FRSGUI/Source/Core/Utility/ResourceManager.cpp
        FRSGUI/Source/Core/Utility/ResourceManager.h
        FRSGUI/FRSGUI.hpp
        FRSGUI/Source/GUI/Styling/StyleSheet.cpp
        FRSGUI/Source/GUI/Styling/StyleSheet.h
        FRSGUI/Source/GUI/Styling/Enums/ApplyBy.h
        FRSGUI/Source/GUI/Styling/StyleVec.h
        FRSGUI/Source/GUI/Styling/StyleVec.cpp
        FRSGUI/Source/GUI/UIElement_derived/Slider.cpp
        FRSGUI/Source/GUI/UIElement_derived/Slider.h
        FRSGUI/Source/Wrappers/Wrapper.hpp
        FRSGUI/Source/GUI/Styling/Enums/KEY.h
        FRSGUI/Source/GUI/UIElement_derived/Input.cpp
        FRSGUI/Source/GUI/UIElement_derived/Input.h
        FRSGUI/Source/Wrappers/Constructor_overloads/InputOverloads.h
        FRSGUI/Source/Wrappers/Constructor_overloads/ButtonOverloads.h
        FRSGUI/Source/Wrappers/Constructor_overloads/UIElementOverloads.h
        FRSGUI/Source/GUI/UIElement_derived/TextBlock.cpp
        FRSGUI/Source/GUI/UIElement_derived/TextBlock.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/dev/DEVEL/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/dev/DEVEL/SFML/include/SFML)
target_link_libraries(FRSGUI sfml-system sfml-window sfml-graphics sfml-audio)