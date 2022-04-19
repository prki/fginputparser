#include <SFML/Graphics.hpp>
#include "view.hpp"

int main()
{
    MainView mainview;
    //sf::RenderWindow window(sf::VideoMode(800, 600), "FG Input parser");

    while (mainview.getWindow().isOpen())
    {
        sf::Event event;
        while (mainview.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainview.getWindow().close();
        }

        mainview.getWindow().clear();
        mainview.drawMainElements();
        mainview.getWindow().display();
    }

    /*
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
    */

    return 0;
}