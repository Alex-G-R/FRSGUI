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
#include "../Utility/Style.h"
#include "../Rendering_layout/StyleManager.h"

namespace fr {

class FRSGUI {
private:
    void Initialize();
    void Update();
    void Render();


    Rendering::Renderer renderer;
    std::shared_ptr<Rendering::Renderer> renerer_ptr = std::make_shared<Rendering::Renderer>(renderer);
    GUI gui;
    std::shared_ptr<sf::RenderWindow> render_window_ptr{};
    Rendering::StyleManager style_manager;

public:
    explicit FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr);

    void Run();

    std::shared_ptr<Rendering::Renderer> getRenderer();

    std::map<std::string, Style>& style_sheet;

    void addElement(const std::shared_ptr<UI_element>& element);

};

}

#endif //FRSGUI_H
