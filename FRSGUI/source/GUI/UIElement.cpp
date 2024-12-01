#include "UIElement.h"
#include "../core/FRSGUI.h"
#include "uielement_derived/Button.h"
#include "uielement_derived/Input.h"
#include "uielement_derived/Checkbox.h"
#include <iostream>

namespace fr {

    // constructor and overloads
    UIElement::UIElement(const std::shared_ptr<Renderer> &renderer_ptr):
    renderer_ptr(renderer_ptr)
    {
        id = "";

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
/*
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
*/
    void UIElement::setText(TextType text)
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
/*
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
*/
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


    // Constructor for Builder
    UIElement::Builder::Builder(FRSGUI* frsgui) : frsgui(frsgui) {}

    // Setters
    UIElement::Builder& UIElement::Builder::setID(const std::string& id) {
        this->id = id;
        return *this;
    }

    UIElement::Builder& UIElement::Builder::addGroup(const std::string& group) {
        groups.push_back(group);
        return *this;
    }

    UIElement::Builder &UIElement::Builder::addGroups(const std::initializer_list<std::string> &groups)
    {
        for(auto& group : groups)
        {
            this->groups.push_back(group);
        }
        return *this;
    }


    UIElement::Builder& UIElement::Builder::setText(TextType text) {
        this->text = text;
        return *this;
    }

    UIElement::Builder &UIElement::Builder::isNumericalOnly(bool isNumericalOnly)
    {
        this->numerical_only = isNumericalOnly;
        return *this;
    }


    // Build method
    std::shared_ptr<UIElement> UIElement::Builder::buildUIElement() {

        auto instance = std::make_shared<UIElement>(frsgui->getRenderer());

        instance->setID(id);
        for (const auto& group : groups) {
            instance->addGroup(group);
        }
        instance->setText(text);

        frsgui->addElement(instance);

        return instance;
    }

    std::shared_ptr<UIElement> UIElement::Builder::buildTextBlock() {
        return buildUIElement();
    }

    std::shared_ptr<fr::Button> UIElement::Builder::buildButton()
    {
        auto instance = std::make_shared<Button>(frsgui->getRenderer());

        instance->setID(id);
        for (const auto& group : groups) {
            instance->addGroup(group);
        }
        instance->setText(text);

        frsgui->addElement(instance);

        return instance;
    }

    std::shared_ptr<fr::Input> UIElement::Builder::buildInput()
    {
        auto instance = std::make_shared<Input>(frsgui->getRenderer(), numerical_only);

        instance->setID(id);
        for (const auto& group : groups) {
            instance->addGroup(group);
        }
        instance->setText(text);

        frsgui->addElement(instance);

        return instance;
    }

    std::shared_ptr<fr::Checkbox> UIElement::Builder::buildCheckbox()
    {
        auto instance = std::make_shared<Checkbox>(frsgui->getRenderer());

        instance->setID(id);
        for (const auto& group : groups) {
            instance->addGroup(group);
        }
        instance->setText(text);

        frsgui->addElement(instance);

        return instance;
    }


}