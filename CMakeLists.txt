cmake_minimum_required(VERSION 3.28)
project(FRSGUI)

set(CMAKE_CXX_STANDARD 20)

add_executable(FRSGUI main.cpp
        FRSGUI/source/Core/FRSGUI.cpp
        FRSGUI/source/Core/FRSGUI.h
        FRSGUI/Source/GUI/GUI.cpp
        FRSGUI/Source/GUI/GUI.h
        FRSGUI/Source/GUI/UIElement.cpp
        FRSGUI/Source/GUI/UIElement.h
        FRSGUI/source/GUI/UIElement_derived/Button.cpp
        FRSGUI/source/GUI/UIElement_derived/Button.h
        FRSGUI/source/GUI/Events/EventDispatcher.cpp
        FRSGUI/source/GUI/Events/EventDispatcher.h
        FRSGUI/source/core/Rendering/Renderer.cpp
        FRSGUI/source/core/Rendering/Renderer.h
        FRSGUI/source/GUI/Styling/StyleManager.cpp
        FRSGUI/source/GUI/Styling/StyleManager.h
        FRSGUI/source/GUI/Styling/Style.cpp
        FRSGUI/source/GUI/Styling/Style.h
        FRSGUI/source/core/Utility/ResourceManager.cpp
        FRSGUI/source/core/Utility/ResourceManager.h
        FRSGUI/FRSGUI.hpp
        FRSGUI/source/GUI/Styling/StyleSheet.cpp
        FRSGUI/source/GUI/Styling/StyleSheet.h
        FRSGUI/source/GUI/styling/Enums/ApplyBy.h
        FRSGUI/source/GUI/Styling/StyleVec.h
        FRSGUI/source/GUI/Styling/StyleVec.cpp
        FRSGUI/source/GUI/UIElement_derived/Slider.cpp
        FRSGUI/source/GUI/UIElement_derived/Slider.h
        FRSGUI/source/Wrappers/Wrapper.hpp
        FRSGUI/source/GUI/styling/Enums/KEY.h
        FRSGUI/source/GUI/UIElement_derived/Input.cpp
        FRSGUI/source/GUI/UIElement_derived/Input.h
        FRSGUI/source/GUI/UIElement_derived/TextBlock.cpp
        FRSGUI/source/GUI/UIElement_derived/TextBlock.h
        FRSGUI/source/GUI/uielement_derived/Checkbox.h
        FRSGUI/source/GUI/uielement_derived/Checkbox.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/dev/DEVEL/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/dev/DEVEL/SFML/include/SFML)
target_link_libraries(FRSGUI sfml-system sfml-window sfml-graphics sfml-audio)