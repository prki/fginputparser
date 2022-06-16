#include <iostream> // [DBG]
#include <SFML/Graphics.hpp>
#include "view.hpp"
#include "inputhandler.hpp"
#include "inputhistory.hpp"

int main()
{
    MainView mainview;
    InputHandler inputHandler;
    InputHistory inputHistory;
    // sf::RenderWindow window(sf::VideoMode(800, 600), "FG Input parser");

    mainview.getWindow().setFramerateLimit(60);
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
        // mainview.getWindow().display();
        inputHandler.readCurrentInput();
        inputHistory.updateNewInput(inputHandler.getCurrentInput());
        mainview.drawInputHistory(inputHistory.getDrawableHistory());
        mainview.getWindow().display();
    }

    return 0;
}