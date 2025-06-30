#include "EventDispatcher.h"

#include <iostream>

#include "../uielement_derived/Button.h"
#include "../uielement_derived/Checkbox.h"
#include "../../core/FRSGUI.h"

namespace fr {
    EventDispatcher::EventDispatcher(std::vector<std::shared_ptr<UIElement> > &elements_ptr, FRSGUI* frsgui_ptr) :
    elements_ptr(elements_ptr), frsgui_ptr(frsgui_ptr)
    {

    }

    void EventDispatcher::dispatchEvent(const std::optional<sf::Event> &event)
    {
        if (!event.has_value()) {
            return;
        }

        const sf::Event& actualEvent = event.value(); // Or *event

        if (const auto* mouseButtonEvent = actualEvent.getIf<sf::Event::MouseButtonPressed>()) {
            if (mouseButtonEvent->button == sf::Mouse::Button::Left) {
                HandleLeftMouseButtonClick(*mouseButtonEvent); // Pass the actual struct
            }
        }
        else if(const auto* textEnteredEvent = actualEvent.getIf<sf::Event::TextEntered>())
        {
            HandleTextEnterd(*textEnteredEvent);
        }
    }

    void EventDispatcher::HandleTextEnterd(const sf::Event::TextEntered &event)
    {
        // Search for a selected input field and if found send in the unicode data from the event
        for(const auto& input : getInputElements())
        {
            if(input->getSelect() == true)
            {
                //std::cout << "Text Entered (Unicode value): " << static_cast<uint32_t>(event.unicode) << std::endl;

                if(event.unicode < 128)
                {
                    input->pushData(event.unicode);
                }
            }
        }
    }


    void EventDispatcher::HandleLeftMouseButtonClick(const sf::Event::MouseButtonPressed &event)
    {
        bool input_selected = false;

        for(const auto& element : elements_ptr)
        {
            // Check if the mouse is within the rectangle's bounds
            if (element->getShape()->getGlobalBounds().contains(sf::Vector2f(static_cast<float>(event.position.x) ,static_cast<float>(event.position.y))))
            {
                if(auto* input = dynamic_cast<Input*>(element.get()))
                {
                    if(input->getSelect() == false)
                    {
                        deselectInputs();
                        input->setSelect(true);
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

                // Attempt to dynamically cast the UI_element to a Checkbox
                if (auto* checkbox = dynamic_cast<Checkbox*>(element.get())) {
                    // The element is a Checkbox - so update the select status
                    if(checkbox->getSelect() == false)
                    {
                        checkbox->setSelect(true);
                        break;
                    }
                    if(checkbox->getSelect() == true)
                    {
                        checkbox->setSelect(false);
                        break;
                    }
                }
            }
        }

        // If no input was selected and a button was clicked or clicked outside any element
        if (!input_selected) {
            deselectInputs();  // Deselect all inputs if none were selected in event
        }
    }


    void EventDispatcher::deselectInputs()
    {
        for(const auto& input : getInputElements())
        {
            if(input->getSelect() == true)
            {
                input->setSelect(false);
                return;
            }
        }
    }

    std::vector<std::shared_ptr<Input>> EventDispatcher::getInputElements()
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