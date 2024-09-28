#ifndef BUTTON_H
#define BUTTON_H

#include "../FRSGUI.h"
#include "../UI_element.h"
#include <functional>

namespace fr {

class Button : public UI_element {
private:
    std::function<void(FRSGUI& frsgui)> onClickCallback; // Callback function for click events

public:
    // Constructor
    Button(const std::shared_ptr<Rendering::Renderer>& renderer_ptr);

    // Destructor
    ~Button() override;

    // Override the Render method if necessary
    void Render() override;

   // Override the Update method if necessary
   void Update() override;

   // Set the click callback function
   void setOnClick(const std::function<void(FRSGUI& frsgui)>& callback);

   // Method to handle click events (this can be called in your Update method)
   void click(FRSGUI& frsgui);
};


}

#endif //BUTTON_H
