#ifndef _INPUTHANDLER_HPP_
#define _INPUTHANDLER_HPP_
#include "inputs.hpp"

class InputHandler
{
public:
    Inputs getCurrentInput() { return currentInput; }
    void readCurrentInput();

private:
    void cleanUpInput();
    Inputs currentInput;
};

#endif // _INPUTHANDLER_HPP_