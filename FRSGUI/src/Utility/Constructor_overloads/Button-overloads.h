
#ifndef BUTTON_OVERLOADS_H
#define BUTTON_OVERLOADS_H
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
#endif //BUTTON_OVERLOADS_H
