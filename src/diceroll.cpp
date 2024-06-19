#include "../include/diceroll.h"
#include <random> // for mt19937 & uniform_int_distribution

int diceRoll( int dice, int sides )
{
    // I 1000% stole this from learncpp.com, and I am not ashamed

    std::mt19937 mt{ std::random_device{}() };

    // Generate a random number between 1 * the number of dice and the max available
    // for the chosen dice, times the number of dice.
    // So if you roll 3d6, the minimum it'll roll is 3 and the max is 18 (3*1 to 3*6)
    std::uniform_int_distribution<int> die{ dice, sides * dice };

    int roll{ die(mt) };

    return roll;
}