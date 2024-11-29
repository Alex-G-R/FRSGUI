#include "UIElement.h"
#include <iostream>

namespace fr {

    // constructor and overloads
    UIElement::UIElement(const std::shared_ptr<Renderer> &renderer_ptr):
    renderer_ptr(renderer_ptr)
    {
        id = "";
        z_order = 0;
        dirty = false;
        if(!font.loadFromFile("./FRSGUI/resources/default_font/default.ttf"))
        {
            std::cout << "Font loading error \n";
        }
        text.setFont(font);

        has_cursor = false;
        selected = false;
    }

    UIElement::UIElement(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups):
    renderer_ptr(renderer_ptr)
    {
        id = std::move(ID);
        z_order = 0;
        dirty = false;

        for(const auto& group : groups)
        {
            this->groups.push_back(group);
        }

        if(!font.loadFromFile("./FRSGUI/resources/default_font/default.ttf"))
        {
            std::cout << "Font loading error \n";
        }
        text.setFont(font);

        has_cursor = false;
        selected = false;
    }

    UIElement::UIElement(const std::shared_ptr<Renderer>& renderer_ptr, std::initializer_list<std::string> groups):
    renderer_ptr(renderer_ptr)
    {
        id = "";
        z_order = 0;
        dirty = false;

        for(const auto& group : groups)
        {
            this->groups.push_back(group);
        }

        if(!font.loadFromFile("./FRSGUI/resources/default_font/default.ttf"))
        {
            std::cout << "Font loading error \n";
        }
        text.setFont(font);

        has_cursor = false;
        selected = false;
    }

    UIElement::UIElement(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID):
    renderer_ptr(renderer_ptr)
    {
        id = std::move(ID);
        z_order = 0;
        dirty = false;

        if(!font.loadFromFile("./FRSGUI/resources/default_font/default.ttf"))
        {
            std::cout << "Font loading error \n";
        }
        text.setFont(font);

        has_cursor = false;
        selected = false;
    }

    UIElement::~UIElement() = default;

    // methods
    void UIElement::Render()
    {
        renderer_ptr->draw(this);
    }

    void UIElement::Update()
    {

    }

    void UIElement::deleteGroup(const std::string &group_name)
    {
        for (auto it = groups.begin(); it != groups.end(); ) {
            if (*it == group_name) {
                it = groups.erase(it); // Erase returns the next iterator
            } else {
                ++it; // Only increment if not erasing
            }
        }
    }


    // setters
    void UIElement::setID(const std::string& id)
    {
        this->id = id;
    }

    void UIElement::addGroup(const std::string& group)
    {
        groups.emplace_back(group);
    }

    void UIElement::addChild(const std::shared_ptr<UIElement>& child)
    {
        children.emplace_back(child);
    }

    void UIElement::setZOrder(int z_order)
    {
        this->z_order = z_order;
    }

    void UIElement::setDirty(bool is_dirty)
    {
        dirty = is_dirty;
    }

    void UIElement::setTextString(TextVariant text)
    {
        std::visit([this](auto&& value)
        {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_arithmetic_v<T>)
            {
                // Convert numbers to string
                std::string str = std::to_string(value);

                // Remove zeros
                str.erase(str.find_last_not_of('0') + 1);

                // Remove trailing dot if exists
                if(str.back() == '.')
                {
                    str.pop_back();
                }

                this->text.setString(str);
            }
            else if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, const char*>)
            {
                this->text.setString(value); // Use strings directly
            }
        }, text);
    }


    // getters
    std::string UIElement::getID()
    {
        return id;
    }

    std::vector<std::string>& UIElement::getGroupsVector()
    {
        return groups;
    }

    std::vector<std::shared_ptr<UIElement>>& UIElement::getChildren()
    {
        return children;
    }

    int UIElement::getZOrder()
    {
        return z_order;
    }

    bool UIElement::isDirty()
    {
        return dirty;
    }

    sf::RectangleShape *UIElement::getShape()
    {
        return &shape;
    }

    std::string UIElement::getTextString()
    {
        return text.getString();
    }

    sf::Text& UIElement::getText()
    {
        return text;
    }



}