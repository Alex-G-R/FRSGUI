#include "FRSGUI/FRSGUI.hpp"

int main()
{
    const auto render_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);

    fr::FRSGUI frsgui(render_window_ptr);

    // Create GUI here
    auto square = std::make_shared<fr::UI_element>(frsgui.getRenderer());
    square->addGroup("squares");

    fr::Style squares_style;
    squares_style.size = sf::Vector2f(100.f, 100.f);
    squares_style.position = sf::Vector2f(200.f, 200.f);
    squares_style.background_color = sf::Color::Green;
    squares_style.outline_thickness = 2.f;
    squares_style.outline_color = sf::Color::White;

    frsgui.style_sheet["squares"] = squares_style;

    frsgui.addElement(square);

    frsgui.Run();
    return 0;
}
