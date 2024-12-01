#include "FRSGUI.h"

namespace fr {
    FRSGUI::FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr) :
    gui(render_window_ptr, renerer_ptr), event_dispatcher(gui.elements, this), render_window_ptr(render_window_ptr),
    renderer(render_window_ptr, this), style_sheet(style_manager.style_sheet)
    {
        render_window_ptr->setFramerateLimit(75);
    }

    void FRSGUI::Render()
    {
        gui.render();
    }


    // Getters
    std::shared_ptr<Renderer> FRSGUI::getRenderer()
    {
        return renerer_ptr;
    }

    // GUI public methods acces
    void FRSGUI::addElement(const std::shared_ptr<UIElement>& element)
    {
        gui.addElement(element);
    }

    void FRSGUI::addStyle(std::string group_name, std::shared_ptr<fr::Style> style, const ApplyBy style_type, const int style_priority)
    {
        style_sheet.addStyleVec(StyleVec(std::move(group_name), style, style_type, style_priority));
    }

    void FRSGUI::dispatchEvent(const sf::Event &event)
    {
        event_dispatcher.dispatchEvent(event);
    }

    std::shared_ptr<UIElement>& FRSGUI::getUIElementByID(const std::string &id)
    {
        return gui.getElementByID(id);
    }

    std::shared_ptr<Input> &FRSGUI::getInputByID(const std::string &id)
    {
        return gui.getInputByID(id);
    }

    std::shared_ptr<Button> &FRSGUI::getButtonByID(const std::string &id)
    {
        return gui.getButtonByID(id);
    }

    std::shared_ptr<Checkbox> &FRSGUI::getCheckboxByID(const std::string &id)
    {
        return gui.getCheckboxByID(id);
    }

    void FRSGUI::addFont(const std::string &font_alias, const std::string &path)
    {
        resource_manager.addFont(font_alias, path);
    }

    sf::Font &FRSGUI::getFont(const std::string &font_alias)
    {
        return resource_manager.getFont(font_alias);
    }


}