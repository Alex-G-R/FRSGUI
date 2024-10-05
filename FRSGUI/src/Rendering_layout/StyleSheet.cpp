#include "StyleSheet.h"

namespace fr::Rendering
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

    void StyleSheet::updateStyleVec(const std::string &style_name, Style& style_update)
    {
        for(auto& s : style_vec)
        {
            if(style_name == s.group_name)
            {
                if(style_update.has_size)
                {
                    s.style.setSize(style_update.getSize());
                }
                if(style_update.has_position)
                {
                    s.style.setPosition(style_update.getPosition());
                }
                if(style_update.has_bg_color)
                {
                    s.style.setBgColor(style_update.getBgColor());
                }
                if(style_update.has_outline_color)
                {
                    s.style.setOutlineColor(style_update.getOutlineColor());
                }
                if(style_update.has_outline_thickness)
                {
                    s.style.setOutlineThickness(style_update.getOutlineThickness());
                }
            }
        }
    }


}