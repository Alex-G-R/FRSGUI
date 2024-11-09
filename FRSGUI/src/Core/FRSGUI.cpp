#include "FRSGUI.h"

namespace fr {
    FRSGUI::FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr) :
    gui(render_window_ptr, renerer_ptr), event_dispatcher(gui.elements, this), render_window_ptr(render_window_ptr),
    renderer(render_window_ptr, this), style_sheet(style_manager.style_sheet)
    {
        render_window_ptr->setFramerateLimit(120);
    }

    void FRSGUI::Render()
    {
        gui.Render();
    }


    // Getters
    std::shared_ptr<Rendering::Renderer> FRSGUI::getRenderer()
    {
        return renerer_ptr;
    }

    // GUI public methods acces
    void FRSGUI::addElement(const std::shared_ptr<UI_element>& element)
    {
        gui.addElement(element);
    }

    void FRSGUI::addStyle(std::string group_name, std::shared_ptr<fr::Style> style, const StyleType style_type, const int style_priority)
    {
        style_sheet.addStyleVec(StyleVec(std::move(group_name), style, style_type, style_priority));
    }

    void FRSGUI::dispatchEvent(const sf::Event &event)
    {
        event_dispatcher.dispatchEvent(event);
    }

    std::shared_ptr<UI_element>& FRSGUI::getElementByID(const std::string &id)
    {
        return gui.getElementByID(id);
    }

}