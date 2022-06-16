#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "inputhistory.hpp"
#include "inputs.hpp"

const float drawHistoryPosY = 30;
const float drawHistoryPosX = 10;

InputHistory::InputHistory()
{
    int ret = this->defaultFont.loadFromFile("./assets/Montserrat-Regular.ttf");
    if (!ret)
    {
        std::cout << "Error loading font: " << ret << std::endl;
        throw std::invalid_argument("Default font for input history not found.");
    }
    // auto initialInput = std::make_pair(Inputs::Neutral, 0);
    auto initialInput = Inputs::Neutral;
    history.push_front(initialInput);
    auto initialInputDrawable = createDrawableText(initialInput, 0);
    drawableHistory.push_back(initialInputDrawable);
    maxLength = 60;
    lastInputDuration = 0;
}

sf::Text InputHistory::createDrawableText(Inputs input, unsigned int duration)
{
    std::string prettifiedInput = prettifyInput(input, duration);

    sf::Text ret;
    ret.setFont(this->defaultFont);
    ret.setString(prettifiedInput);
    ret.setCharacterSize(20);
    ret.setPosition(drawHistoryPosX, drawHistoryPosY);

    return ret;
}

void InputHistory::updateDrawableHistoryPositions()
{
    float posY = drawHistoryPosY;
    for (auto it = drawableHistory.rbegin(); it != drawableHistory.rend(); it++)
    {
        it->setPosition(drawHistoryPosX, posY);
        posY += drawHistoryPosY;
    }
}

void InputHistory::updateDrawableHistory()
{
    Inputs lastInput;
    Inputs secondLastInput;
    bool pushNewInput = false;

    if (drawableHistory.empty())
    {
        lastInput = history.back();
        lastInputDuration = 1;
    }
    else
    {
        lastInput = history.back();
        auto it = history.end();
        --it;
        --it;
        secondLastInput = *it;
        if (lastInput == secondLastInput)
            lastInputDuration += 1;
        else
        {
            lastInputDuration = 1;
            pushNewInput = true;
        }
    }

    sf::Text drawable = createDrawableText(lastInput, lastInputDuration);

    if (pushNewInput)
    {
        drawableHistory.push_back(drawable);
        if (drawableHistory.size() == maxLength)
            drawableHistory.erase(drawableHistory.begin());
        updateDrawableHistoryPositions();
    }
    else
    {
        auto itEnd = drawableHistory.end();
        --itEnd;
        drawableHistory.erase(itEnd);
        drawableHistory.push_back(drawable);
    }
}

std::string InputHistory::prettifyInput(Inputs input, unsigned int duration)
{
    auto currInput = input;
    std::string inputString = "";
    std::string inputFrameCounter = "";
    std::string retString;

    if ((currInput & Inputs::Downright) == Inputs::Downright)
        inputString += "3";
    else if ((currInput & Inputs::Downleft) == Inputs::Downleft)
        inputString += "1";
    else if ((currInput & Inputs::Upright) == Inputs::Upright)
        inputString += "9";
    else if ((currInput & Inputs::Upleft) == Inputs::Upleft)
        inputString += "7";
    else if ((currInput & Inputs::Down) == Inputs::Down)
        inputString += "2";
    else if ((currInput & Inputs::Up) == Inputs::Up)
        inputString += "8";
    else if ((currInput & Inputs::Left) == Inputs::Left)
        inputString += "4";
    else if ((currInput & Inputs::Right) == Inputs::Right)
        inputString += "6";
    else
        inputString += "5";

    if ((currInput & Inputs::ABC) == Inputs::ABC)
        inputString += "ABC";
    else if ((currInput & Inputs::AB) == Inputs::AB)
        inputString += "AB";
    else if ((currInput & Inputs::AC) == Inputs::AC)
        inputString += "AC";
    else if ((currInput & Inputs::BC) == Inputs::BC)
        inputString += "BC";
    else if ((currInput & Inputs::A) == Inputs::A)
        inputString += "A";
    else if ((currInput & Inputs::B) == Inputs::B)
        inputString += "B";
    else if ((currInput & Inputs::C) == Inputs::C)
        inputString += "C";

    inputFrameCounter = std::to_string(duration);

    retString = inputFrameCounter + "  |  " + inputString;
    std::cout << retString << std::endl;

    return retString;
}

void InputHistory::updateNewInput(Inputs input)
{
    auto currentinput = input;
    history.push_back(currentinput);
    if (history.size() == maxLength)
        history.erase(history.begin());

    // prettifyInput(history.back());
    updateDrawableHistory();
}