#ifndef _INPUTHISTORY_HPP_
#define _INPUTHISTORY_HPP_
#include <list>
#include <string>
#include <SFML/Graphics.hpp>
#include "inputs.hpp"

class InputHistory
{
public:
    InputHistory();
    void updateNewInput(Inputs input);

    const std::list<sf::Text> &getDrawableHistory() { return drawableHistory; }

private:
    void increaseLastInput();
    void updateDrawableHistory();
    sf::Text createDrawableText(Inputs input, unsigned int duration);
    std::string prettifyInput(Inputs input, unsigned int duration);
    void updateDrawableHistoryPositions();

    // std::list<std::pair<Inputs, unsigned int>> history;
    std::list<Inputs> history;
    // std::list<std::pair<Inputs, unsigned int>>::size_type maxLength;
    std::list<Inputs>::size_type maxLength;
    std::list<sf::Text> drawableHistory;
    unsigned int lastInputDuration; // Convenience for drawable history.
    sf::Font defaultFont;
};

#endif // _INPUTHISTORY_HPP_