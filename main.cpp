#include "FRSGUI/FRSGUI.hpp"

int main()
{
    const auto render_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);

    fr::FRSGUI frsgui(render_window_ptr);

    // Create GUI here
    const auto square = UI_element(frsgui.getRenderer());
    const auto squareTwo = UI_element(frsgui.getRenderer());

    square->addGroup("squares");
    square->addGroup("squares_two");

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


    frsgui.addStyle("squares", squares_style, StyleType::CLASS, 1);
    frsgui.addStyle("squares_two", squares_style_two, StyleType::CLASS, 5);
    frsgui.addStyle("squares_three", squares_style_three, StyleType::ID, 3);


    frsgui.addElement(square);
    frsgui.addElement(squareTwo);

    frsgui.Run();
    return 0;
}
