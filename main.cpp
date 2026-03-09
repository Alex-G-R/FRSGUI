#include "FRSGUI/FRSGUI.hpp"

int main()
{
    /* initialize SFML render window, create a pointer to that render window */
    constexpr int W_WIDTH = 1920;
    constexpr int W_HEIGHT = 1080;
    const auto WINDOW = std::make_shared<sf::RenderWindow>(sf::VideoMode({W_WIDTH, W_HEIGHT}), "FRSGUI - Window");

    /* initialize FRSGUI by passing the render window pointer */
    fr::FRSGUI FRSGUI(WINDOW);

    /* Create SFML elements here, custom non FRSGUI visuals */

    /* Create GUI here */
    // Create a banner element as a default UIElement
    const auto banner = fr::UIElement::Builder(&FRSGUI)
    .setID("Banner")
    .addGroup("Banner_main")
    .setText("Hey, Welcome to FRSGUI :)")
    .buildUIElement();
    // Create a style for Banner_main
    auto banner_main_style = Style("Banner_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::POSITION, sf::Vector2f(W_WIDTH/2 - 500.f/2 , 50.f)},
        {fr::KEY::SIZE, sf::Vector2f(500.f, 60.f)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color{0, 255, 0, 255}},
        {fr::KEY::CHARACTER_SIZE, 36},
        {fr::KEY::TEXT_COLOR, sf::Color::White}
    }, FRSGUI);

    // Create a button element as a fr::Button
    const auto button = fr::Button::Builder(&FRSGUI)
    .setID("button")
    .addGroup("Button_main")
    .setText("Click me!")
    .buildButton();
    // Create a style for button_main
    const auto button_main_style = Style("Button_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::SIZE, sf::Vector2f(140.f, 100.f)},
        {fr::KEY::POSITION, sf::Vector2f(W_WIDTH/6 - 140.f/2, 150.f)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color::Blue},
        {fr::KEY::CHARACTER_SIZE, 30},
        {fr::KEY::TEXT_COLOR, sf::Color::White},
        {fr::KEY::OUTLINE_THICKNESS, 4.f},
        {fr::KEY::OUTLINE_COLOR, sf::Color{160, 160, 255, 255}},
    }, FRSGUI);
    // Create functionality for the button
    int banner_status = 0;
    // Create custom background color style with higher priority
    auto red_bg_style = Style("red_bg_style", fr::ApplyBy::GROUP, 5, {
            {fr::KEY::BACKGROUND_COLOR, sf::Color{255, 0, 0, 255}},
    }, FRSGUI);
    button->setOnClick([&FRSGUI, &banner_status]()
    {
        /* Change the banner color */
        if (banner_status % 2 == 0)
        {
            FRSGUI.getUIElementByID("Banner")->addGroup("red_bg_style");
        }
        else
        {
            FRSGUI.getUIElementByID("Banner")->deleteGroup("red_bg_style");
        }
        banner_status++;

        /* Handle operation on inputs if checkbox is selected */
        if (FRSGUI.getCheckboxByID("checkbox_A")->getSelect() == true)
        {
            const auto num1 = FRSGUI.getInputByID("input_A");
            const auto num2 = FRSGUI.getInputByID("input_B");
            const auto result = num1->getDataAs<double>() + num2->getDataAs<double>();
            // Display the result
            FRSGUI.getUIElementByID("result")->setText(result);
        }
    });

    /* Create two numer inputs */
    const auto input_A = fr::Input::Builder(&FRSGUI)
    .addGroup("input_main")
    .isNumericalOnly(true)
    .setID("input_A")
    .buildInput();
    const auto input_B = fr::Input::Builder(&FRSGUI)
    .addGroup("input_main")
    .isNumericalOnly(true)
    .setID("input_B")
    .buildInput();

    /* Add styling */
    auto input_main_style = Style("input_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::SIZE, sf::Vector2f(300.f, 60.f)},
        {fr::KEY::OUTLINE_THICKNESS, 2},
        {fr::KEY::OUTLINE_COLOR, sf::Color{160, 160, 160, 255}},
        {fr::KEY::BACKGROUND_COLOR, sf::Color::White},
        {fr::KEY::CURSOR_COLOR, sf::Color(133, 134, 135, 255)},
        {fr::KEY::CHARACTER_SIZE, 50},
        {fr::KEY::TEXT_COLOR, sf::Color::Black}
    }, FRSGUI);
    auto input_A_style = Style("input_A", fr::ApplyBy::ID, 1, {
        {fr::KEY::POSITION, sf::Vector2f(500.f, 500.f)}
    }, FRSGUI);
    auto input_B_style = Style("input_B", fr::ApplyBy::ID, 1, {
        {fr::KEY::POSITION, sf::Vector2f(900.f, 500.f)}
    }, FRSGUI);

    /* Create a result block for addition */
    const auto result = fr::TextBlock::Builder(&FRSGUI)
    .addGroup("result_main")
    .setID("result")
    .buildTextBlock();

    auto textblock_style = Style("result_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::CHARACTER_SIZE, 50},
        {fr::KEY::TEXT_COLOR, sf::Color::White},
        {fr::KEY::POSITION, sf::Vector2f(1300.f, 490.f)},
        {fr::KEY::SIZE, sf::Vector2f(300.f, 80.f)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color::Black}
    }, FRSGUI);

    /* Create a checkbox */
    const auto checkbox = fr::Checkbox::Builder(&FRSGUI)
    .addGroup("checkbox_main")
    .setID("checkbox_A")
    .buildCheckbox();
    auto checkbox_style = Style("checkbox_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::POSITION, sf::Vector2f(1700.f, 200.f)},
        {fr::KEY::SIZE, sf::Vector2f(100.f, 100.f)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color::White},
        {fr::KEY::OUTLINE_COLOR, sf::Color(134, 135, 136)},
        {fr::KEY::OUTLINE_THICKNESS, 2.f},
        {fr::KEY::SELECT_MARK_COLOR, sf::Color(0, 0, 0)}
    }, FRSGUI);

    /* SFML render loop */
    while(WINDOW->isOpen())
    {
        /* Pool events, if event = close, break the loop if any other pass it to the FRSGUI to handle*/
        while(const std::optional<sf::Event> event = WINDOW->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                WINDOW->close();
                break;
            }
            FRSGUI.dispatchEvent(event);
        }

        WINDOW->clear();

        /* Custom rendering, custom non FRSGUI elements */


        /* Render GUI by FRSGUI */
        FRSGUI.Render();

        /* SFML display function */
        WINDOW->display();
    }
    return 0;
}