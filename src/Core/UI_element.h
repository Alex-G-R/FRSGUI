#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <Graphics.hpp>
#include "../Rendering_layout/Renderer.h"
#include <memory>

class GUI;

namespace fr {

class UI_element {
    /*
    Role: Base class for all UI components. Manages common properties like position, size, visibility, and styling.


    Key Properties:
        std::string id: Unique identifier.
        std::vector<std::string> classes: List of class names for styling.
        std::vector<std::shared_ptr<UI_element>> children: Child elements for hierarchical structure.
        bool visible: Determines if the element is rendered.
        int zOrder: Determines rendering order.
        bool dirty: Indicates if the element needs to be updated.

    Key Methods:
        virtual void render(): Renders the element (to be overridden by derived classes).
        virtual void update(): Updates the element (to be overridden by derived classes).
        virtual void onEvent(const Event& event): Handles events (to be overridden by derived classes).
        addChild(std::shared_ptr<UI_element> child): Adds a child element.
     */

private:
    std::shared_ptr<Rendering::Renderer> renderer_ptr{};

public:
    explicit UI_element(const std::shared_ptr<Rendering::Renderer>& renderer_ptr);
    sf::RectangleShape shape;
    void Render();
};

}

#endif //UI_ELEMENT_H
