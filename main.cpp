#include "FRSGUI/FRSGUI.hpp"

#include <iostream>

void click_fun(fr::FRSGUI& frsgui)
{
    frsgui.getElementByID("squares_three")->addGroup("yellow_color");
    frsgui.getElementByID("SQUA1f")->deleteGroup("squares_two");
}

int main()
{
    const auto render_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);

    fr::FRSGUI frsgui(render_window_ptr);

    // Create GUI here
    const auto square = UI_element(frsgui.getRenderer());
    const auto squareTwo = UI_element(frsgui.getRenderer());

    square->addGroup("squares");
    square->addGroup("squares_two");
    square->setID("SQUA1");

    squareTwo->addGroup("squares");
    squareTwo->setID("squares_three");

    fr::Style squares_style;
    squares_style.setSize(100.f, 100.f);
    squares_style.setPosition(200.f, 200.f);
    squares_style.setBgColor(sf::Color::Green);
    squares_style.setOutlineThickness(2.f);
    squares_style.setOutlineColor(sf::Color::White);

    fr::Style squares_style_two;
    squares_style_two.setBgColor(sf::Color::Red);

    fr::Style squares_style_three;
    squares_style_three.setBgColor(sf::Color::Blue);
    squares_style_three.setPosition(400.f, 300.f);

    fr::Style yellow_color;
    yellow_color.setBgColor(sf::Color::Yellow);


    frsgui.addStyle("squares", squares_style, StyleType::CLASS, 1);
    frsgui.addStyle("squares_two", squares_style_two, StyleType::CLASS, 5);
    frsgui.addStyle("squares_three", squares_style_three, StyleType::ID, 3);
    frsgui.addStyle("yellow_color", yellow_color, StyleType::CLASS, 10);


    // button test
    const auto btn = Button(frsgui.getRenderer());

    btn->addGroup("btn");

    btn->setOnClick(click_fun);

    fr::Style btn_style;
    btn_style.setSize(100.f, 100.f);
    btn_style.setPosition(800.f, 200.f);
    btn_style.setBgColor(sf::Color::Cyan);
    btn_style.setOutlineThickness(2.f);
    btn_style.setOutlineColor(sf::Color::Magenta);

    frsgui.addStyle("btn", btn_style, StyleType::CLASS, 1);
    frsgui.addElement(btn);


    frsgui.addElement(square);
    frsgui.addElement(squareTwo);


    while(render_window_ptr->isOpen())
    {
        sf::Event event{};
        while(render_window_ptr->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                render_window_ptr->close();
                break;
            }
            frsgui.dispatchEvent(event);
        }

        render_window_ptr->clear();

        frsgui.Render();

        render_window_ptr->display();
    }

    return 0;
}
