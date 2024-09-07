#ifndef RENDERER_H
#define RENDERER_H

#include "../Core/UI_element.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace fr::Rendering {

class Renderer {
    /*
    Role: Handles the actual rendering of UI_elements. May interface with SFML for drawing shapes, text, etc.

    Key Methods:
        void draw(const UI_element& element): Draws an element.
     */
private:
    std::shared_ptr<sf::RenderWindow> render_window_ptr;
public:
    explicit Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr);
    void draw(const std::shared_ptr<UI_element>& element);
};

}

#endif //RENDERER_H
