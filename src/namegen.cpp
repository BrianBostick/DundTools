#include "../include/name_generator.h"
#include <iostream>
#include <string>

int main()
{
    std::string name = genName();

    std::cout << name << std::endl;

    return 0;
}
