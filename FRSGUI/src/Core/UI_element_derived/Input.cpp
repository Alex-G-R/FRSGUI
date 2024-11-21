
#include "Input.h"

#include <iostream>

fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr)
        : UI_element(renderer_ptr)
{
        is_number_only_input = false;
        selected = false;
        stored_data = "";
        has_cursor = true;
}

fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, std::string ID)
        : UI_element(renderer_ptr, std::move(ID))
{
        is_number_only_input = false;
        selected = false;
        stored_data = "";
        has_cursor = true;
}

fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, std::initializer_list<std::string> groups)
    : UI_element(renderer_ptr, groups)
{
        is_number_only_input = false;
        selected = false;
        stored_data = "";
        has_cursor = true;
}

fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups)
    : UI_element(renderer_ptr, std::move(ID), groups)
{
        is_number_only_input = false;
        selected = false;
        stored_data = "";
        has_cursor = true;
}


fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input)
        : UI_element(renderer_ptr), is_number_only_input(is_number_only_input)
{
        selected = false;
        stored_data = "";
        has_cursor = true;
}

fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input, std::string ID)
        : UI_element(renderer_ptr, std::move(ID)), is_number_only_input(is_number_only_input)
{
        selected = false;
        stored_data = "";
        has_cursor = true;
}

fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input, std::initializer_list<std::string> groups)
    : UI_element(renderer_ptr, groups), is_number_only_input(is_number_only_input)
{
        selected = false;
        stored_data = "";
        has_cursor = true;
}

fr::Input::Input(const std::shared_ptr<Rendering::Renderer>& renderer_ptr, bool is_number_only_input, std::string ID, std::initializer_list<std::string> groups)
    : UI_element(renderer_ptr, std::move(ID), groups), is_number_only_input(is_number_only_input)
{
        selected = false;
        stored_data = "";
        has_cursor = true;
}

void fr::Input::push_data(sf::Uint32 char_to_add_unicode)
{
        // Ignore enter
        if(char_to_add_unicode == 13)
                return;

        // Handle backspace
        if(stored_data.length() > 0 && char_to_add_unicode == 8)
        {
                stored_data.pop_back();
                std::cout << stored_data << "\n";
                setTextString(stored_data);
                return;
        }

        if(stored_data.length() == 0 && char_to_add_unicode == 8)
                return;

        if(this->is_number_only_input)
        {
                // Check if char is a number
                if(char_to_add_unicode > 46 && char_to_add_unicode < 58)
                {
                        stored_data += static_cast<char>(char_to_add_unicode);
                        std::cout << stored_data << "\n";
                        setTextString(stored_data);
                }
        }
        else
        {
                stored_data += static_cast<char>(char_to_add_unicode);
                std::cout << stored_data << "\n";
                setTextString(stored_data);
        }
}

std::string fr::Input::get_data()
{
    return stored_data;
}


void fr::Input::set_select(bool selected)
{
    std::cout << "Select changed to " << selected << " from " << this->selected << "\n";
    this->selected = selected;
}

bool fr::Input::get_select()
{
    return this->selected;
}

