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
#include "../GUI/GUI.h"
#include "../GUI/UIElement.h"
#include "rendering/Renderer.h"
#include "../GUI/styling/Style.h"
#include "../GUI/styling/StyleManager.h"
#include "../GUI/styling/StyleSheet.h"
#include "../GUI/events/EventDispatcher.h"
#include "utility/ResourceManager.h"

namespace fr {

class FRSGUI {
private:
    // Renderer
    Renderer renderer;
    std::shared_ptr<Renderer> renerer_ptr = std::make_shared<Renderer>(renderer);

    // GUI
    GUI gui;

    // Event dispatcher
    EventDispatcher event_dispatcher;

    // Style manager
    StyleManager style_manager;

    // SFML Render window
    std::shared_ptr<sf::RenderWindow> render_window_ptr{};

    // Resource menager
    ResourceManager resource_manager;

public:
    explicit FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr);

    // Methods
    void Render();

    // Getters
    std::shared_ptr<Renderer> getRenderer();

    //methods public acces
    void addElement(const std::shared_ptr<UIElement>& element);
    void addStyle(std::string group_name, std::shared_ptr<Style> style, ApplyBy style_type, int style_priority);
    void dispatchEvent(const sf::Event& event);
    std::shared_ptr<UIElement>& getUIElementByID(const std::string& id);
    std::shared_ptr<Input>& getInputByID(const std::string& id);
    std::shared_ptr<Button>& getButtonByID(const std::string& id);
    std::shared_ptr<Checkbox>& getCheckboxByID(const std::string& id);
    void addFont(const std::string& font_alias, const std::string& path);
    sf::Font& getFont(const std::string& font_alias);

    StyleSheet& style_sheet;
};

}

#endif //FRSGUI_H
