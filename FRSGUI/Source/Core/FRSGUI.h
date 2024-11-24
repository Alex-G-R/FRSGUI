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
#include "UIElement.h"
#include "../Rendering_layout/Renderer.h"
#include "../Utility/Style.h"
#include "../Rendering_layout/StyleManager.h"
#include "../Rendering_layout/StyleSheet.h"
#include "../Event_system/EventDispatcher.h"
#include "../Utility/ResourceManager.h"

namespace fr {

class FRSGUI {
private:
    // Renderer
    Rendering::Renderer renderer;
    std::shared_ptr<Rendering::Renderer> renerer_ptr = std::make_shared<Rendering::Renderer>(renderer);

    // GUI
    GUI gui;

    // Event dispatcher
    Events::EventDispatcher event_dispatcher;

    // Style manager
    Rendering::StyleManager style_manager;

    // SFML Render window
    std::shared_ptr<sf::RenderWindow> render_window_ptr{};

    // Resource menager
    Utils::ResourceManager resource_manager;

public:
    explicit FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr);

    // Methods
    void Render();

    // Getters
    std::shared_ptr<Rendering::Renderer> getRenderer();

    // GUI methods public acces
    void addElement(const std::shared_ptr<UI_element>& element);
    void addStyle(std::string group_name, std::shared_ptr<Style> style, ApplyBy style_type, int style_priority);
    void dispatchEvent(const sf::Event& event);
    std::shared_ptr<UI_element>& getElementByID(const std::string& id);
    std::shared_ptr<Input>& getInputByID(const std::string& id);
    void addFont(const std::string& font_alias, const std::string& path);
    sf::Font& getFont(const std::string& font_alias);

    Rendering::StyleSheet& style_sheet;
};

}

#endif //FRSGUI_H