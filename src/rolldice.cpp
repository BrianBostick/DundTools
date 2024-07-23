#include "../include/rolldice.h"
#include <iostream>
#include <string>
#include <stdlib.h>

int main( int argc, char* argv[])
{
    if (argc < 2)
    {
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <number of dice> <number of sides of dice> <mod> (-mod if negative)" << '\n';
        else
            std::cout << "Usage: <program name> <number>" << '\n';

        return 1;
    }
    
    int num_mod;
    if (argv[3])
    {
        num_mod = atoi(argv[3]);
    } else {
        num_mod = 0;
    }
    int num_sides = atoi(argv[2]);
    int num_dice = atoi(argv[1]);

    int roll = diceRoll(num_dice, num_sides);
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
