#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <Graphics.hpp>
#include "../Rendering_layout/Renderer.h"
#include <memory>
#include <string>

class GUI;

namespace fr {

class UI_element {
private:
    sf::RectangleShape shape;

    std::string id;
    std::vector<std::string> groups;

    bool visible;

    // Not use for now
    std::vector<std::shared_ptr<UI_element>> children;
    int z_order;
    bool dirty;
    // -----

    std::shared_ptr<Rendering::Renderer> renderer_ptr{};

public:
    // Constructor
    explicit UI_element(const std::shared_ptr<Rendering::Renderer>& renderer_ptr);
    virtual ~UI_element();

    // Methods
    virtual void Render();
    virtual void Update();

    void deleteGroup(const std::string& group);

    // Setters
    void setID(const std::string& id);
    void addGroup(const std::string& group);
    void addChild(const std::shared_ptr<UI_element>& child);
    void setZOrder(const int& z_order);
    void setVisibility(const bool& is_visible);
    void setDirty(const bool& is_dirty);


    // Getters
    std::string getID();
    std::vector<std::string>& getGroupsVector();
    std::vector<std::shared_ptr<UI_element>>& getChildren();
    int getZOrder();
    bool isVisible();
    bool isDirty();
    sf::RectangleShape* getShape();
};

}

#endif //UI_ELEMENT_H
