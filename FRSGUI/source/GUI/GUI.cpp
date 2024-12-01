#include "GUI.h"

#include "uielement_derived/Input.h"
#include "uielement_derived/Button.h"
#include "uielement_derived/Checkbox.h"


namespace fr {
    GUI::GUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, const std::shared_ptr<Renderer>& renderer_ptr) :
    render_window_ptr(render_window_ptr), renderer_ptr(renderer_ptr)
    {

    }

    void GUI::render()
    {
        for(const auto& element : elements)
        {
            element->Render();
        }
    }

    void GUI::update()
    {

    }

    void GUI::addElement(const std::shared_ptr<UIElement>& element)
    {
        elements.emplace_back(element);
    }

    std::shared_ptr<UIElement>& GUI::getElementByID(const std::string& id)
    {
        for(auto& element : elements)
        {
            if(element->getID() == id)
            {
                return element;
            }
        };
        throw std::invalid_argument("Provided ID does not match with any element. \n getElementByID([?] <- Invalid ID)");
    }

    std::shared_ptr<Input> &GUI::getInputByID(const std::string &id)
    {
        for( auto& element : elements)
        {
            if(element->getID() == id)
            {
                // Verify the element can be cast to Input
                if (std::dynamic_pointer_cast<Input>(element)) {
                    return reinterpret_cast<std::shared_ptr<Input>&>(element);
                }
                throw std::invalid_argument("Cast failed, getInputByID | GUI.cpp)");
            }
        };
        throw std::invalid_argument("Provided ID does not match with any element. \n getInputByID([?] <- Invalid ID)");
    }

    std::shared_ptr<Button> &GUI::getButtonByID(const std::string &id)
    {
        for( auto& element : elements)
        {
            if(element->getID() == id)
            {
                // Verify the element can be cast to Input
                if (std::dynamic_pointer_cast<Button>(element)) {
                    return reinterpret_cast<std::shared_ptr<Button>&>(element);
                }
                throw std::invalid_argument("Cast failed, getButtonByID | GUI.cpp)");
            }
        };
        throw std::invalid_argument("Provided ID does not match with any element. \n getButtonByID([?] <- Invalid ID)");
    }

    std::shared_ptr<Checkbox> &GUI::getCheckboxByID(const std::string &id)
    {
        for( auto& element : elements)
        {
            if(element->getID() == id)
            {
                // Verify the element can be cast to Checkbox
                if (std::dynamic_pointer_cast<Checkbox>(element)) {
                    return reinterpret_cast<std::shared_ptr<Checkbox>&>(element);
                }
                throw std::invalid_argument("Cast failed, getCheckboxByID | GUI.cpp)");
            }
        };
        throw std::invalid_argument("Provided ID does not match with any element. \n getCheckboxByID([?] <- Invalid ID)");
    }


}
