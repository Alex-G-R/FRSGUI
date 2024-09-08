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
                for(const auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
                {
                    if(group == styleVec.group_name)
                    {
                        shape->setPosition(styleVec.style.position);
                        shape->setSize(styleVec.style.size);
                        shape->setFillColor(styleVec.style.background_color);
                        shape->setOutlineThickness(styleVec.style.outline_thickness);
                        shape->setOutlineColor(styleVec.style.outline_color);
                    }
                }
            }

            render_window_ptr->draw(*shape);
        }
    }
}