#include "StyleSheet.h"

namespace fr
{
    StyleSheet::StyleSheet()
    {

    }

    std::vector<StyleVec> &StyleSheet::getStyleVec()
    {
        return style_vec;
    }

    void StyleSheet::addStyleVec(const StyleVec& style_vec)
    {
        this->style_vec.emplace_back(style_vec);
    }

}