#include "EventDispatcher.h"

#include "../Core/UI_element_derived/Button.h"
#include "../Core/FRSGUI.h"

namespace fr::Events {
    EventDispatcher::EventDispatcher(std::vector<std::shared_ptr<UI_element> > &elements_ptr, FRSGUI* frsgui_ptr) :
    elements_ptr(elements_ptr), frsgui_ptr(frsgui_ptr)
    {

    }

    void EventDispatcher::dispatchEvent(const sf::Event &event)
    {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            for(const auto& element : elements_ptr)
            {
                // Check if the mouse is within the rectangle's bounds
                if (element->getShape()->getGlobalBounds().contains(static_cast<float>(event.mouseButton.x) ,static_cast<float>(event.mouseButton.y)))
                {
                    // Attempt to dynamically cast the UI_element to a Button
                    if (auto* button = dynamic_cast<Button*>(element.get())) {
                        // The element is a Button - so call the click function
                        button->click(); // Calls Button's click() method
                    }
                }
            }
        }
    }


}