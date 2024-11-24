
#ifndef INPUT_H
#define INPUT_H
#include "../UI_element.h"
#include <sstream>
#include <stdexcept>

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

    template <typename T>
    T get_data()
    {
        if(stored_data.empty())
            return 0;

        std::istringstream stream(this->stored_data);
        T value;
        if(!(stream >> value))
        {
            throw std::runtime_error("Failed to cast stored_data to the desired type | Input.h");
        }
        return value;
    }

    // Specialization for std::string to avoid stream issues
    std::string get_data() {
        return stored_data;
    }
};
}


#endif //INPUT_H
