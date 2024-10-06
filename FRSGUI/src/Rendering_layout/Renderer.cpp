#include "Renderer.h"
#include "../Core/FRSGUI.h"
#include "../Core/UI_element.h"

#include <iostream>

namespace fr::Rendering {
    Renderer::Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, FRSGUI* frsgui_ptr) :
    render_window_ptr(render_window_ptr), frsgui_ptr(frsgui_ptr)
    {

    }

    void Renderer::draw(UI_element* element)
    {
        // Only render if is visible
        for (auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
        {
            if (styleVec.style_type == StyleType::ID && styleVec.group_name == element->getID())
            {
                // Skip rendering if element style by ID has set visibility to false
                if(styleVec.style.has_visibility == true && styleVec.style.isVisible() == false)
                    return;
            }
            else if (styleVec.style_type == StyleType::CLASS)
            {
                for (const auto& group : element->getGroupsVector())
                {
                    // Match by group
                    if (group == styleVec.group_name)
                    {
                        // Skip rendering if element style by group (CLASS) has set visibility to false
                        if(styleVec.style.has_visibility == true && styleVec.style.isVisible() == false)
                            return;
                    }
                }
            }
        }

        // Dereference the pointer to pass the actual object
        if (sf::RectangleShape* shape = element->getShape()) {
            // Track current priorities for style properties
            int current_pos_priority = 0;
            int current_size_priority = 0;
            int current_backgroundColor_priority = 0;
            int current_outlineThickness_priority = 0;
            int current_outlineColor_priority = 0;

            // Style handling for both ID and groups
            std::string element_id = element->getID();
            std::vector<std::string> element_groups = element->getGroupsVector();

            // Iterate over the styles defined in the stylesheet
            for (auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
            {
                bool applyStyle = false;

                // Check if the style should apply by ID or group(class)
                if (styleVec.style_type == StyleType::ID && styleVec.group_name == element_id)
                {
                    // Apply style by ID
                    applyStyle = true;
                }
                else if (styleVec.style_type == StyleType::CLASS) {
                    // Apply style if it matches one of the elements groups
                    for (const auto& group : element_groups)
                    {
                        if (group == styleVec.group_name)
                        {
                            applyStyle = true;
                            break;
                        }
                    }
                }

                // If we should apply the style -> check priorities and set the properties accordingly
                if (applyStyle) {
                    // Position
                    if (styleVec.style.has_position && (current_pos_priority < styleVec.style_priority)) {
                        shape->setPosition(styleVec.style.getPosition());
                        current_pos_priority = styleVec.style_priority;
                    }

                    // Size
                    if (styleVec.style.has_size && (current_size_priority < styleVec.style_priority)) {
                        shape->setSize(styleVec.style.getSize());
                        current_size_priority = styleVec.style_priority;
                    }

                    // Background color
                    if (styleVec.style.has_bg_color && (current_backgroundColor_priority < styleVec.style_priority)) {
                        shape->setFillColor(styleVec.style.getBgColor());
                        current_backgroundColor_priority = styleVec.style_priority;
                    }

                    // Outline thickness
                    if (styleVec.style.has_outline_thickness && (current_outlineThickness_priority < styleVec.style_priority)) {
                        shape->setOutlineThickness(styleVec.style.getOutlineThickness());
                        current_outlineThickness_priority = styleVec.style_priority;
                    }

                    // Outline color
                    if (styleVec.style.has_outline_color && (current_outlineColor_priority < styleVec.style_priority)) {
                        shape->setOutlineColor(styleVec.style.getOutlineColor());
                        current_outlineColor_priority = styleVec.style_priority;
                    }
                }
            }

            // Draw the shape
            render_window_ptr->draw(*shape);
        }
    }
}