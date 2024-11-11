#include "EventDispatcher.h"

#include <iostream>

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
            Handle_LeftMouseButtonClick(event);
        }
        else if(event.type == sf::Event::TextEntered)
        {
            Handle_TextEnterd(event);
        }
    }

    void EventDispatcher::Handle_TextEnterd(const sf::Event &event)
    {
        for(const auto& input : get_input_elements())
        {
            if(input->get_select() == true)
            {
                if(event.text.unicode < 128)
                {
                    input->push_data(event.text.unicode);
                }
            }
        }
    }


    void EventDispatcher::Handle_LeftMouseButtonClick(const sf::Event &event)
    {
        bool input_selected = false;

        for(const auto& element : elements_ptr)
        {
            // Check if the mouse is within the rectangle's bounds
            if (element->getShape()->getGlobalBounds().contains(static_cast<float>(event.mouseButton.x) ,static_cast<float>(event.mouseButton.y)))
            {
                if(auto* input = dynamic_cast<Input*>(element.get()))
                {
                    if(input->get_select() == false)
                    {
                        input->set_select(true);
                        input_selected = true;
                        break;
                    }
                }

                // Attempt to dynamically cast the UI_element to a Button
                if (auto* button = dynamic_cast<Button*>(element.get())) {
                    // The element is a Button - so call the click function
                    button->click();
                    break;
                }
            }
        }

        // If no input was selected and a button was clicked or clicked outside any element
        if (!input_selected) {
            deselect_inputs();  // Deselect all inputs if none were selected in event
        }
    }


    void EventDispatcher::deselect_inputs()
    {
        for(const auto& input : get_input_elements())
        {
            if(input->get_select() == true)
            {
                input->set_select(false);
                return;
            }
        }
    }

    std::vector<std::shared_ptr<Input>> EventDispatcher::get_input_elements()
    {
        std::vector<std::shared_ptr<Input>> input_elements;

        for(const auto& element : elements_ptr)
        {
            // Try to cast the element to Input type
            if(auto input_ptr = std::dynamic_pointer_cast<Input>(element))
            {
                input_elements.push_back(input_ptr); // only add if of the Input type
            }
        }

        return input_elements;
    }

}