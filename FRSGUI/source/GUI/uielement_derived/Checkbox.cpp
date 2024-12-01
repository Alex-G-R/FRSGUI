#include "Checkbox.h"

namespace fr {

    Checkbox::Checkbox(const std::shared_ptr<Renderer> &renderer_ptr) : UIElement(renderer_ptr)
    {

    }

    void Checkbox::Render()
    {
        // Draw the element
        renderer_ptr->draw(this);

        /* Draw the checkbox_mark */
        if(selected == false)
            return;

        const sf::Vector2f checkbox_pos = this->getShape()->getPosition();
        const sf::Vector2f checkbox_size = this->getShape()->getSize();

        select_mark.setSize(sf::Vector2f(checkbox_size.x * 0.85f, checkbox_size.y * 0.85f));

        // Calculate position to center the select mark inside the checkbox
        const sf::Vector2f offset(
            (checkbox_size.x - select_mark.getSize().x) / 2.0f,
            (checkbox_size.y - select_mark.getSize().y) / 2.0f
        );

        select_mark.setPosition(sf::Vector2f(checkbox_pos.x + offset.x, checkbox_pos.y + offset.y));

        renderer_ptr->drawSelectMark(&select_mark, this);
    }

    void Checkbox::setSelect(bool selected)
    {
        this->selected = selected;
    }

    bool Checkbox::getSelect()
    {
        return this->selected;
    }

    bool Checkbox::getData()
    {
        return this->selected;
    }

} // fr