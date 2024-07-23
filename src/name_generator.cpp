#include "../include/name_generator.h"
#include "../include/diceroll.h"
#include <random>
#include <iostream>
#include <fstream>
#include <string>


//int main()
//{
//    std::string name = genName();
//
//    std::cout << name << std::endl;
//
//    return 0;
//}

std::string genName()
{
    std::string f_name, l_name;

    // Working previously, keeping in until new method confirmed
    //std::ifstream first_names("../files/name_generator/first_names.txt");
    //std::ifstream last_names("../files/name_generator/last_names.txt");

    std::ifstream names("../files/name_generator/names.txt");
    
    int i, num1, num2;
    // getline() indexs from 0, and there's 3109 possible choices.
    // I'm going with the -1 route to avoid having to write a whole new function
    // when the diceRoll one works just fine
    num1 = diceRoll(1,3109) - 1;
    num2 = diceRoll(1,3109) - 1;

    // I don't want the same name twice, so reroll
    if (num1 == num2)
        num2 = diceRoll(1, 3109) - 1;

    for (i = 0; i <= num1; ++i)
    {
        getline(names, f_name);
    }

    for (i = 0; i <= num2; ++i)
    {
        getline(names, l_name);
    }
    names.close();

    std::string random_name = f_name + " " + l_name;


    return random_name;
}

