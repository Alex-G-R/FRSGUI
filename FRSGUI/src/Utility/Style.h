#ifndef STYLE_H
#define STYLE_H

#include <Graphics.hpp>

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <variant>

// Lemme tell you this shit is going to burn

namespace fr {

enum class KEY
{
    POSITION,
    SIZE,
    BACKGROUND_COLOR,
    OUTLINE_COLOR,
    OUTLINE_THICKNESS,
    VISIBLE
};

using type = std::variant<bool, int, float, double, sf::Color, sf::Vector2f>;

class Style {

    std::unordered_map<KEY, type> properties;

public:
    // Status propierties
    std::unordered_map<KEY, bool> flags = {
        {KEY::POSITION, false},
        {KEY::SIZE, false},
        {KEY::BACKGROUND_COLOR, false},
        {KEY::OUTLINE_COLOR, false},
        {KEY::OUTLINE_THICKNESS, false},
        {KEY::VISIBLE, false}
    };

    Style(std::initializer_list<std::pair<KEY, type>> init)
    {

        for(const auto& [key, value] : init)
        {
            properties[key] = value;

            // If the key is found in the flags map set its value to true
            if (flags.find(key) != flags.end()) {
                flags[key] = true;
            }
        }
    }

    type getProperty(KEY property_key)
    {
        for(const auto& [key, value] : properties)
        {
            if(property_key == key)
            {
               return value;
            }
        }

        throw std::runtime_error("Property key not found");  // key is not found
    }

    void update_style(std::initializer_list<std::pair<KEY, type>> init)
    {
        for(const auto& [key, value] : init)
        {
            properties[key] = value;

            // If the key is found in the flags map set its value to true
            if (flags.find(key) != flags.end()) {
                flags[key] = true;
            }
        }
    };

};

}

#endif //STYLE_H
