#include "Renderer.h"
#include "../Core/FRSGUI.h"
#include "../Core/UI_element.h"
#include <iostream>
#include <functional>

namespace fr::Rendering {

void applyStylesRectangleShape(std::unordered_map<KEY, int>& current_priority, StyleVec& styleVec, sf::RectangleShape* shape);

Renderer::Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, FRSGUI* frsgui_ptr) :
render_window_ptr(render_window_ptr), frsgui_ptr(frsgui_ptr)
{

}

void Renderer::draw(sf::Text& text, Input& input_field)
{
    //Only render if is visible
    if(!shouldRender(&input_field))
    {
        return;
    }

    // Track current priorities for input style specific styles
    std::unordered_map<KEY, int> current_priority{
            {KEY::CURSOR_COLOR, 0},
            {KEY::CHARACTER_SIZE, 0}
    };


    // Get position and width of input field
    auto inputPosition = input_field.getShape()->getPosition();
    float inputWidth = input_field.getShape()->getSize().x;

    // Set the text position relative to input field
    text.setPosition(inputPosition.x, inputPosition.y);

    // Get the full text string from input
    std::string fullText = input_field.get_data();
    text.setString(fullText);

    // Check if text width exceeds input field width
    while (text.getGlobalBounds().width + 10 > inputWidth && !fullText.empty()) {
        // If too wide remove characters from the beginning of the string
        fullText.erase(0, 1);
        text.setString(fullText);
    }

    // Style handling for both ID and groups
    std::string element_id = input_field.getID();
    std::vector<std::string> element_groups = input_field.getGroupsVector();

    // Do not render if no styles applied
    if(element_groups.empty())
        return;

    sf::Color cursor_color;

    // Iterate over the styles defined in the stylesheet
    for (auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
    {
        // Check if the style should apply by ID or group(class)
        if (styleVec.style_type == ApplyBy::ID && styleVec.group_name == element_id)
        {
            // Apply style by ID

            // Character size
            if (styleVec.style->flags[KEY::CHARACTER_SIZE] && (current_priority[KEY::CHARACTER_SIZE] < styleVec.style_priority)) {

                type value = styleVec.style->getProperty(KEY::CHARACTER_SIZE);

                std::visit([&](auto&& arg)
                {
                    using T = std::decay_t<decltype(arg)>;
                    if constexpr(std::is_same_v<T, int>)
                    {
                        text.setCharacterSize(arg);
                    }
                }, value);

                current_priority[KEY::CHARACTER_SIZE] = styleVec.style_priority;
            }

            // Cursor color
            if (styleVec.style->flags[KEY::CURSOR_COLOR] && (current_priority[KEY::CURSOR_COLOR] < styleVec.style_priority)) {

                type value = styleVec.style->getProperty(KEY::CURSOR_COLOR);

                std::visit([&](auto&& arg)
                {
                    using T = std::decay_t<decltype(arg)>;
                    if constexpr(std::is_same_v<T, sf::Color>)
                    {
                        cursor_color = arg;
                    }
                }, value);

                current_priority[KEY::CURSOR_COLOR] = styleVec.style_priority;
            }

        }
        else if (styleVec.style_type == ApplyBy::GROUP) {
            // Apply style if it matches one of the elements groups
            for (const auto& group : element_groups)
            {
                if (group == styleVec.group_name)
                {
                    // Character size
                    if (styleVec.style->flags[KEY::CHARACTER_SIZE] && (current_priority[KEY::CHARACTER_SIZE] < styleVec.style_priority)) {

                        type value = styleVec.style->getProperty(KEY::CHARACTER_SIZE);

                        std::visit([&](auto&& arg)
                        {
                            using T = std::decay_t<decltype(arg)>;
                            if constexpr(std::is_same_v<T, int>)
                            {
                                text.setCharacterSize(arg);
                            }
                        }, value);

                        current_priority[KEY::CHARACTER_SIZE] = styleVec.style_priority;
                    }

                    // Cursor color
                    if (styleVec.style->flags[KEY::CURSOR_COLOR] && (current_priority[KEY::CURSOR_COLOR] < styleVec.style_priority)) {

                        type value = styleVec.style->getProperty(KEY::CURSOR_COLOR);

                        std::visit([&](auto&& arg)
                        {
                            using T = std::decay_t<decltype(arg)>;
                            if constexpr(std::is_same_v<T, sf::Color>)
                            {
                                cursor_color = arg;
                            }
                        }, value);

                        current_priority[KEY::CURSOR_COLOR] = styleVec.style_priority;
                    }
                    break;
                }
            }
        }
    }

    // Draw the main text first
    render_window_ptr->draw(text);

    // If the cursor `|` should be displayed create and configure a separate sf::Text for it
    if (input_field.get_select() == true)
    {
        sf::Text cursor(text);
        cursor.setString("|");
        cursor.setCharacterSize(text.getCharacterSize());


        // Set the color for the cursor
        cursor.setFillColor(cursor_color);

        // Position the cursor at the end of the main text
        float cursorXPosition = text.getGlobalBounds().left + text.getGlobalBounds().width;
        cursor.setPosition(cursorXPosition+1, inputPosition.y);
        // Draw the cursor `|`
        render_window_ptr->draw(cursor);
    }
}

void Renderer::draw(UI_element* element)
{
    //Only render if is visible
    if(!shouldRender(element))
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
        {KEY::OUTLINE_COLOR, 0},
        {KEY::CURSOR_COLOR, 0},
        {KEY::CHARACTER_SIZE, 0}
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
        if (styleVec.style_type == ApplyBy::ID && styleVec.group_name == element_id)
        {
            // Apply style by ID
            applyStylesRectangleShape(current_priority, styleVec, shape);
        }
        else if (styleVec.style_type == ApplyBy::GROUP) {
            // Apply style if it matches one of the elements groups
            for (const auto& group : element_groups)
            {
                if (group == styleVec.group_name)
                {
                    applyStylesRectangleShape(current_priority, styleVec, shape);
                    break;
                }
            }
        }
    }

    // Draw the shape
    render_window_ptr->draw(*shape);
}

void applyStylesRectangleShape(std::unordered_map<KEY, int>& current_priority, StyleVec& styleVec, sf::RectangleShape* shape)
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


bool Renderer::shouldRender(UI_element* element)
{
    // Helper lambda to check visibility property
    // This eliminates code duplication and makes the logic clearer
    auto checkVisibility = [](const std::shared_ptr<Style>& style) -> bool
    {
        // If VISIBLE flag is not set, element is visible by default
        if (!style->flags[KEY::VISIBLE])
        {
            return true;
        }

        // Get the visibility value from style properties
        type value = style->getProperty(KEY::VISIBLE);
        bool visible = true;  // Default to visible

        // Use std::visit to safely extract boolean value
        std::visit([&visible](auto&& arg)
        {
            using T = std::decay_t<decltype(arg)>;
            if constexpr(std::is_same_v<T, bool>)
            {
                visible = arg;
            }
        }, value);

        return visible;
    };

    // Iterate through all style vectors in the stylesheet
    for (auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
    {
        // Case 1: Check styles applied by ID
        if (styleVec.style_type == ApplyBy::ID && styleVec.group_name == element->getID())
        {
            // If visibility check fails, element should not be rendered
            if (!checkVisibility(styleVec.style))
            {
                return false;
            }
        }
        // Case 2: Check styles applied by GROUP
        else if (styleVec.style_type == ApplyBy::GROUP)
        {
            // Check if element belongs to any groups
            for (auto& group : element->getGroupsVector())
            {
                if (group == styleVec.group_name)
                {
                    // If visibility check fails for any matching group,
                    // element should not be rendered
                    if (!checkVisibility(styleVec.style))
                    {
                        return false;
                    }
                    break;  // No need to check other groups once we find a match
                }
            }
        }
    }

    // If no style rules made the element invisible, it should be rendered
    return true;
}

}