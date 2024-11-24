
#ifndef UI_ELEMENT_OVERLOADS_H
#define UI_ELEMENT_OVERLOADS_H
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

#endif //UI_ELEMENT_OVERLOADS_H
