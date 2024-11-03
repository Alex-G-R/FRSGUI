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
    bool visible;

public:
    Style();

    // setters
    void setSize(sf::Vector2f size);
    void setSize(float size_x, float size_y);
    void setPosition(sf::Vector2f pos);
    void setPosition(float pos_x, float pos_y);
    void setBgColor(const sf::Color& bg_color);
    void setOutlineColor(const sf::Color& outline_color);
    void setOutlineThickness(float outline_thickness);
    void setVisibility(bool visible);

    // getters
    sf::Vector2f& getSize();
    sf::Vector2f& getPosition();
    sf::Color& getBgColor();
    sf::Color& getOutlineColor();
    float& getOutlineThickness();
    bool isVisible();


    // Status propierties
    bool has_size;
    bool has_position;
    bool has_bg_color;
    bool has_outline_color;
    bool has_outline_thickness;
    bool has_visibility;
};

}

#endif //STYLE_H
