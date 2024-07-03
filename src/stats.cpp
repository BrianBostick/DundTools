#include "../include/character_creator.h"
#include "../include/diceroll.h"
#include "../include/logos.h"
#include "../include/stats.h"
#include <ncurses.h>
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


void stdArray1(WINDOW *win, int x_max, std::string char_class)
{

    keypad(win, true);

    std::string class_list[12] = {"Barbarian", "Bard", "Cleric", "Druid",
                                  "Fighter", "Monk", "Paladin", "Ranger",
                                  "Rogue", "Sorcerer", "Warlock", "Wizard"};
    std::string class_suggestions[12] = {"Str", "Cha", "Wis", "Wis", "Str", "Dex",
                                         "Cha", "Dex", "Dex", "Cha", "Cha", "Int"};
    int suggest_index;
    int highlight = 0;
    int choice;

    for (int i = 0; i < 12; ++i)
    {
        if (char_class == class_list[i])
        {
            suggest_index = i;
            break;
        } else {
            ++i;
        }
    }
    
    wclear(win);
    box(win, 0, 0);
    wrefresh(win);

    while(1)
    {
        std::string stat_list[6] = {"Str", "Dex", "Con", "Int", "Wis", "Cha"};
        int length = 5;
        for (int i = 0; i < 6; ++i)
        {
            if (i == highlight)
            {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, i + 5, 1, "%s", stat_list[i].c_str());
            wattroff(win, A_REVERSE);
            mvwprintw(win, 1, x_max / 2 - 7, "Standard Array");
            mvwprintw(win, 2, x_max / 2 - 14, "Select your first stat (15)");
            mvwprintw(win, 3, x_max / 2 - 13, "Suggestion for class: %s", class_suggestions[suggest_index].c_str());
        }

        choice = wgetch(win);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = length;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = length;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == length + 1)
                    highlight = 0;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case 106:
                highlight++;
                if (highlight == length + 1)
                    highlight = 0;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            default:
                break;
        }
        if (choice == 113)
            break;
        if (choice == 10)
            break;
        wclear(win);
        box(win, 0, 0);
        wrefresh(win);
    }
}
