#ifndef STYLE_H
#define STYLE_H

#include <Graphics.hpp>
#include <unordered_map>
#include <variant>

#include "KEY.h"

namespace fr {

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

    Style(std::initializer_list<std::pair<KEY, type>> init);

    type getProperty(KEY property_key);
    void update_style(std::initializer_list<std::pair<KEY, type>> init);
};

}

#endif //STYLE_H
