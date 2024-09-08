#include "FRSGUI/FRSGUI.hpp"

int main()
{
    const auto render_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);

    fr::FRSGUI frsgui(render_window_ptr);

    // Create GUI here
    auto square = std::make_shared<fr::UI_element>(frsgui.getRenderer());
    square->addGroup("squares");
    square->addGroup("squares_two");

    fr::Style squares_style;
    squares_style.setSize(100.f, 100.f);
    squares_style.setPosition(200.f, 200.f);
    squares_style.setBgColor(sf::Color::Green);
    squares_style.setOutlineThickness(2.f);
    squares_style.setOutlineColor(sf::Color::White);

    fr::Style squares_style_two;
    //squares_style_two.setSize(100.f, 100.f);
    //squares_style_two.setPosition(200.f, 200.f);
    squares_style_two.setBgColor(sf::Color::Red);
    //squares_style_two.setOutlineThickness(2.f);
    //squares_style_two.setOutlineColor(sf::Color::Blue);

    frsgui.style_sheet.addStyleVec(fr::StyleVec("squares", squares_style, StyleType::CLASS, 1));
    frsgui.style_sheet.addStyleVec(fr::StyleVec("squares_two", squares_style_two, StyleType::CLASS, 5));

    frsgui.addElement(square);

    frsgui.Run();
    return 0;
}
