#ifndef _INPUTS_HPP_
#define _INPUTS_HPP_

enum Inputs
{
    Neutral = 0b00000000,
    Down = 0b00000001,
    Right = 0b00000010,
    Left = 0b00000100,
    Up = 0b00001000,
    A = 0b00010000,
    B = 0b00100000,
    C = 0b01000000,

    Downright = Down | Right,
    Downleft = Down | Left,
    Upright = Up | Right,
    Upleft = Up | Left,

    AB = A | B,
    AC = A | C,
    BC = B | C,
    ABC = A | B | C
};

#endif // _INPUTS_HPP_