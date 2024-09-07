#include "src/Core/FRSGUI.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);
    sf::RenderWindow* render_window_ptr = &window;

    fr::FRSGUI frsgui(render_window_ptr);

    frsgui.Run();

    // Create GUI here

    return 0;
}
