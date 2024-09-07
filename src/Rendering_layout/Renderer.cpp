#include "Renderer.h"
#include "../Core/UI_element.h"

namespace fr::Rendering {
    Renderer::Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr) :
    render_window_ptr(render_window_ptr)
    {

    }

    void Renderer::draw(UI_element* element)
    {
        // Dereference the pointer to pass the actual object
        if (const sf::RectangleShape* shape = element->getShape())
        {
            render_window_ptr->draw(*shape);
        }
    }
}