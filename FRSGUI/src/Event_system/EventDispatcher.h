#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include "SFML/Graphics.hpp"
#include "../Core/UI_element.h"
#include "../Core/UI_element_derived/Input.h"
#include <memory>


namespace fr::Events {

class EventDispatcher {
public:
    explicit EventDispatcher(std::vector<std::shared_ptr<UI_element>>& elements_ptr, FRSGUI* frsgui_ptr);
    void dispatchEvent(const sf::Event& event);

    void deselect_inputs();

    FRSGUI* frsgui_ptr{};
private:
    std::vector<std::shared_ptr<UI_element>>& elements_ptr;
    std::vector<std::shared_ptr<Input>> get_input_elements();
};

}

#endif //EVENTDISPATCHER_H
