#ifndef RENDERER_H
#define RENDERER_H

#include "SFML/Graphics.hpp"
#include <memory>
#include <string>

// Forward declaration
namespace fr {
    class UI_element;
    class FRSGUI;
}

namespace fr::Rendering {

class Renderer {
private:
    std::shared_ptr<sf::RenderWindow> render_window_ptr;
    FRSGUI* frsgui_ptr{};
public:
    explicit Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, FRSGUI* frsgui_ptr);
    void draw(UI_element* element);
};

}

#endif //RENDERER_H
