#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "../../GUI/UIElement.h"

namespace fr {

class Checkbox : public UIElement{

    sf::RectangleShape select_mark;

public:

    explicit Checkbox(const std::shared_ptr<Renderer>& renderer_ptr);

    void Render() override;

    void setSelect(bool selected);

    // Returns the select status of the checkbox | The same as getData()
    bool getSelect();

    // Returns the select status of the checkbox | The same as getSelect()
    bool getData();

};

} // fr

#endif //CHECKBOX_H
