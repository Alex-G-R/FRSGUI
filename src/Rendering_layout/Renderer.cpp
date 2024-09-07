#include "Renderer.h"

namespace fr::Rendering {
    Renderer::Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr) :
    render_window_ptr(render_window_ptr)
    {

    }

    void Renderer::draw(const std::shared_ptr<UI_element>& element)
    {
        render_window_ptr->draw(element->shape);
    }
}