#ifndef FRSGUI_H
#define FRSGUI_H

#include <Graphics.hpp>
#include <System.hpp>
#include <Window.hpp>
#include <Audio.hpp>
#include <Network.hpp>

#include <memory>

#include "GUI.h"
#include "UI_element.h"
#include "../Rendering_layout/Renderer.h"

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


    Rendering::Renderer renderer;
    std::shared_ptr<Rendering::Renderer> renerer_ptr = std::make_shared<Rendering::Renderer>(renderer);
    GUI gui;
    std::shared_ptr<sf::RenderWindow> render_window_ptr{};

public:
    explicit FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr);
    void Run();

    std::shared_ptr<Rendering::Renderer> getRenderer();

    void addElement(const std::shared_ptr<UI_element>& element);

};

}

#endif //FRSGUI_H
