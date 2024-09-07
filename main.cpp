#include "FRSGUI/FRSGUI.hpp"

int main()
{
    const auto render_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);

    fr::FRSGUI frsgui(render_window_ptr);

    // Create GUI here
    auto square = std::make_shared<fr::UI_element>(frsgui.getRenderer());
    square->addGroup("squares");


    frsgui.addElement(square);

    frsgui.Run();
    return 0;
}
