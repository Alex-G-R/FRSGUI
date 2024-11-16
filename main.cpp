#include "FRSGUI/FRSGUI.hpp"

#include <iostream>

int main()
{
    const auto render_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "FRSGUI test", sf::Style::Default);

    fr::FRSGUI frsgui(render_window_ptr);

    // Create GUI here
    const auto square = UI_element(frsgui.getRenderer(), "Foo", {
        "squares",
        "squares_two",
        "squares_three",
        "squares_four"
    }, frsgui);


    auto squares_style = Style("squares", fr::ApplyBy::GROUP, 1,{
        {fr::KEY::POSITION, sf::Vector2f(50.f, 50.f)},
        {fr::KEY::SIZE, sf::Vector2f(500.f, 30.f)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color{255, 0, 0, 255}},
        {fr::KEY::OUTLINE_THICKNESS, 10.f},
        {fr::KEY::OUTLINE_COLOR, sf::Color{0, 255, 0, 255}},
        {fr::KEY::VISIBLE, true}
    }, frsgui);

    auto squares_two = Style("squares_two", fr::ApplyBy::GROUP, 10, {
        {fr::KEY::BACKGROUND_COLOR, sf::Color::Black}
    }, frsgui);

    auto squares_three = Style("squares_three", fr::ApplyBy::GROUP, 15, {
        {fr::KEY::OUTLINE_COLOR, sf::Color::Blue}
    }, frsgui);

    auto squares_four = Style("squares_four", fr::ApplyBy::GROUP, 7, {
        {fr::KEY::BACKGROUND_COLOR, sf::Color::Cyan}
    }, frsgui);

    //button test
    const auto btn = Button(frsgui.getRenderer(), frsgui);
    btn->addGroup("btn");
    // frsgui.addElement(btn);

    auto btn_style = Style("btn", fr::ApplyBy::GROUP, 1,{
        {fr::KEY::SIZE, sf::Vector2f(100.f, 100.f)},
        {fr::KEY::POSITION, sf::Vector2f(800.f, 300.f)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color::Cyan}
    }, frsgui);

    // testing custom event handlers
    sf::RectangleShape player;
    player.setFillColor(sf::Color::White);
    player.setPosition(800.f, 800.f);
    player.setSize(sf::Vector2f(50.f, 50.f));

    btn->setOnClick([&player, &square, &frsgui, &squares_style]()
    {
        // Object manipulation by capture
        //square->deleteGroup("squares");

        /* Object manipulation by FRSGUI capture */
        frsgui.getElementByID("Foo")->deleteGroup("squares_two");

        /* Custom functionality by capture */
        std::cout << "Button clicked. \n";
        player.move(10.f, 0.f);

        /* Styles manipulation by style capture */
        squares_style->update_style({
            {fr::KEY::BACKGROUND_COLOR, sf::Color::Yellow},
            {fr::KEY::OUTLINE_THICKNESS, 2}
        });

        // Size debug |
        // std::cout << "Size of element: " << sizeof(square) << "\n";
        // std::cout << "Size of frsgui: " << sizeof(frsgui) << "\n";
    });

    //Bool is_numerical_only is an overload, defaults to false
    const auto input = Input(frsgui.getRenderer(), false, frsgui);
    input->addGroup("input");
    auto input_style = Style("input", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::SIZE, sf::Vector2f(300.f, 60.f)},
        {fr::KEY::POSITION, sf::Vector2f(500.f, 500.f)},
        {fr::KEY::OUTLINE_THICKNESS, 1},
        {fr::KEY::OUTLINE_COLOR, sf::Color(160, 160, 160)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color(35, 34, 33)},
        // ended here
        {fr::KEY::CURSOR_COLOR, sf::Color(133, 134, 135, 255)},
        {fr::KEY::CHARACTER_SIZE, 48}
    }, frsgui);


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

        // Your rendering
        render_window_ptr->draw(player);

        // Render GUI at the end
        frsgui.Render();
        render_window_ptr->display();
    }

    return 0;
}
