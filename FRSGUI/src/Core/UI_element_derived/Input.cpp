
#include "Input.h"

#include <iostream>

fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr)
        : UI_element(renderer_ptr)
{
        selected = false;
}

void fr::Input::set_select(bool selected)
{
        std::cout << "Select changed to " << selected << " from " << this->selected << "\n";
        this->selected = selected;
}

bool fr::Input::get_select()
{
        return this->selected;
}

