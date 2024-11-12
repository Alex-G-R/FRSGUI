
#ifndef INPUT_OVERLOADS_H
#define INPUT_OVERLOADS_H
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

#endif
