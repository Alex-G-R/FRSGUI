#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include "../Utility/Style.h"
#include <map>

namespace fr::Rendering {

class StyleManager {

private:
    std::map<std::string, Utils::Style> style_sheet;
public:
    StyleManager();
    Utils::Style getStyle(const std::string& groupName);
};

}

#endif //STYLEMANAGER_H