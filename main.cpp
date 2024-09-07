#include "src/Core/FRSGUI.h"

int main()
{
    auto render_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);

    fr::FRSGUI frsgui(render_window_ptr);

    frsgui.Run();

    // Create GUI here

    return 0;
}
