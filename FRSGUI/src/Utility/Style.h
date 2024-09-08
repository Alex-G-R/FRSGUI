#ifndef STYLE_H
#define STYLE_H

#include <Graphics.hpp>

namespace fr {

class Style {
private:
    sf::Vector2f size;
    sf::Vector2f position;
    sf::Color background_color;
    sf::Color outline_color;
    float outline_thickness;

public:
    Style();

    // setters
    void setSize(const sf::Vector2f& size);
    void setSize(const float& size_x, const float& size_y);
    void setPosition(const sf::Vector2f& pos);
    void setPosition(const float& pos_x, const float& pos_y);
    void setBgColor(const sf::Color& bg_color);
    void setOutlineColor(const sf::Color& outline_color);
    void setOutlineThickness(const float& outline_thickness);

    // getters
    sf::Vector2f& getSize();
    sf::Vector2f& getPosition();
    sf::Color& getBgColor();
    sf::Color& getOutlineColor();
    float& getOutlineThickness();


    // Status propierties
    bool has_size;
    bool has_position;
    bool has_bg_color;
    bool has_outline_color;
    bool has_outline_thickness;
};

}

#endif //STYLE_H
