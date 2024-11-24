#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <vector>
#include <string>

#include "../Utility/StyleVec.h"
#include "../Utility/Style.h"

namespace fr::Rendering {

    class StyleSheet {

    std::vector<StyleVec> style_vec;

    public:
        StyleSheet();
        void addStyleVec(const StyleVec& style_vec);
        std::vector<StyleVec>& getStyleVec();
    };

}


#endif //STYLESHEET_H
