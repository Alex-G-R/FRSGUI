#include "FRSGUI.h"

namespace fr {
    FRSGUI::FRSGUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr) :
    gui(render_window_ptr, renerer_ptr), render_window_ptr(render_window_ptr), renderer(render_window_ptr)
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

    void FRSGUI::addElement(const std::shared_ptr<UI_element>& element)
    {
        gui.addElement(element);
    }

    std::shared_ptr<Rendering::Renderer> FRSGUI::getRenderer()
    {
        return renerer_ptr;
    }

}