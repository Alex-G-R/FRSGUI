
#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <memory>
#include "../Core/FRSGUI.h"

/* Raw Ui_element and overloads with group declaration built-in */
inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer> &renderer) {
    return std::make_shared<fr::UI_element>(renderer);
}
inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, const std::initializer_list<std::string>& groups) {
    auto UI_element_instance = std::make_shared<fr::UI_element>(renderer, std::move(ID), groups);
    return UI_element_instance;
}
inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID) {
    auto UI_element_instance = std::make_shared<fr::UI_element>(renderer, std::move(ID));
    return UI_element_instance;
}
inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer>& renderer, const std::initializer_list<std::string>& groups) {
    auto UI_element_instance = std::make_shared<fr::UI_element>(renderer, groups);
    return UI_element_instance;
}
// FRSGUI overloads
inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer> &renderer, fr::FRSGUI& frsgui) {
    auto UI_element_instance = std::make_shared<fr::UI_element>(renderer);
    frsgui.addElement(UI_element_instance);
    return std::make_shared<fr::UI_element>(renderer);
}
inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, const std::initializer_list<std::string>& groups, fr::FRSGUI& frsgui) {
    auto UI_element_instance = std::make_shared<fr::UI_element>(renderer, std::move(ID), groups);
    frsgui.addElement(UI_element_instance);
    return UI_element_instance;
}
inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, fr::FRSGUI& frsgui) {
    auto UI_element_instance = std::make_shared<fr::UI_element>(renderer, std::move(ID));
    frsgui.addElement(UI_element_instance);
    return UI_element_instance;
}
inline std::shared_ptr<fr::UI_element> UI_element(const std::shared_ptr<fr::Rendering::Renderer>& renderer, const std::initializer_list<std::string>& groups, fr::FRSGUI& frsgui) {
    auto UI_element_instance = std::make_shared<fr::UI_element>(renderer, groups);
    frsgui.addElement(UI_element_instance);
    return UI_element_instance;
}


/* Button and overloads with group declaration built-in */
inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer> &renderer) {
    return std::make_shared<fr::Button>(renderer);
}
inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, const std::initializer_list<std::string>& groups) {
    auto Button_element_instance = std::make_shared<fr::Button>(renderer, std::move(ID), groups);
    return Button_element_instance;
}
inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID) {
    auto Button_element_instance = std::make_shared<fr::Button>(renderer, std::move(ID));
    return Button_element_instance;
}
inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer>& renderer, const std::initializer_list<std::string>& groups) {
    auto Button_element_instance = std::make_shared<fr::Button>(renderer, groups);
    return Button_element_instance;
}
// FRSGUI overloads
inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer> &renderer, fr::FRSGUI& frsgui) {
    auto Button_element_instance = std::make_shared<fr::Button>(renderer);
    frsgui.addElement(Button_element_instance);
    return Button_element_instance;
}
inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, const std::initializer_list<std::string>& groups, fr::FRSGUI& frsgui) {
    auto Button_element_instance = std::make_shared<fr::Button>(renderer, std::move(ID), groups);
    frsgui.addElement(Button_element_instance);
    return Button_element_instance;
}
inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, fr::FRSGUI& frsgui) {
    auto Button_element_instance = std::make_shared<fr::Button>(renderer, std::move(ID));
    frsgui.addElement(Button_element_instance);
    return Button_element_instance;
}
inline std::shared_ptr<fr::Button> Button(const std::shared_ptr<fr::Rendering::Renderer>& renderer, const std::initializer_list<std::string>& groups, fr::FRSGUI& frsgui) {
    auto Button_element_instance = std::make_shared<fr::Button>(renderer, groups);
    frsgui.addElement(Button_element_instance);
    return Button_element_instance;
}


/* Input and Input overload for numeric only and overloads with group declaration built-in */
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer> &renderer) {
    return std::make_shared<fr::Input>(renderer);
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, const std::initializer_list<std::string>& groups) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, std::move(ID), groups);
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, std::move(ID));
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, const std::initializer_list<std::string>& groups) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, groups);
    return Input_element_instance;
}
// Number only
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer> &renderer, bool is_numerical_only) {
    return std::make_shared<fr::Input>(renderer, is_numerical_only);
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, bool is_numerical_only, std::string ID, const std::initializer_list<std::string>& groups) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, is_numerical_only, std::move(ID), groups);
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, bool is_numerical_only, std::string ID) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, is_numerical_only, std::move(ID));
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, bool is_numerical_only, const std::initializer_list<std::string>& groups) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, is_numerical_only, groups);
    return Input_element_instance;
}

// frsgui overload
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer> &renderer, fr::FRSGUI& frsgui) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer);
    frsgui.addElement(Input_element_instance);
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, const std::initializer_list<std::string>& groups, fr::FRSGUI& frsgui) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, std::move(ID), groups);
    frsgui.addElement(Input_element_instance);
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, std::string ID, fr::FRSGUI& frsgui) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, std::move(ID));
    frsgui.addElement(Input_element_instance);
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, const std::initializer_list<std::string>& groups, fr::FRSGUI& frsgui) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, groups);
    frsgui.addElement(Input_element_instance);
    return Input_element_instance;
}
// number only frsgui
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer> &renderer, bool is_numerical_only, fr::FRSGUI& frsgui) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, is_numerical_only);
    frsgui.addElement(Input_element_instance);
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, bool is_numerical_only, std::string ID, const std::initializer_list<std::string>& groups, fr::FRSGUI& frsgui) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, is_numerical_only, std::move(ID), groups);
    frsgui.addElement(Input_element_instance);
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, bool is_numerical_only, std::string ID, fr::FRSGUI& frsgui) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, is_numerical_only, std::move(ID));
    frsgui.addElement(Input_element_instance);
    return Input_element_instance;
}
inline std::shared_ptr<fr::Input> Input(const std::shared_ptr<fr::Rendering::Renderer>& renderer, bool is_numerical_only, const std::initializer_list<std::string>& groups, fr::FRSGUI& frsgui) {
    auto Input_element_instance = std::make_shared<fr::Input>(renderer, is_numerical_only, groups);
    frsgui.addElement(Input_element_instance);
    return Input_element_instance;
}


/* Style block */
inline std::shared_ptr<fr::Style> Style(std::string style_name, fr::ApplyBy styletype, int style_priority,std::initializer_list<std::pair<fr::KEY, fr::type>> init, fr::FRSGUI& frsgui)
{
    auto my_instance = std::make_shared<fr::Style>(init);

    frsgui.addStyle(std::move(style_name), my_instance, styletype, style_priority);

    return my_instance;
}


#endif //HELPERFUNCTIONS_H
