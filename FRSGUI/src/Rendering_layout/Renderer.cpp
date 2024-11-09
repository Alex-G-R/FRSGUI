#include "Renderer.h"
#include "../Core/FRSGUI.h"
#include "../Core/UI_element.h"
#include <iostream>

namespace fr::Rendering {

    bool shouldRender(UI_element* element, FRSGUI* frsgui_ptr);
    void applyStyles(std::unordered_map<KEY, int>& current_priority, StyleVec& styleVec, sf::RectangleShape* shape);

    Renderer::Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, FRSGUI* frsgui_ptr) :
    render_window_ptr(render_window_ptr), frsgui_ptr(frsgui_ptr)
    {

    }

    void Renderer::draw(UI_element* element)
    {
        //Only render if is visible
        if(!shouldRender(element, frsgui_ptr))
            return;

        // Dereference the pointer to pass the actual object
        sf::RectangleShape* shape = element->getShape();
        if(shape == nullptr)
        {
            std::cerr<< "RENDERER.CPP DEREFERENCE ERROR | Error: Failed to get the shape from the element. Pointer is null." << std::endl;
            return;
        }

        // Track current priorities for style properties
        std::unordered_map<KEY, int> current_priority{
            {KEY::POSITION, 0},
            {KEY::SIZE, 0},
            {KEY::BACKGROUND_COLOR, 0},
            {KEY::OUTLINE_THICKNESS, 0},
            {KEY::OUTLINE_COLOR, 0}
        };


        // Style handling for both ID and groups
        std::string element_id = element->getID();
        std::vector<std::string> element_groups = element->getGroupsVector();

        // Do not render if no styles applied
        if(element_groups.empty())
            return;

        // Iterate over the styles defined in the stylesheet
        for (auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
        {
            // Check if the style should apply by ID or group(class)
            if (styleVec.style_type == StyleType::ID && styleVec.group_name == element_id)
            {
                // Apply style by ID
                applyStyles(current_priority, styleVec, shape);
            }
            else if (styleVec.style_type == StyleType::CLASS) {
                // Apply style if it matches one of the elements groups
                for (const auto& group : element_groups)
                {
                    if (group == styleVec.group_name)
                    {
                        applyStyles(current_priority, styleVec, shape);
                        break;
                    }
                }
            }
        }



        // Draw the shape
        render_window_ptr->draw(*shape);
    }

    void applyStyles(std::unordered_map<KEY, int>& current_priority, StyleVec& styleVec, sf::RectangleShape* shape)
    {
        // Position
        if (styleVec.style->flags[KEY::POSITION] && (current_priority[KEY::POSITION] < styleVec.style_priority)) {

            type value = styleVec.style->getProperty(KEY::POSITION);

            std::visit([&](auto&& arg)
            {
                using T = std::decay_t<decltype(arg)>;
                if constexpr(std::is_same_v<T, sf::Vector2f>)
                {
                    shape->setPosition(arg);
                }
            }, value);

            current_priority[KEY::POSITION] = styleVec.style_priority;
        }

        // Size
        if (styleVec.style->flags[KEY::SIZE] && (current_priority[KEY::SIZE] < styleVec.style_priority)) {

            type value = styleVec.style->getProperty(KEY::SIZE);

            std::visit([&](auto&& arg)
            {
                using T = std::decay_t<decltype(arg)>;
                if constexpr(std::is_same_v<T, sf::Vector2f>)
                {
                    shape->setSize(arg);
                }
            }, value);

            current_priority[KEY::SIZE] = styleVec.style_priority;
        }

        // Background color
        if (styleVec.style->flags[KEY::BACKGROUND_COLOR] && (current_priority[KEY::BACKGROUND_COLOR] < styleVec.style_priority)) {

            type value = styleVec.style->getProperty(KEY::BACKGROUND_COLOR);

            std::visit([&](auto&& arg)
            {
                using T = std::decay_t<decltype(arg)>;
                if constexpr(std::is_same_v<T, sf::Color>)
                {
                    shape->setFillColor(arg);
                }
            }, value);

            current_priority[KEY::BACKGROUND_COLOR] = styleVec.style_priority;
        }

        // Outline thickness
        if (styleVec.style->flags[KEY::OUTLINE_THICKNESS] && (current_priority[KEY::OUTLINE_THICKNESS] < styleVec.style_priority)) {
            type value = styleVec.style->getProperty(KEY::OUTLINE_THICKNESS);

            std::visit([&](auto&& arg)
            {
                using T = std::decay_t<decltype(arg)>;
                if constexpr(std::is_same_v<T, float>)
                {
                    shape->setOutlineThickness(arg);
                }
                else if constexpr(std::is_same_v<T, int>)
                {
                    shape->setOutlineThickness(static_cast<float>(arg));
                }
                else if constexpr(std::is_same_v<T, double>)
                {
                    shape->setOutlineThickness(static_cast<float>(arg));
                }
            }, value);

            current_priority[KEY::OUTLINE_THICKNESS] = styleVec.style_priority;
        }

        // Outline color
        if (styleVec.style->flags[KEY::OUTLINE_COLOR] && (current_priority[KEY::OUTLINE_COLOR] < styleVec.style_priority)) {
            type value = styleVec.style->getProperty(KEY::OUTLINE_COLOR);

            std::visit([&](auto&& arg)
            {
                using T = std::decay_t<decltype(arg)>;
                if constexpr(std::is_same_v<T, sf::Color>)
                {
                    shape->setOutlineColor(arg);
                }
            }, value);

            current_priority[KEY::OUTLINE_COLOR] = styleVec.style_priority;
        }
    }


    // Please fix this later cuz its terible xDDD
    bool shouldRender(UI_element* element, FRSGUI* frsgui_ptr)
    {
        for (auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
        {
            if (styleVec.style_type == StyleType::ID && styleVec.group_name == element->getID())
            {   // Skip rendering if element style by ID has set visibility to false
                if(styleVec.style->flags[KEY::VISIBLE] == true)
                {
                    bool visible = false;
                    type value = styleVec.style->getProperty(KEY::VISIBLE);

                    std::visit([&](auto&& arg)
                    {
                        using T = std::decay_t<decltype(arg)>;
                        if constexpr(std::is_same_v<T, bool>)
                        {
                            visible = arg;
                        }
                    }, value);

                    if(visible == false)
                        return false;
                }
            }

            else if (styleVec.style_type == StyleType::CLASS)
            {
                for (const auto& group : element->getGroupsVector())
                {
                    // Match by group
                    if (group == styleVec.group_name)
                    {
                        // Skip rendering if element style by group (CLASS) has set visibility to false
                        if(styleVec.style->flags[KEY::VISIBLE] == true)
                        {
                            bool visible = false;
                            type value = styleVec.style->getProperty(KEY::VISIBLE);

                            std::visit([&](auto&& arg)
                            {
                                using T = std::decay_t<decltype(arg)>;
                                if constexpr(std::is_same_v<T, bool>)
                                {
                                    visible = arg;
                                }
                            }, value);

                            if(visible == false)
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
}