
#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <memory>
#include "../Core/FRSGUI.h"

inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer> &renderer) {
    return std::make_shared<fr::UI_element>(renderer);
}

inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer> &renderer) {
    return std::make_shared<fr::Button>(renderer);
}

inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer> &renderer) {
    return std::make_shared<fr::Input>(renderer);
}

inline std::shared_ptr<fr::Style> Style(std::string style_name, fr::ApplyBy styletype, int style_priority,std::initializer_list<std::pair<fr::KEY, fr::type>> init, fr::FRSGUI& frsgui)
{
    auto my_instance = std::make_shared<fr::Style>(init);

    frsgui.addStyle(std::move(style_name), my_instance, styletype, style_priority);

    return my_instance;
}


#endif //HELPERFUNCTIONS_H
