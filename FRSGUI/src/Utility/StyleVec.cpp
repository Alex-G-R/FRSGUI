#include "StyleVec.h"

namespace fr
{
    StyleVec::StyleVec(std::string group_name, const Style &style,StyleType style_type, int style_priority) :
    group_name(std::move(group_name)), style(style), style_type(style_type), style_priority(style_priority)
    {

    }

}