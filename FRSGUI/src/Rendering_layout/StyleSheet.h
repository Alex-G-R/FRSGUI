#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <string>

#include "../Utility/Style.h"

enum class StyleType
{
    ID,
    CLASS
};

namespace fr::Rendering {

    class StyleSheet {
    public:
        StyleSheet();
        std::string group_name;
        Style style;
        StyleType style_type;
        int style_priority;
    };

}


#endif //STYLESHEET_H
