
#ifndef STYLEVEC_H
#define STYLEVEC_H

#include <string>

#include "../Utility/Style.h"
#include "../Utility/StyleType.h"

namespace fr
{

class StyleVec {
public:
    StyleVec(std::string group_name, const Style& style, StyleType style_type, int style_priority);
    std::string group_name;
    Style style;
    StyleType style_type;
    int style_priority;
};

}

#endif //STYLEVEC_H
