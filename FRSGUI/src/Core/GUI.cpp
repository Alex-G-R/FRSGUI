#include "GUI.h"

#include "UI_element_derived/Input.h"


namespace fr {
    GUI::GUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr, const std::shared_ptr<Rendering::Renderer>& renderer_ptr) :
    render_window_ptr(render_window_ptr), renderer_ptr(renderer_ptr)
    {

    }

    void GUI::Render()
    {
        for(const auto& element : elements)
        {
            element->Render();
        }
    }

    void GUI::Update()
    {

    }

    void GUI::addElement(const std::shared_ptr<UI_element>& element)
    {
        elements.emplace_back(element);
    }

    std::shared_ptr<UI_element>& GUI::getElementByID(const std::string& id)
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
                    // Cast the reference to the original shared_ptr<UI_element>
                    return reinterpret_cast<std::shared_ptr<Input>&>(element);
                }
                throw std::invalid_argument("Cast failed, getInputByID | GUI.cpp)");
            }
        };
        throw std::invalid_argument("Provided ID does not match with any element. \n getInputByID([?] <- Invalid ID)");
    }


}
