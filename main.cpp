#include "src/Core/FRSGUI.h"

int main()
{
    auto render_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);

    fr::FRSGUI frsgui(render_window_ptr);

    // Create GUI here
    auto square = std::make_shared<fr::UI_element>(frsgui.getRenderer());
    sf::RectangleShape* square_shape = square->getShape();
    square_shape->setSize(sf::Vector2f(100.f, 100.f));
    square_shape->setPosition(sf::Vector2f(100.f, 100.f));
    square_shape->setFillColor(sf::Color::Red);

    frsgui.addElement(square);

    frsgui.Run();
    return 0;
}
