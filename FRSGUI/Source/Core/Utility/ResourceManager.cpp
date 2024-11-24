#include "ResourceManager.h"
#include <iostream>
#include <filesystem>

namespace fr {

    void ResourceManager::addFont(const std::string& font_alias, const std::string& path)
    {
        sf::Font font;
        if (!font.loadFromFile(path)) {
            // Attempt to load using the absolute path
            auto absolute_path = (std::filesystem::current_path()).string() + path;
            if (!font.loadFromFile(absolute_path)) {
                std::cout << "path: " << absolute_path << "\n";
                std::cout << "Font loading error | invalid path | FRSGUI ResourceManager error \n";
                return;
            }
        }
        fonts.emplace_back(font_alias,font);
    }

    sf::Font &ResourceManager::getFont(const std::string &font_alias)
    {
        for (auto& font : fonts)
        {
            if(font.first == font_alias)
            {
                return font.second;
            }
        }
        std::__throw_invalid_argument("Invalid font alias, font not found | get_font() | FRSGUI error \n");
    }


}