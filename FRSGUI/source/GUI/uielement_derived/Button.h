#ifndef BUTTON_H
#define BUTTON_H

#include "../../core/FRSGUI.h"
#include "../../GUI/UIElement.h"
#include <functional>

namespace fr {

class Button : public UIElement {
private:
    std::function<void()> onClickCallback; // Callback function for click events

public:
    // Constructor
    explicit Button(const std::shared_ptr<Renderer>& renderer_ptr);
    Button(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups);
    Button(const std::shared_ptr<Renderer>& renderer_ptr, std::initializer_list<std::string> groups);
    Button(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID);

   // Set the click callback function
   void setOnClick(const std::function<void()>& callback);

   // Method to handle click events (this can be called in your Update method)
   void click();
};


}

#endif //BUTTON_H
