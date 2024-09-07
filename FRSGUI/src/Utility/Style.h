#ifndef STYLE_H
#define STYLE_H

#include <Graphics.hpp>

namespace fr {

class Style {
public:
    Style();

    sf::Vector2f size;
    sf::Vector2f position;

    sf::Color background_color;

    // Outline
    sf::Color outline_color;
    float outline_thickness;
};

}

#endif //STYLE_H
