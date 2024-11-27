
#ifndef INPUT_H
#define INPUT_H
#include "../../GUI/UIElement.h"
#include <sstream>
#include <stdexcept>

namespace fr
{
class Input : public UIElement{
private:
    // Numeric flag
    bool is_number_only_input;

    std::string stored_data;

    sf::Font font;

    sf::Text displayd_text;

public:
    Input(const std::shared_ptr<Renderer>& renderer_ptr);
    Input(const std::shared_ptr<Renderer>& renderer_ptr, bool is_number_only_input);

    Input(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups);
    Input(const std::shared_ptr<Renderer>& renderer_ptr, std::initializer_list<std::string> groups);
    Input(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID);

    Input(const std::shared_ptr<Renderer>& renderer_ptr, bool is_number_only_input, std::string ID, std::initializer_list<std::string> groups);
    Input(const std::shared_ptr<Renderer>& renderer_ptr, bool is_number_only_input, std::initializer_list<std::string> groups);
    Input(const std::shared_ptr<Renderer>& renderer_ptr, bool is_number_only_input, std::string ID);

    void setSelect(bool selected);
    bool getSelect();
    void pushData(sf::Uint32 char_to_add);

    template <typename T>
    T getDataAs()
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
    std::string getData() {
        return stored_data;
    }
};
}


#endif //INPUT_H
