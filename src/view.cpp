#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "view.hpp"

void MainView::drawMainElements()
{
    this->window.draw(this->headerText);
}

void MainView::drawInputHistory(const std::list<sf::Text> &drawableHistory)
{
    float positionMover = 20;
    for (auto it = drawableHistory.rbegin(); it != drawableHistory.rend(); it++)
    {
        this->window.draw(*it);
    }
}