#include "UI_element.h"

namespace fr {

    // constructor
    UI_element::UI_element(const std::shared_ptr<Rendering::Renderer> &renderer_ptr):
    renderer_ptr(renderer_ptr)
    {
        id = "";
        z_order = 0;
        dirty = false;
    }

    UI_element::~UI_element() = default;

    // methods
    void UI_element::Render()
    {
        renderer_ptr->draw(this);
    }

    void UI_element::Update()
    {

    }

    void UI_element::deleteGroup(const std::string &group_name)
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
    void UI_element::setID(const std::string& id)
    {
        this->id = id;
    }

    void UI_element::addGroup(const std::string& group)
    {
        groups.emplace_back(group);
    }

    void UI_element::addChild(const std::shared_ptr<UI_element>& child)
    {
        children.emplace_back(child);
    }

    void UI_element::setZOrder(int z_order)
    {
        this->z_order = z_order;
    }

    void UI_element::setDirty(bool is_dirty)
    {
        dirty = is_dirty;
    }

    // getters
    std::string UI_element::getID()
    {
        return id;
    }

    std::vector<std::string>& UI_element::getGroupsVector()
    {
        return groups;
    }

    std::vector<std::shared_ptr<UI_element>>& UI_element::getChildren()
    {
        return children;
    }

    int UI_element::getZOrder()
    {
        return z_order;
    }

    bool UI_element::isDirty()
    {
        return dirty;
    }

    sf::RectangleShape *UI_element::getShape()
    {
        return &shape;
    }


}