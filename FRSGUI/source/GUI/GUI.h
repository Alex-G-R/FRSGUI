#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include "UIElement.h"
#include "../core/rendering/Renderer.h"

#include <vector>
#include <memory>

namespace fr {


class GUI {
private:
    std::shared_ptr<sf::RenderWindow> render_window_ptr{};
    std::shared_ptr<Renderer> renderer_ptr{};


public:
    GUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, const std::shared_ptr<Renderer>& renderer_ptr);

    std::vector<std::shared_ptr<UIElement>> elements;

    void render();
    void update();
    void addElement(const std::shared_ptr<UIElement>& element);

    std::shared_ptr<UIElement>& getElementByID(const std::string& id);
    std::shared_ptr<Input>& getInputByID(const std::string& id);
    std::shared_ptr<Button>& getButtonByID(const std::string& id);
    std::shared_ptr<Checkbox>& getCheckboxByID(const std::string& id);

    friend class UIElement;
};

}

#endif //GUI_H
