#include "Renderer.h"
#include "../FRSGUI.h"
#include "../../GUI/UIElement.h"
#include <iostream>
#include <type_traits>
#include <functional>
#include "../../GUI/uielement_derived/Checkbox.h"

namespace fr {

void applyStylesRectangleShape(std::unordered_map<KEY, int>& current_priority, StyleVec& styleVec, sf::RectangleShape* shape);

Renderer::Renderer(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, FRSGUI* frsgui_ptr) :
render_window_ptr(render_window_ptr), frsgui_ptr(frsgui_ptr)
{

}

void Renderer::draw(UIElement* element)
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
        {KEY::CHARACTER_SIZE, 0},
        {KEY::TEXT_COLOR, 0},
        {KEY::FONT, 0}
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

    // Draw element text
    // Get position and width of the element
    auto elementPosition = shape->getPosition();
    float elementWidth = shape->getSize().x;

    sf::Text text = element->getText();

    // Set the text position relative to input field
    //text.setPosition(elementPosition.x, elementPosition.y);

    // Get the full text string from input
    std::string fullText = element->getTextString();
    text.setString(fullText);


    sf::Color cursor_color;
    // Iterate over the styles defined in the stylesheet
    for (auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
    {
        // Check if the style should apply by ID or group(class)
        if (styleVec.style_type == ApplyBy::ID && styleVec.group_name == element_id)
        { // Apply style by ID
            applyStylesText(current_priority, styleVec, text, cursor_color);
            // Center text verticaly
            text.setPosition(elementPosition.x, elementPosition.y + (shape->getSize().y / 2) - (text.getLocalBounds().height / 2 + text.getLocalBounds().top));
        }
        else if (styleVec.style_type == ApplyBy::GROUP) {
            // Apply style if it matches one of the elements groups
            for (const auto& group : element_groups)
            {
                if (group == styleVec.group_name)
                {
                    applyStylesText(current_priority, styleVec, text, cursor_color);
                    // Center text verticaly
                    text.setPosition(elementPosition.x, elementPosition.y + (shape->getSize().y / 2) - (text.getLocalBounds().height / 2 + text.getLocalBounds().top));
                    break;
                }
            }
        }
    }

    // Check if text width exceeds input field width
    while (text.getGlobalBounds().width + 10 > elementWidth && !fullText.empty()) {
        // If too wide remove characters from the beginning of the string
        fullText.erase(0, 1);
        text.setString(fullText);
    }

    render_window_ptr->draw(text);

    // Draw the cursor
    if(element->has_cursor == true)
    {
        // If the cursor `|` should be displayed create and configure a separate sf::Text for it
        if (element->selected == true)
        {
            sf::Text cursor(text);
            cursor.setString("|");
            cursor.setCharacterSize(text.getCharacterSize());


            // Set the color for the cursor
            cursor.setFillColor(cursor_color);

            // Position the cursor at the end of the main text
            float cursorXPosition = text.getGlobalBounds().left + text.getGlobalBounds().width;
            // Center cursor verticaly
            cursor.setPosition(cursorXPosition+1, elementPosition.y + (shape->getSize().y / 2) - (cursor.getLocalBounds().height / 2 + cursor.getLocalBounds().top));
            // Draw the cursor `|`
            render_window_ptr->draw(cursor);
        }
    }
}


void Renderer::applyStylesText(std::unordered_map<KEY, int>& current_priority, StyleVec& styleVec, sf::Text& text, sf::Color& cursor_color)
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

    // Text color
    if (styleVec.style->flags[KEY::TEXT_COLOR] && (current_priority[KEY::TEXT_COLOR] < styleVec.style_priority)) {

        type value = styleVec.style->getProperty(KEY::TEXT_COLOR);

        std::visit([&](auto&& arg)
        {
            using T = std::decay_t<decltype(arg)>;
            if constexpr(std::is_same_v<T, sf::Color>)
            {
                text.setFillColor(arg);
            }
        }, value);

        current_priority[KEY::TEXT_COLOR] = styleVec.style_priority;
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

    // Font
    if (styleVec.style->flags[KEY::FONT] && (current_priority[KEY::FONT] < styleVec.style_priority)) {

        type value = styleVec.style->getProperty(KEY::FONT);

        std::visit([&](auto&& arg)
        {
            using T = std::decay_t<decltype(arg)>;
            if constexpr(std::is_same_v<T, std::string>)
            {
                text.setFont(frsgui_ptr->getFont(arg));
            }
        }, value);

        current_priority[KEY::FONT] = styleVec.style_priority;
    }
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

void applyStylesSelectMark(std::unordered_map<KEY, int>& current_priority, StyleVec& styleVec, sf::RectangleShape& shape)
{
    if (styleVec.style->flags[KEY::SELECT_MARK_COLOR] && (current_priority[KEY::SELECT_MARK_COLOR] < styleVec.style_priority)) {
        type value = styleVec.style->getProperty(KEY::SELECT_MARK_COLOR);
        std::visit([&](auto&& arg)
        {
            using T = std::decay_t<decltype(arg)>;
            if constexpr(std::is_same_v<T, sf::Color>)
            {
                shape.setFillColor(arg);
            }
        }, value);
        current_priority[KEY::SELECT_MARK_COLOR] = styleVec.style_priority;
    }
}

void Renderer::drawSelectMark(sf::RectangleShape *shape_ptr, Checkbox *checkbox_ptr)
{
    if(shape_ptr == nullptr || checkbox_ptr == nullptr)
    {
        std::cerr << "FRSGUI | Renderer.cpp | passed pointer is a null pointer | drawSelectMark(some argument == nullptr) <---" << std::endl;
        return;
    }

    auto checkbox = *checkbox_ptr;
    auto shape = *shape_ptr;

    std::unordered_map<KEY, int> current_priority{
        {KEY::SELECT_MARK_COLOR, 0}
    };

    for (auto& styleVec : frsgui_ptr->style_sheet.getStyleVec())
    {
        // Check if the style should apply by ID or group(class)
        if (styleVec.style_type == ApplyBy::ID && styleVec.group_name == checkbox.getID())
        {
            applyStylesSelectMark(current_priority, styleVec, shape);
        }
        else if (styleVec.style_type == ApplyBy::GROUP) {
            // Apply style if it matches one of the elements groups
            for (const auto& group : checkbox.getGroupsVector())
            {
                if (group == styleVec.group_name)
                {
                    applyStylesSelectMark(current_priority, styleVec, shape);
                    break;
                }
            }
        }
    }

    render_window_ptr->draw(shape);
}


bool Renderer::shouldRender(UIElement* element)
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
