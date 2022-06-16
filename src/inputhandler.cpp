#include <iostream> // # [DBG]
#include <SFML/Window.hpp>
#include "inputhandler.hpp"

void InputHandler::readCurrentInput()
{
    this->currentInput = Inputs::Neutral;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        currentInput = static_cast<Inputs>(currentInput | Inputs::Down);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        currentInput = static_cast<Inputs>(currentInput | Inputs::Up);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        currentInput = static_cast<Inputs>(currentInput | Inputs::Left);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        currentInput = static_cast<Inputs>(currentInput | Inputs::Right);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        currentInput = static_cast<Inputs>(currentInput | Inputs::A);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        currentInput = static_cast<Inputs>(currentInput | Inputs::B);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        currentInput = static_cast<Inputs>(currentInput | Inputs::C);

    cleanUpInput();
}

void InputHandler::cleanUpInput()
{
    if ((currentInput & Inputs::Left) && (currentInput & Inputs::Right))
        currentInput = static_cast<Inputs>(currentInput & ~(Inputs::Left | Inputs::Right));
    if ((currentInput & Inputs::Down) && (currentInput & Inputs::Up))
        currentInput = static_cast<Inputs>(currentInput & ~Inputs::Down);
}