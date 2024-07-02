#include "../include/character_creator.h"
#include "../include/diceroll.h"
#include "../include/logos.h"
#include "../include/stats.h"
#include <string>


int rollStats()
{
    int roll;
    while (roll < 8)
    {
        roll = diceRoll(3, 6);
    }

    return roll;
}


int getStrNoSub(std::string char_race)
{
    int mod;
    if (char_race == "Tiefling")
    {
        mod = 0;
    } else {
        mod = 2;
    }
    
    return mod;
}
int getStrSub(std::string char_sub)
{
    std::string sub_races[11] = {"Hill", "Mountain", "Drow", "High", "Wood",
                                 "Forest", "Rock", "Lightfoot", "Stout", "Base", "Variant"};
    int index = 0;
    int mod;
    int i = 0;
    
    while(1)
    {
        if (char_sub == sub_races[i])
        {
            index = i;
            break;
        } else {
            ++i;
        }
    }
    
    switch(index)
    {
        case 0:
            mod = 0;
            break;
        case 1:
            mod = 2;
            break;
        case 2:
            mod = 0;
            break;
        case 3:
            mod = 0;
            break;
        case 4:
            mod = 0;
            break;
        case 5:
            mod = 0;
            break;
        case 6:
            mod = 0;
            break;
        case 7:
            mod = 0;
            break;
        case 8:
            mod = 0;
            break;
        case 9:
            mod = 1;
            break;
        case 10:
            mod = 0;
            break;
        default:
            break;
    }

    return mod;
}

int getDexNoSub(std::string char_race)
{
    int mod;
    if (char_race == "Half-Orc")
    {
        mod = 0;
    } else if (char_race == "Tiefling") {
        mod = 0;
    } else if (char_race == "Dragonborn") {
        mod = 0;
    }
    
    return mod;
}
int getDexSub(std::string char_sub)
{
    std::string sub_races[11] = {"Hill", "Mountain", "Drow", "High", "Wood",
                                 "Forest", "Rock", "Lightfoot", "Stout", "Base", "Variant"};
    int index = 0;
    int mod;
    int i = 0;
    
    while(1)
    {
        if (char_sub == sub_races[i])
        {
            index = i;
            break;
        } else {
            ++i;
        }
    }
    
    switch(index)
    {
        case 0:
            mod = 0;
            break;
        case 1:
            mod = 0;
            break;
        case 2:
            mod = 2;
            break;
        case 3:
            mod = 2;
            break;
        case 4:
            mod = 2;
            break;
        case 5:
            mod = 1;
            break;
        case 6:
            mod = 0;
            break;
        case 7:
            mod = 2;
            break;
        case 8:
            mod = 2;
            break;
        case 9:
            mod = 1;
            break;
        case 10:
            mod = 0;
            break;
        default:
            break;
    }

    return mod;
}

int getConNoSub(std::string char_race)
{
    int mod;
    if (char_race == "Half-Orc")
    {
        mod = 1;
    } else if (char_race == "Tiefling") {
        mod = 0;
    } else if (char_race == "Dragonborn") {
        mod = 0;
    }
    
    return mod;
}
int getConSub(std::string char_sub)
{
    std::string sub_races[11] = {"Hill", "Mountain", "Drow", "High", "Wood",
                                 "Forest", "Rock", "Lightfoot", "Stout", "Base", "Variant"};
    int index = 0;
    int mod;
    int i = 0;
    
    while(1)
    {
        if (char_sub == sub_races[i])
        {
            index = i;
            break;
        } else {
            ++i;
        }
    }
    
    switch(index)
    {
        case 0:
            mod = 2;
            break;
        case 1:
            mod = 2;
            break;
        case 2:
            mod = 0;
            break;
        case 3:
            mod = 0;
            break;
        case 4:
            mod = 0;
            break;
        case 5:
            mod = 0;
            break;
        case 6:
            mod = 1;
            break;
        case 7:
            mod = 0;
            break;
        case 8:
            mod = 1;
            break;
        case 9:
            mod = 1;
            break;
        case 10:
            mod = 0;
            break;
        default:
            break;
    }

    return mod;
}

int getIntNoSub(std::string char_race)
{
    int mod;
    if (char_race == "Half-Orc")
    {
        mod = 0;
    } else if (char_race == "Tiefling") {
        mod = 1;
    } else if (char_race == "Dragonborn") {
        mod = 0;
    }
    
    return mod;
}
int getIntSub(std::string char_sub)
{
    std::string sub_races[11] = {"Hill", "Mountain", "Drow", "High", "Wood",
                                 "Forest", "Rock", "Lightfoot", "Stout", "Base", "Variant"};
    int index = 0;
    int mod;
    int i = 0;
    
    while(1)
    {
        if (char_sub == sub_races[i])
        {
            index = i;
            break;
        } else {
            ++i;
        }
    }
    
    switch(index)
    {
        case 0:
            mod = 0;
            break;
        case 1:
            mod = 0;
            break;
        case 2:
            mod = 0;
            break;
        case 3:
            mod = 1;
            break;
        case 4:
            mod = 0;
            break;
        case 5:
            mod = 2;
            break;
        case 6:
            mod = 2;
            break;
        case 7:
            mod = 0;
            break;
        case 8:
            mod = 0;
            break;
        case 9:
            mod = 1;
            break;
        case 10:
            mod = 0;
            break;
        default:
            break;
    }

    return mod;
}

int getWisNoSub(std::string char_race)
{
    int mod;
    if (char_race == "Half-Orc")
    {
        mod = 0;
    } else if (char_race == "Tiefling") {
        mod = 0;
    } else if (char_race == "Dragonborn") {
        mod = 0;
    }
    
    return mod;
}
int getWisSub(std::string char_sub)
{
    std::string sub_races[11] = {"Hill", "Mountain", "Drow", "High", "Wood",
                                 "Forest", "Rock", "Lightfoot", "Stout", "Base", "Variant"};
    int index = 0;
    int mod;
    int i = 0;

    while(1)
    {
        if (char_sub == sub_races[i])
        {
            index = i;
            break;
        } else {
            ++i;
        }
    }
    
    switch(index)
    {
        case 0:
            mod = 1;
            break;
        case 1:
            mod = 0;
            break;
        case 2:
            mod = 0;
            break;
        case 3:
            mod = 0;
            break;
        case 4:
            mod = 1;
            break;
        case 5:
            mod = 0;
            break;
        case 6:
            mod = 0;
            break;
        case 7:
            mod = 0;
            break;
        case 8:
            mod = 0;
            break;
        case 9:
            mod = 1;
            break;
        case 10:
            mod = 0;
            break;
        default:
            break;
    }

    return mod;
}

int getChaNoSub(std::string char_race)
{
    int mod;
    if (char_race == "Half-Orc")
    {
        mod = 0;
    } else if (char_race == "Tiefling") {
        mod = 2;
    } else if (char_race == "Dragonborn") {
        mod = 1;
    }
    
    return mod;
}
int getChaSub(std::string char_sub)
{
    std::string sub_races[11] = {"Hill", "Mountain", "Drow", "High", "Wood",
                                 "Forest", "Rock", "Lightfoot", "Stout", "Base", "Variant"};
    int index = 0;
    int mod;
    int i = 0;

    while(1)
    {
        if (char_sub == sub_races[i])
        {
            index = i;
            break;
        } else {
            ++i;
        }
    }
    
    switch(index)
    {
        case 0:
            mod = 0;
            break;
        case 1:
            mod = 0;
            break;
        case 2:
            mod = 1;
            break;
        case 3:
            mod = 0;
            break;
        case 4:
            mod = 0;
            break;
        case 5:
            mod = 0;
            break;
        case 6:
            mod = 0;
            break;
        case 7:
            mod = 1;
            break;
        case 8:
            mod = 0;
            break;
        case 9:
            mod = 1;
            break;
        case 10:
            mod = 0;
            break;
        default:
            break;
    }

    return mod;
}
