#include "UI_element.h"

namespace fr {

    UI_element::UI_element(const std::shared_ptr<Rendering::Renderer> &renderer_ptr):
    renderer_ptr(renderer_ptr)
    {

    }


    void UI_element::Render()
    {
        renderer_ptr->draw(this);
    }

}