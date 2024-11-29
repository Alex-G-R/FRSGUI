#include "TextBlock.h"

namespace fr {
    TextBlock::TextBlock(const std::shared_ptr<Renderer> &renderer_ptr) : UIElement(renderer_ptr){}
    TextBlock::TextBlock(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups) : UIElement(renderer_ptr, std::move(ID), groups) {}
    TextBlock::TextBlock(const std::shared_ptr<Renderer>& renderer_ptr, std::initializer_list<std::string> groups) : UIElement(renderer_ptr, groups) {}
    TextBlock::TextBlock(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID) : UIElement(renderer_ptr, std::move(ID)) {}

} // fr