#ifndef RENDERER_H
#define RENDERER_H

#include "SFML/Graphics.hpp"
#include <memory>
#include <string>
#include <unordered_map>

// Forward declaration
namespace fr {
    enum class KEY;
    class StyleVec;
    class Input;
    class UI_element;
    class FRSGUI;
}

namespace fr::Rendering {

class Renderer {
private:
    std::shared_ptr<sf::RenderWindow> render_window_ptr;
    FRSGUI* frsgui_ptr{};

    void applyStylesText(std::unordered_map<KEY, int>& current_priority, StyleVec& styleVec, sf::Text& text, sf::Color& cursor_color);
public:
    explicit Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, FRSGUI* frsgui_ptr);
    void draw(UI_element* element);
    bool shouldRender(UI_element* element);
};

}

#endif //RENDERER_H
