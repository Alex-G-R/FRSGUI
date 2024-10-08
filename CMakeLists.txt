cmake_minimum_required(VERSION 3.28)
project(FRSGUI)

set(CMAKE_CXX_STANDARD 17)

add_executable(FRSGUI main.cpp
        FRSGUI/src/Core/FRSGUI.cpp
        FRSGUI/src/Core/FRSGUI.h
        FRSGUI/src/Core/GUI.cpp
        FRSGUI/src/Core/GUI.h
        FRSGUI/src/Core/UI_element.cpp
        FRSGUI/src/Core/UI_element.h
        FRSGUI/src/Core/UI_element_derived/Button.cpp
        FRSGUI/src/Core/UI_element_derived/Button.h
        FRSGUI/src/Event_system/EventDispatcher.cpp
        FRSGUI/src/Event_system/EventDispatcher.h
        FRSGUI/src/Rendering_layout/Renderer.cpp
        FRSGUI/src/Rendering_layout/Renderer.h
        FRSGUI/src/Rendering_layout/Layout.cpp
        FRSGUI/src/Rendering_layout/Layout.h
        FRSGUI/src/Rendering_layout/StyleManager.cpp
        FRSGUI/src/Rendering_layout/StyleManager.h
        FRSGUI/src/Utility/Style.cpp
        FRSGUI/src/Utility/Style.h
        FRSGUI/src/Utility/ResourceManager.cpp
        FRSGUI/src/Utility/ResourceManager.h
        FRSGUI/FRSGUI.hpp
        FRSGUI/src/Rendering_layout/StyleSheet.cpp
        FRSGUI/src/Rendering_layout/StyleSheet.h
        FRSGUI/src/Utility/StyleType.h
        FRSGUI/src/Utility/StyleVec.h
        FRSGUI/src/Utility/StyleVec.cpp
        FRSGUI/src/Core/UI_element_derived/TextArea.cpp
        FRSGUI/src/Core/UI_element_derived/TextArea.h
        FRSGUI/src/Core/UI_element_derived/Slider.cpp
        FRSGUI/src/Core/UI_element_derived/Slider.h
        FRSGUI/src/Utility/HelperFunctions.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/dev/DEVEL/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/dev/DEVEL/SFML/include/SFML)
target_link_libraries(FRSGUI sfml-system sfml-window sfml-graphics sfml-audio)