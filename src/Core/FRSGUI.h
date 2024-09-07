#ifndef FRSGUI_H
#define FRSGUI_H

#include <Graphics.hpp>
#include <System.hpp>
#include <Window.hpp>
#include <Audio.hpp>
#include <Network.hpp>

#include "GUI.h"

namespace fr {

class FRSGUI {
    /*
     Role: The main entry point of the application. Manages the GUI instance and handles the application lifecycle.


    Key Methods:
        run(): Initializes the GUI and enters the main loop.
    */
private:
    void Initialize();
    void Update();
    void Render();

    GUI* gui_ptr{};
    sf::RenderWindow* render_window_ptr{};

public:
    explicit FRSGUI(sf::RenderWindow* render_window_ptr);
    void Run();
};

}

#endif //FRSGUI_H
