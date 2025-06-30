cmake_minimum_required(VERSION 3.31)
project(FRSGUI)

set(CMAKE_CXX_STANDARD 20)

# Define the path to your local SFML installation within the project
set(SFML_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/FRSGUI/external_libs/SFML")

# Add the include directories
include_directories("${SFML_ROOT}/include")

# Tell CMake to search for libraries in our custom lib directory
link_directories("${SFML_ROOT}/lib")

# Define a preprocessor definition for static linking
# This is important for SFML to know it's being statically linked
add_definitions(-DSFML_STATIC)

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

# Link SFML components statically and their dependencies.
# The order of libraries is important for static linking!
# SFML modules usually come first, followed by their dependencies.
target_link_libraries(${PROJECT_NAME}
        sfml-graphics-s
        sfml-window-s
        sfml-system-s
        sfml-audio-s   # If you're using audio
        sfml-network-s # If you're using network

        # Core SFML dependencies (crucial for static linking)
        freetype       # Required by sfml-graphics-s for fonts (this was the missing one!)
        # jpeg         # Optional: If SFML was compiled with JPEG image support
        # webp         # Optional: If SFML was compiled with WebP image support

        # Audio dependencies (if sfml-audio-s is used)
        # openal32     # Core OpenAL library
        # vorbisfile
        # vorbis
        # vorbisenc
        # ogg
        # flac

        # Networking dependencies (if sfml-network-s is used)
        # ws2_32       # Windows Sockets 2 (for networking)

        # System dependencies (for Windows with MinGW)
        opengl32
        winmm
        gdi32
        # Add other Windows system libraries that SFML might implicitly depend on,
        # often needed when linking static SFML on MinGW:
        user32
        kernel32
        # Other common ones that might be needed depending on your SFML build:
        # shell32
        # ole32
        # uuid
        # advapi32
)