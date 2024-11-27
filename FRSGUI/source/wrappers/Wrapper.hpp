
#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <memory>
#include "../core/FRSGUI.h"

/* Raw Ui_element and overloads with group declaration built-in */
#include "constructor_overloads/UIElementOverloads.h"

/* Button and overloads with group declaration built-in */
#include "constructor_overloads/ButtonOverloads.h"

/* Input and Input overload for numeric only and overloads with group declaration built-in */
#include "constructor_overloads/InputOverloads.h"

/* Style block */
inline std::shared_ptr<fr::Style> Style(std::string style_name, fr::ApplyBy styletype, int style_priority,std::initializer_list<std::pair<fr::KEY, fr::type>> init, fr::FRSGUI& frsgui)
{
    auto my_instance = std::make_shared<fr::Style>(init);

    frsgui.addStyle(std::move(style_name), my_instance, styletype, style_priority);

    return my_instance;
}


#endif //HELPERFUNCTIONS_H
