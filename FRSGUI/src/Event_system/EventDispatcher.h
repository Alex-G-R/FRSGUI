#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include "SFML/Graphics.hpp"
#include "../Core/UI_element.h"
#include <memory>


namespace fr::Events {

class EventDispatcher {
public:
    explicit EventDispatcher(std::vector<std::shared_ptr<UI_element>>& elements_ptr);
    void dispatchEvent(const sf::Event& event);

private:
    std::vector<std::shared_ptr<UI_element>>& elements_ptr;
};

}

#endif //EVENTDISPATCHER_H
