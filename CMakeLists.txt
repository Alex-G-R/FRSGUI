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
        src/Core/UI_element_derived/Button.h)
