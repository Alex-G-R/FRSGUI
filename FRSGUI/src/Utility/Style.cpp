
#include "Style.h"

namespace fr {

    Style::Style(std::initializer_list<std::pair<KEY, type>> init)
    {
        createFlags();

        for(const auto& [key, value] : init)
        {
            properties[key] = value;

            // If the key is found in the flags map set its value to true
            if (flags.find(key) != flags.end()) {
                flags[key] = true;
            }
        }
    }

    void Style::createFlags()
    {
        for(int key_int = static_cast<int>(KEY::POSITION); key_int < static_cast<int>(KEY::DEVEL_LAST_KEY); ++key_int)
        {
            auto key = static_cast<KEY>(key_int);
            flags.emplace(key, false);
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

    void Style::updateStyle(std::initializer_list<std::pair<KEY, type> > init)
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