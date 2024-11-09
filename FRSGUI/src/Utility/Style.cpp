
#include "Style.h"

namespace fr {

    Style::Style(std::initializer_list<std::pair<KEY, type>> init)
    {
        for(const auto& [key, value] : init)
        {
            properties[key] = value;

            // If the key is found in the flags map set its value to true
            if (flags.find(key) != flags.end()) {
                flags[key] = true;
            }
        }
    }

    type Style::getProperty(KEY property_key)
    {
        for(const auto& [key, value] : properties)
        {
            if(property_key == key)
            {
                return value;
            }
        }

        throw std::runtime_error("Property key not found");  // key is not found
    }

    void Style::update_style(std::initializer_list<std::pair<KEY, type> > init)
    {
        for(const auto& [key, value] : init)
        {
            properties[key] = value;

            // If the key is found in the flags map set its value to true
            if (flags.find(key) != flags.end()) {
                flags[key] = true;
            }
        }
    };

}