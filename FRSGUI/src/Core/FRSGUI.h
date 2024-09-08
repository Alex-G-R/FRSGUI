#ifndef FRSGUI_H
#define FRSGUI_H

/* SFML */
#include <Graphics.hpp>
#include <System.hpp>
#include <Window.hpp>
#include <Audio.hpp>
#include <Network.hpp>

/* Standard lib */
#include <memory>

/* Inner header files */
#include "GUI.h"
#include "UI_element.h"
#include "../Rendering_layout/Renderer.h"
#include "../Utility/Style.h"
#include "../Rendering_layout/StyleManager.h"
#include "../Rendering_layout/StyleSheet.h"

namespace fr {

class FRSGUI {
private:
    void Initialize();
    void Update();
    void Render();

    // Renderer
    Rendering::Renderer renderer;
    std::shared_ptr<Rendering::Renderer> renerer_ptr = std::make_shared<Rendering::Renderer>(renderer);

    // GUI
    GUI gui;

    // Style manager
    Rendering::StyleManager style_manager;

    // SFML Render window
    std::shared_ptr<sf::RenderWindow> render_window_ptr{};

public:
    explicit FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr);

    // Methods
    void Run();

    // Getters
    std::shared_ptr<Rendering::Renderer> getRenderer();

    // GUI methods public acces
    void addElement(const std::shared_ptr<UI_element>& element);

    Rendering::StyleSheet& style_sheet;
};

}

#endif //FRSGUI_H
