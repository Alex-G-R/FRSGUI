#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include "UI_element.h"
#include "../Rendering_layout/Renderer.h"

#include <vector>
#include <memory>

namespace fr {


class GUI {
    /*
    Role: Manages the overall UI. Contains a collection of UI_element objects and handles event propagation, rendering, and updates.

    Key Methods:
        addElement(std::shared_ptr<UI_element> element): Adds a UI_element to the GUI.
        handleEvent(const Event& event): Processes events and dispatches them to the appropriate UI_element.
        render(): Renders all UI elements in the correct order.
        update(): Updates all UI elements as necessary.

     */

private:
    std::vector<std::shared_ptr<UI_element>> elements;
    std::shared_ptr<sf::RenderWindow> render_window_ptr{};
    std::shared_ptr<Rendering::Renderer> renderer_ptr{};


public:
    GUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, const std::shared_ptr<Rendering::Renderer>& renderer_ptr);

    void Render();
    void Update();
    void addElement(const std::shared_ptr<UI_element>& element);

    friend class UI_element;
};

}

#endif //GUI_H
