#include "FRSGUI.h"

namespace fr {
    FRSGUI::FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr) :
    gui(render_window_ptr, renerer_ptr), render_window_ptr(render_window_ptr),
    renderer(render_window_ptr, this), style_sheet(style_manager.style_sheet)
    {
    }

    void FRSGUI::Initialize()
    {

    }

    void FRSGUI::Update()
    {

    }

    void FRSGUI::Render()
    {
        render_window_ptr->clear();

        gui.Render();

        render_window_ptr->display();
    }

    void FRSGUI::Run()
    {
        Initialize();

        while(render_window_ptr->isOpen())
        {
            sf::Event event{};
            while(render_window_ptr->pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    render_window_ptr->close();
            }

            Update();
            Render();
        }
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

    void FRSGUI::addStyleVec(std::string group_name, const Style& style, const StyleType style_type, const int style_priority)
    {
        style_sheet.addStyleVec(StyleVec(std::move(group_name), style, style_type, style_priority));
    }
}