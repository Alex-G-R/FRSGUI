#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include "../Utility/Style.h"
#include <string>
#include <map>

namespace fr::Rendering {

class StyleManager {
public:
    StyleManager();
    Style getStyle(const std::string& groupName);
    std::map<std::string, Style> style_sheet;
};

}

#endif //STYLEMANAGER_H