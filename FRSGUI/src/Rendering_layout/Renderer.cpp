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
            int current_pos_priority = 0;
            int current_size_priority = 0;
            int current_backgroundColor_priority = 0;
            int current_outlineThickness_priority = 0;
            int current_outlineColor_priority = 0;

            for(const auto& group : element->getGroupsVector())
            {
                for(auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
                {
                    if(group == styleVec.group_name)
                    {
                        // Position
                        if ((styleVec.style.has_position) && (current_pos_priority == 0 || current_pos_priority < styleVec.style_priority)) {
                            shape->setPosition(styleVec.style.getPosition());
                            current_pos_priority = styleVec.style_priority;
                        }

                        // Size
                        if ((styleVec.style.has_size) && (current_size_priority == 0 || current_size_priority < styleVec.style_priority)) {
                            shape->setSize(styleVec.style.getSize());
                            current_size_priority = styleVec.style_priority;
                        }

                        // BG color
                        if ((styleVec.style.has_bg_color) && (current_backgroundColor_priority == 0 || current_backgroundColor_priority < styleVec.style_priority)) {
                            shape->setFillColor(styleVec.style.getBgColor());
                            current_backgroundColor_priority = styleVec.style_priority;
                        }

                        // Outline Thickness
                        if ((styleVec.style.has_outline_thickness) && (current_outlineThickness_priority == 0 || current_outlineThickness_priority < styleVec.style_priority)) {
                            shape->setOutlineThickness(styleVec.style.getOutlineThickness());
                            current_outlineThickness_priority = styleVec.style_priority;
                        }

                        // Outline Color
                        if ((styleVec.style.has_outline_color) && (current_outlineColor_priority == 0 || current_outlineColor_priority < styleVec.style_priority)) {
                            shape->setOutlineColor(styleVec.style.getOutlineColor());
                            current_outlineColor_priority = styleVec.style_priority;
                        }
                    }
                }
            }

            render_window_ptr->draw(*shape);
        }
    }
}