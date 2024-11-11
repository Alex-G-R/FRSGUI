
#ifndef INPUT_H
#define INPUT_H
#include "../UI_element.h"

namespace fr
{
class Input : public UI_element{
private:
    // Numeric flag
    bool is_number_only_input;

    bool selected;
    std::string stored_data;

public:
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr);
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input);

    void set_select(bool selected);
    bool get_select();

    void push_data(sf::Uint32 char_to_add);
    std::string get_data();
};
}


#endif //INPUT_H
