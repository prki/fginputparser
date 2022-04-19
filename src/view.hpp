#include <iostream>
#include <stdexcept>
#include <SFML/Graphics.hpp>

class MainView
{
public:
    MainView() : window(sf::VideoMode(800, 600), "FG Input parser")
    {
        int ret = this->defaultFont.loadFromFile("./assets/Montserrat-Regular.ttf");
        if (!ret)
        {
            std::cout << "Error loading font: " << ret << std::endl;
            throw std::invalid_argument("Default font for main view not found.");
        }

        this->headerText.setFont(this->defaultFont);
        this->headerText.setString("FG Input parser");
        this->headerText.setCharacterSize(24);
    }
    sf::RenderWindow &getWindow() { return this->window; }
    void drawMainElements();

private:
    sf::Font defaultFont;
    sf::Text headerText;
    sf::RenderWindow window;
};
