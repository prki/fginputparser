#include <iostream>
#include <SFML/Graphics.hpp>
#include "view.hpp"
/*
MainView::MainView()
{
    //this->window = window(sf::VideoMode(800, 600), "FG Input parser");
    int ret = this->defaultFont.loadFromFile("./assets/Montserrat-Regular.ttf");
    if (!ret)
    {
        std::cout << "Error loading font: " << ret << std::endl;
    }
}
*/

void MainView::drawMainElements()
{
    this->window.draw(this->headerText);
}