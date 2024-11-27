#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include "SFML/Graphics.hpp"
#include "../UIElement.h"
#include "../uielement_derived/Input.h"
#include <memory>


namespace fr {

class EventDispatcher {
public:
    explicit EventDispatcher(std::vector<std::shared_ptr<UIElement>>& elements_ptr, FRSGUI* frsgui_ptr);
    void dispatchEvent(const sf::Event& event);
    void deselectInputs();

    FRSGUI* frsgui_ptr{};
private:
    std::vector<std::shared_ptr<UIElement>>& elements_ptr;
    std::vector<std::shared_ptr<Input>> getInputElements();

    void HandleLeftMouseButtonClick(const sf::Event& event);
    void HandleTextEnterd(const sf::Event& event);
};

}

#endif //EVENTDISPATCHER_H
