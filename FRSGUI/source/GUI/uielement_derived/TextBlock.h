#ifndef TEXT_BLOCK_H
#define TEXT_BLOCK_H

#include "../../GUI/UIElement.h"

namespace fr {

class TextBlock : public UIElement {
public:
    explicit TextBlock(const std::shared_ptr<Renderer>& renderer_ptr);
    TextBlock(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups);
    TextBlock(const std::shared_ptr<Renderer>& renderer_ptr, std::initializer_list<std::string> groups);
    TextBlock(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID);
};

} // fr

#endif //TEXT_BLOCK_H
