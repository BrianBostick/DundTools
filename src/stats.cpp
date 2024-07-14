#include "../include/character_creator.h"
#include "../include/diceroll.h"
#include "../include/logos.h"
#include "../include/stats.h"
#include <ncurses.h>
#include <string>




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


Character stdArray(WINDOW *win, int x_max, std::string char_class, Character character)
{
    std::string stat_list[6] = {"Str", "Dex", "Con", "Int", "Wis", "Cha"};

    std::string class_list[12] = {"Barbarian", "Bard", "Cleric", "Druid",
                                  "Fighter", "Monk", "Paladin", "Ranger",
                                  "Rogue", "Sorcerer", "Warlock", "Wizard"};

    std::string class_suggestions[12] = {"Str", "Cha", "Wis", "Wis", "Str", "Dex",
                                         "Cha", "Dex", "Dex", "Cha", "Cha", "Int"};
    int suggest_index;
    int highlight = 0;
    int choice;
    int stat_choices[6] = {0, 0, 0, 0, 0, 0};

    std::string stat1 = "";
    std::string stat2 = "";
    std::string stat3 = "";
    std::string stat4 = "";
    std::string stat5 = "";

    int check = 0;
    while(check < 12)
    {
        if (char_class == class_list[check])
        {
            suggest_index = check;
            break;
        } else {
            ++check;
        }
    }
    
    refreshWindow(win);

    while(1)
    {
GET_STATS:
        refreshWindow(win);
        for (int i = 0; i <6; ++i)
        {
            if (i == highlight)
            {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, i + 5, 1, "%s", stat_list[i].c_str());
            wattroff(win, A_REVERSE);
            mvwprintw(win, 1, x_max / 2 - 7, "Standard Array");
            if (stat1 == "")
            {
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 1st stat (15)");
                mvwprintw(win, 3, x_max / 2 - 13, "Suggestion for class: %s", class_suggestions[suggest_index].c_str());
            }
            else if (stat2 == "")
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 2nd stat (14)");
            else if (stat3 == "")
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 3rd stat (13)");
            else if (stat4 == "")
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 4th stat (12)");
            else
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 5th stat (10)");
        }

        choice = wgetch(win);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 5;
                refreshWindow(win);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 5;
                refreshWindow(win);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 6)
                    highlight = 0;
                refreshWindow(win);
                break;
            case 106:
                highlight++;
                if (highlight == 6)
                    highlight = 0;
                refreshWindow(win);
                break;
            default:
                break;
        }
        if (choice == 113)
            break;
        if (choice == 10)
        {
            if (stat1 == "")
            {
                stat1 = stat_list[highlight];
                goto GET_STATS;
            }
            else if (stat2 == "")
            {
                stat2 = stat_list[highlight];
                goto GET_STATS;
            }
            else if (stat3 == "")
            {
                stat3 = stat_list[highlight];
                goto GET_STATS;
            }
            else if (stat4 == "")
            {
                stat4 = stat_list[highlight];
                goto GET_STATS;
            }
            else if (stat5 == "")
            {
                stat5 = stat_list[highlight];
            }
            break;
        }
        refreshWindow(win);

    }
        
    for (int index = 0; index < 6; ++index)
    {
        if (stat1 == stat_list[index])
            stat_choices[index] = 15;
        else if (stat2 == stat_list[index])
            stat_choices[index] = 14;
        else if (stat3 == stat_list[index])
            stat_choices[index] = 13;
        else if (stat4 == stat_list[index])
            stat_choices[index] = 12;
        else if (stat5 == stat_list[index])
            stat_choices[index] = 10;
        else
            stat_choices[index] = 8;
    }

    character = Character(stat_choices[0], stat_choices[1], stat_choices[2],
                          stat_choices[3], stat_choices[4], stat_choices[5]);
    endwin();

    return character;
}

Character rollStats(WINDOW* win, int x_max, Character character, std::string char_class)
{
    std::string stat_list[6] = {"Str", "Dex", "Con", "Int", "Wis", "Cha"};

    std::string class_list[12] = {"Barbarian", "Bard", "Cleric", "Druid",
                                  "Fighter", "Monk", "Paladin", "Ranger",
                                  "Rogue", "Sorcerer", "Warlock", "Wizard"};

    std::string class_suggestions[12] = {"Str", "Cha", "Wis", "Wis", "Str", "Dex",
                                         "Cha", "Dex", "Dex", "Cha", "Cha", "Int"};
    int suggest_index = 0;
    int highlight = 0;
    int choice;

    // If I try to initialize the array with diceRoll() functions, every index is the same
    int rolled_stats[6];
    rolled_stats[0] = getStats();
    rolled_stats[1] = getStats();
    rolled_stats[2] = getStats();
    rolled_stats[3] = getStats();
    rolled_stats[4] = getStats();
    rolled_stats[5] = getStats();

    int stat_choices[6] = {0, 0, 0, 0, 0, 0};

    std::string stat1 = "";
    std::string stat2 = "";
    std::string stat3 = "";
    std::string stat4 = "";
    std::string stat5 = "";
   
    int check = 0;
    while(check < 12)
    {
        if (char_class == class_list[check])
        {
            suggest_index = check;
            break;
        } else {
            ++check;
        }
    }

    // Sort rolls from geatest to least
    // I'm sure there's a thousand better ways to do this, but I don't feel like looking up
    // new functions to do one thing since this works just fine
    int swap;
    int i = 0;
    int j = 0;
    while(i < 5)
    {
        while(j < 5)
        {
            if (rolled_stats[j] < rolled_stats[j + 1])
            {
                swap = rolled_stats[j];
                rolled_stats[j] = rolled_stats[j + 1];
                rolled_stats[j + 1] = swap;
            }
            ++j;
        }
        j = 0;
        ++i;
    }

    while(1)
    {
        refreshWindow(win);
        for (int i = 0; i <6; ++i)
        {
            if (i == highlight)
            {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, i + 5, 1, "%s", stat_list[i].c_str());
            wattroff(win, A_REVERSE);
            mvwprintw(win, 1, x_max / 2 - 7, "Standard Array");
            if (stat1 == "")
            {
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 1st stat (%d)", rolled_stats[0]);
                mvwprintw(win, 3, x_max / 2 - 13, "Suggestion for class: %s", class_suggestions[suggest_index].c_str());
            }
            else if (stat2 == "")
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 2nd stat (%d)", rolled_stats[1]);
            else if (stat3 == "")
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 3rd stat (%d)", rolled_stats[2]);
            else if (stat4 == "")
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 4th stat (%d)", rolled_stats[3]);
            else
                mvwprintw(win, 2, x_max / 2 - 8, "Select your 5th stat (%d)", rolled_stats[5]);
        }

        choice = wgetch(win);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 5;
                refreshWindow(win);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 5;
                refreshWindow(win);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 6)
                    highlight = 0;
                refreshWindow(win);
                break;
            case 106:
                highlight++;
                if (highlight == 6)
                    highlight = 0;
                refreshWindow(win);
                break;
            default:
                break;
        }
        if (choice == 113)
            break;
        if (choice == 10)
        {
            if (stat1 == "")
            {
                stat1 = stat_list[highlight];
                continue;
            }
            else if (stat2 == "")
            {
                stat2 = stat_list[highlight];
                continue;
            }
            else if (stat3 == "")
            {
                stat3 = stat_list[highlight];
                continue;
            }
            else if (stat4 == "")
            {
                stat4 = stat_list[highlight];
                continue;
            }
            else if (stat5 == "")
            {
                stat5 = stat_list[highlight];
            }
            break;
        }
        refreshWindow(win);

    }
        
    for (int index = 0; index < 6; ++index)
    {
        if (stat1 == stat_list[index])
            stat_choices[index] = rolled_stats[0];
        else if (stat2 == stat_list[index])
            stat_choices[index] = rolled_stats[1];
        else if (stat3 == stat_list[index])
            stat_choices[index] = rolled_stats[2];
        else if (stat4 == stat_list[index])
            stat_choices[index] = rolled_stats[3];
        else if (stat5 == stat_list[index])
            stat_choices[index] = rolled_stats[4];
        else
            stat_choices[index] = rolled_stats[5];
    }

    character = Character(stat_choices[0], stat_choices[1], stat_choices[2],
                          stat_choices[3], stat_choices[4], stat_choices[5]);

    return character;
}

// 7-9
Character manualStats(WINDOW* win, int x_max, Character character)
{
    int stat_choices[6] = {0, 0, 0, 0, 0, 0};
    int i = 0;

    while(1)
    {
        refreshWindow(win);
        // 7-13 - This isn't printing for some reason??
        mvwprintw(win, 1, x_max / 2 - 6, "Manual Input");
        if (stat_choices[0] == 0)
        {
            mvwprintw(win, 2, x_max / 2 - 4, "Enter Str");
        } else if (stat_choices[1] == 0) {
            mvwprintw(win, 2, x_max / 2 - 4, "Enter Dex");
        } else if (stat_choices[2] == 0) {
            mvwprintw(win, 2, x_max / 2 - 4, "Enter Con");
        } else if (stat_choices[3] == 0) {
            mvwprintw(win, 2, x_max / 2 - 4, "Enter Int");
        } else if (stat_choices[4] == 0) {
            mvwprintw(win, 2, x_max / 2 - 4, "Enter Wis");
        } else {
            mvwprintw(win, 2, x_max / 2 - 4, "Enter Cha");
        }
        wrefresh(win);

        if (stat_choices[i] == 0)
        {
            stat_choices[i] = getStatInput(win, x_max);
            ++i;
            continue;
        } else {
            break;
        }
    }

    character = Character(stat_choices[0], stat_choices[1], stat_choices[2],
                          stat_choices[3], stat_choices[4], stat_choices[5]);

    return character;
}

int getStatInput(WINDOW* win, int x_max)
{
    int y_max = getmaxy(win);
    WINDOW *textbox = newwin(3, 10, y_max, x_max - 6);
    box(textbox, 0, 0);

    keypad(textbox, true);

    echo();
    curs_set(1);
    wmove(textbox, 1, 1);



    char input[10];
    input[0] = wgetch(textbox);
    int i = 1;
    while(input[i - 1] != '\n')
    {
        input[i] = wgetch(textbox);
        if (input[i - 1] == KEY_BACKSPACE)
        {
            wmove(textbox, 1, i);
            wprintw(textbox, " ");
            wmove(textbox, 1, i);
            i = i - 1;
        }
        else
        {
            ++i;
        }
    }
    input[9] = '\0';
    char *endp;
    
    int stat = strtoimax(input, &endp, 10);

    noecho();
    curs_set(0);
    endwin();

    return stat;
}
