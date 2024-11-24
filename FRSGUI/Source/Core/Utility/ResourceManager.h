#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <vector>
#include <Graphics.hpp>
#include <string>
#include <utility>

namespace fr {

class ResourceManager
{
    std::vector<std::pair<std::string, sf::Font>> fonts;
public:
    void addFont(const std::string& font_alias, const std::string& path);
    sf::Font& getFont(const std::string& font_alias);
};

}

#endif //RESOURCEMANAGER_H
