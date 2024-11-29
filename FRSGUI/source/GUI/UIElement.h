#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <Graphics.hpp>
#include "../core/rendering/Renderer.h"
#include <memory>
#include <string>
#include <variant>

class GUI;

namespace fr {

class UIElement {
private:
    sf::RectangleShape shape;

    std::string id;
    std::vector<std::string> groups;

    // Not used for now
    std::vector<std::shared_ptr<UIElement>> children;
    int z_order;
    bool dirty;
    // -----

    using TextType = std::variant<std::string,const char*, int, double, float>;
    sf::Font font;
    sf::Text text;

protected:
    std::shared_ptr<Renderer> renderer_ptr{};

public:
    // Constructor
    explicit UIElement(const std::shared_ptr<Renderer>& renderer_ptr);
    UIElement(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID, std::initializer_list<std::string> groups);
    UIElement(const std::shared_ptr<Renderer>& renderer_ptr, std::initializer_list<std::string> groups);
    UIElement(const std::shared_ptr<Renderer>& renderer_ptr, std::string ID);
    virtual ~UIElement();

    // Methods
    virtual void Render();
    virtual void Update();

    void deleteGroup(const std::string& group);

    // Setters
    void setID(const std::string& id);
    void addGroup(const std::string& group);
    void addChild(const std::shared_ptr<UIElement>& child);
    void setZOrder(int z_order);
    void setDirty(bool is_dirty);
    void setTextString(TextType text);


    // Getters
    std::string getID();
    std::vector<std::string>& getGroupsVector();
    std::vector<std::shared_ptr<UIElement>>& getChildren();
    int getZOrder();
    bool isDirty();
    sf::RectangleShape* getShape();
    std::string getTextString();
    sf::Text& getText();

    // Flags
    bool has_cursor;
    bool selected;
};

}

#endif //UI_ELEMENT_H
