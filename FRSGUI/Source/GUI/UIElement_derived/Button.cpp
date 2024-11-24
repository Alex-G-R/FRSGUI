#include "Button.h"

namespace fr {

    Button::Button(const std::shared_ptr<Renderer>& renderer_ptr)
        : UIElement(renderer_ptr)
    {

    }

    Button::Button(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID)
        : UIElement(renderer_ptr, std::move(ID))
    {

    }

    Button::Button(const std::shared_ptr<Renderer>& renderer_ptr, std::initializer_list<std::string> groups)
        : UIElement(renderer_ptr, groups)
    {

    }

    Button::Button(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups)
        : UIElement(renderer_ptr, std::move(ID), groups)
    {

    }

    // Set the click callback function
    void Button::setOnClick(const std::function<void()>& callback) {
        onClickCallback = callback; // Store the callback
    }

    void Button::click() {
        if (onClickCallback) { // Check if a callback is set
            onClickCallback(); // Call the stored callback
        }
    }
}