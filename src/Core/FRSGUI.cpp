#include "FRSGUI.h"

namespace fr {
    FRSGUI::FRSGUI(sf::RenderWindow* render_window_ptr)
    {
        this->render_window_ptr = render_window_ptr;
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
}