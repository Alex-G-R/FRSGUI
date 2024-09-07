#ifndef STYLE_H
#define STYLE_H

#include <Graphics.hpp>

namespace fr::Utils {

class Style {
private:

    sf::Vector2f size;
    sf::Vector2f position;

    sf::Color background_color;

    // Outline
    sf::Color outline_color;
    float outline_thickness;


public:
    std::string style_name;
    Style();
};

}

#endif //STYLE_H
