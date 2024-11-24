#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include "UIElement.h"
#include "../Rendering_layout/Renderer.h"

#include <vector>
#include <memory>

namespace fr {


class GUI {
private:
    std::shared_ptr<sf::RenderWindow> render_window_ptr{};
    std::shared_ptr<Rendering::Renderer> renderer_ptr{};


public:
    GUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, const std::shared_ptr<Rendering::Renderer>& renderer_ptr);

    std::vector<std::shared_ptr<UI_element>> elements;

    void render();
    void update();
    void addElement(const std::shared_ptr<UI_element>& element);

    std::shared_ptr<UI_element>& getElementByID(const std::string& id);
    std::shared_ptr<Input>& getInputByID(const std::string& id);

    friend class UI_element;
};

}

#endif //GUI_H