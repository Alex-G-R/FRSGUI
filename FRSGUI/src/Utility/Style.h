#ifndef STYLE_H
#define STYLE_H

#include <Graphics.hpp>
#include <unordered_map>
#include <variant>
#include <string>

#include "KEY.h"

namespace fr {

using type = std::variant<bool, int, float, double, sf::Color, sf::Vector2f, std::string>;

class Style {

    std::unordered_map<KEY, type> properties;
    void create_flags();

public:
    // Status propierties
    std::unordered_map<KEY, bool> flags = {};

    Style(std::initializer_list<std::pair<KEY, type>> init);

    type getProperty(KEY property_key);
    void update_style(std::initializer_list<std::pair<KEY, type>> init);
};

}

#endif //STYLE_H
