#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <vector>
#include <Graphics.hpp>
#include <string>
#include <utility>

namespace fr::Utils {

class ResourceManager
{
    std::vector<std::pair<std::string, sf::Font>> fonts;
public:
    void add_font(const std::string& font_alias, const std::string& path);
    sf::Font& get_font(const std::string& font_alias);
};

}

#endif //RESOURCEMANAGER_H
