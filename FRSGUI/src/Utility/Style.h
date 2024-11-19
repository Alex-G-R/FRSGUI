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
    std::unordered_map<KEY, bool> flags = {};

    Style(std::initializer_list<std::pair<KEY, type>> init);

    void create_flags()
    {
      for(int key_int = static_cast<int>(KEY::POSITION); key_int < static_cast<int>(KEY::DEVEL_LAST_KEY); ++key_int)
      {
          auto key = static_cast<KEY>(key_int);
          flags.emplace(key, false);
      }
    };

    type getProperty(KEY property_key);
    void update_style(std::initializer_list<std::pair<KEY, type>> init);
};

}

#endif //STYLE_H
