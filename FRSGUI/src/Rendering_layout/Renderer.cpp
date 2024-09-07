#include "Renderer.h"
#include "../Core/FRSGUI.h"
#include "../Core/UI_element.h"

namespace fr::Rendering {
    Renderer::Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, FRSGUI* frsgui_ptr) :
    render_window_ptr(render_window_ptr), frsgui_ptr(frsgui_ptr)
    {

    }

    void Renderer::draw(UI_element* element)
    {

        // Dereference the pointer to pass the actual object
        if (sf::RectangleShape* shape = element->getShape())
        {

            for(const auto& group : element->getGroupsVector())
            {
                for(const auto& style : frsgui_ptr->style_sheet)
                {
                    if(group == style.first)
                    {
                        shape->setPosition(style.second.position);
                        shape->setSize(style.second.size);
                        shape->setFillColor(style.second.background_color);
                        shape->setOutlineThickness(style.second.outline_thickness);
                        shape->setOutlineColor(style.second.outline_color);
                    }
                }
            }

            render_window_ptr->draw(*shape);
        }
    }
}