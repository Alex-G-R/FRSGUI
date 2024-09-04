#ifndef GUI_H
#define GUI_H

namespace fr {

class GUI {
    /*
    Role: Manages the overall UI. Contains a collection of UI_element objects and handles event propagation, rendering, and updates.

    Key Methods:
        addElement(std::shared_ptr<UI_element> element): Adds a UI_element to the GUI.
        handleEvent(const Event& event): Processes events and dispatches them to the appropriate UI_element.
        render(): Renders all UI elements in the correct order.
        update(): Updates all UI elements as necessary.

     */
};

}

#endif //GUI_H
