#include "EventDispatcher.h"
#include <iostream>

namespace fr::Events {
    EventDispatcher::EventDispatcher(std::vector<std::shared_ptr<UI_element> > &elements_ptr) :
    elements_ptr(elements_ptr)
    {

    }

    void EventDispatcher::dispatchEvent(const sf::Event &event)
    {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "Left clicked! \n";
            std::cout << "MouseX: " << event.mouseButton.x << ", MouseY: " << event.mouseButton.y << "\n";
            for(const auto& element : elements_ptr)
            {
                // Check if the mouse is within the rectangle's bounds
                if (element->getShape()->getGlobalBounds().contains(static_cast<float>(event.mouseButton.x) ,static_cast<float>(event.mouseButton.y)))
                {
                    // Rectangle has been clicked
                    std::cout << "CONTACT \n";
                }
            }
        }
    }


}