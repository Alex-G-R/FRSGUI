
#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <memory>
#include "../Core/FRSGUI.h"

inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer> &renderer) {
    return std::make_shared<fr::UI_element>(renderer);
}



#endif //HELPERFUNCTIONS_H