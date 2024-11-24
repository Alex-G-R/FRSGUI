#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <vector>
#include <string>

#include "StyleVec.h"
#include "Style.h"

namespace fr {

    class StyleSheet {

    std::vector<StyleVec> style_vec;

    public:
        StyleSheet();
        void addStyleVec(const StyleVec& style_vec);
        std::vector<StyleVec>& getStyleVec();
    };

}


#endif //STYLESHEET_H
