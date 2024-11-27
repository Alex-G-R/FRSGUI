
#ifndef STYLEVEC_H
#define STYLEVEC_H

#include <string>
#include <memory>

#include "Style.h"
#include "./enums/ApplyBy.h"

namespace fr
{

class StyleVec {
public:
    StyleVec(std::string group_name, std::shared_ptr<Style> style, ApplyBy style_type, int style_priority);
    std::string group_name;
    std::shared_ptr<fr::Style> style;
    ApplyBy style_type;
    int style_priority;
};

}

#endif //STYLEVEC_H
