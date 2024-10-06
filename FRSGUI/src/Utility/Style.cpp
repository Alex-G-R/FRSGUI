
#include "Style.h"

namespace fr {
    Style::Style()
    {
        visible = false;
        outline_thickness = 0.f;

        has_size  = false;
        has_position = false;
        has_bg_color = false;
        has_outline_color = false;
        has_outline_thickness = false;
        has_visibility = false;
    }

    void Style::setSize(const sf::Vector2f& size)
    {
        this->size = size;
        has_size = true;
    }

    void Style::setSize(const float& size_x, const float& size_y)
    {
        this->size = sf::Vector2f(size_x, size_y);
        has_size = true;
    }

    void Style::setPosition(const sf::Vector2f& pos)
    {
        this->position = pos;
        has_position = true;
    }

    void Style::setPosition(const float& pos_x, const float& pos_y)
    {
        this->position = sf::Vector2f(pos_x, pos_y);
        has_position = true;
    }

    void Style::setBgColor(const sf::Color& bg_color)
    {
        this->background_color = bg_color;
        has_bg_color = true;
    }

    void Style::setOutlineColor(const sf::Color& outline_color)
    {
        this->outline_color = outline_color;
        has_outline_color = true;
    }

    void Style::setOutlineThickness(const float& outline_thickness)
    {
        this->outline_thickness = outline_thickness;
        has_outline_thickness = true;
    }

    void Style::setVisibility(const bool visible)
    {
        this->visible = visible;
        has_visibility = true;
    }



    sf::Vector2f& Style::getSize()
    {
        return size;
    }
    sf::Vector2f& Style::getPosition()
    {
        return position;
    }
    sf::Color& Style::getBgColor()
    {
        return background_color;
    }
    sf::Color& Style::getOutlineColor()
    {
        return outline_color;
    }
    float& Style::getOutlineThickness()
    {
        return outline_thickness;
    }
    bool Style::isVisible()
    {
        return visible;
    }


}