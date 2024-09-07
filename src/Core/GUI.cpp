#include "GUI.h"

namespace fr {
    GUI::GUI(const std::shared_ptr<sf::RenderWindow>& render_window_ptr) :
    render_window_ptr(render_window_ptr), renderer(render_window_ptr)
    {

    }

    void GUI::Render()
    {
        for(auto& element : elements)
        {
            renderer.draw(element);
        }
    }

    void GUI::Update()
    {

    }

}