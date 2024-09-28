#include "GUI.h"

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
    }

}