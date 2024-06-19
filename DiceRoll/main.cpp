#include "../include/diceroll.h"
#include <iostream>
#include <sstream>

int main( int argc, char* argv[])
{
    if (argc <= 2)
    {
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <number>" << " <mod> (-mod if negative)" << '\n';
        else
            std::cout << "Usage: <program name> <number>" << '\n';

        return 1;
    }

    std::stringstream convert1{ argv[1] };
    std::stringstream convert2{ argv[2] };
    int num_mod{};
    if (!argv[3])
       num_mod = 0;
    std::stringstream convert3{ argv[3] };
    int num_dice{};
    int num_sides{};

    if (!(convert1 >> num_dice))
        num_dice = 0;
    if (!(convert2 >> num_sides))
        num_sides = 0;
    if (!(convert3 >> num_mod))
        num_mod = 0;

    int roll{ diceRoll(num_dice, num_sides) };
    int total{ roll + num_mod };

    if (num_sides == 20 && roll == 20)
        std::cout << "Nat 20!" << '\n';
    else if (num_sides == 20 && roll == 1)
        std::cout << "Nat 1 :(" << '\n';

    std::cout << num_dice << "d" << num_sides << '\n';
    std::cout << "Roll: " << roll << "\nMod: " << num_mod << '\n';
    std::cout << "\nTotal: " << total << '\n';

    return 0;
}