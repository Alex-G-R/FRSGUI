
#ifndef INPUT_H
#define INPUT_H
#include "../UI_element.h"

namespace fr
{
class Input : public UI_element{
private:
    bool selected;

public:
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr);

    void set_select(bool selected);
    bool get_select();
};
}


#endif //INPUT_H
