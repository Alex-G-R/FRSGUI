#include "Button.h"

namespace fr {

    Button::Button(const std::shared_ptr<Rendering::Renderer>& renderer_ptr)
        : UI_element(renderer_ptr)
    {

    }

    Button::~Button() {}

    void Button::Render() {
        UI_element::Render();
    }


    void Button::Update() {
        UI_element::Update();
    }

    // Set the click callback function
    void Button::setOnClick(const std::function<void(const FRSGUI& frsgui)>& callback) {
        onClickCallback = callback; // Store the callback
    }

    void Button::click(const FRSGUI& frsgui) {
        if (onClickCallback) { // Check if a callback is set
            onClickCallback(frsgui); // Call the stored callback
        }
    }
}