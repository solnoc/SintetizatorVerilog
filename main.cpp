#include "gate_level.h"

core_abstruction_level coreLevel;

void window_managemant(sf::RenderWindow* window, sf::View* view);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000.0f, 1000.0f), "Sintetizator Verilog");
    sf::View view(sf::Vector2f(500.0f, 500.f), sf::Vector2f(1000.0f, 1000.0f));
    window.setView(view);
   
    coreLevel.ChangeWindow(&window);

    coreLevel.ChangeAbstructionLevel(new gate_level);

    int i = 0;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window_managemant(&window, &view);

        if (i == 100)
        {
            coreLevel.ChangeAbstructionLevel(new gate_level);
            i = 0;
        }

        window.clear();

        coreLevel.Update();
        coreLevel.Draw();

        window.display();
        i++;
    }
    return 0;
}

void window_managemant(sf::RenderWindow* window, sf::View* view)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        view->move(0.0f, -5.0f);
        window->setView(*view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        view->move(0.0f, 5.0f);
        window->setView(*view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        view->move(-5.0f, 0.0f);
        window->setView(*view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        view->move(5.0f, 0.0f);
        window->setView(*view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Hyphen))
    {
        view->zoom(1.01f);
        window->setView(*view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal))
    {
        view->zoom(0.99f);
        window->setView(*view);
    }
}