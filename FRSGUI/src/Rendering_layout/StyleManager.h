#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include "StyleSheet.h"

namespace fr::Rendering {

class StyleManager {
public:
    StyleManager();
    StyleSheet style_sheet;
};

}

#endif //STYLEMANAGER_H