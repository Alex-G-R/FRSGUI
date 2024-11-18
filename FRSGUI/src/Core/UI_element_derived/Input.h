
#ifndef INPUT_H
#define INPUT_H
#include "../UI_element.h"

namespace fr
{
class Input : public UI_element{
private:
    // Numeric flag
    bool is_number_only_input;

    std::string stored_data;

    sf::Font font;

    sf::Text displayd_text;

public:
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr);
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input);

    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups);
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, std::initializer_list<std::string> groups);
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, std::string ID);

    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input, std::string ID, std::initializer_list<std::string> groups);
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input, std::initializer_list<std::string> groups);
    Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input, std::string ID);


    void load_text();

    void set_select(bool selected);
    bool get_select();

    void push_data(sf::Uint32 char_to_add);
    std::string get_data();
};
}


#endif //INPUT_H
