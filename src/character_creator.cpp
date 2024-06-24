#include "../include/character_creator.h"
#include "../include/diceroll.h"
#include "../include/logos.h"
#include <ncurses.h>
#include <string>

void genCCWindow()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    int mainwin_y_max, mainwin_x_max;
    getmaxyx(stdscr, mainwin_y_max, mainwin_x_max);
    box(stdscr, 0, 0);

    printLogo(stdscr, 2, 50);
    printCCLogo(stdscr, mainwin_y_max, mainwin_x_max);
    refresh();

    WINDOW *centerwin = newwin(mainwin_y_max / 2, mainwin_x_max / 2, mainwin_y_max / 4, mainwin_x_max / 4);
    int centerwin_y_max, centerwin_x_max;
    getmaxyx(centerwin, centerwin_y_max, centerwin_x_max);
    box(centerwin, 0, 0);
    wrefresh(centerwin);
    keypad(centerwin, true);

    std::string choices[1] = {"New Character"};
    int choice;
    int highlight = 0;

    std::string player_name;
    std::string char_name;
    std::string char_class;
    std::string char_race;
    bool has_sub;
    std::string char_sub;

    while(1)
    {
        for (int i = 0; i < 1; i++)
        {
            if (i == highlight)
            {
                wattron(centerwin, A_REVERSE);
            }
            mvwprintw(centerwin, i + 1, 1, "%s", choices[i].c_str());
            wattroff(centerwin, A_REVERSE);
        }

        choice = wgetch(centerwin);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                wclear(centerwin);
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                wclear(centerwin);
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 1)
                    highlight = 0;
                wclear(centerwin);
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            case 106:
                highlight++;
                if (highlight == 1)
                    highlight = 0;
                wclear(centerwin);
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            default:
                break;
        }
        if (choice == 113)
            break;
        if (choice == 10 && highlight == 0) {
            player_name = getPlayerName(centerwin, centerwin_y_max, centerwin_x_max);
            char_name = getCharName(centerwin, centerwin_y_max, centerwin_x_max);
            char_class = getCharClass(centerwin, centerwin_x_max);
            char_race = getCharRace(centerwin, centerwin_x_max);
            has_sub = checkForSub(char_race);
            if (has_sub == true)
                char_sub = getCharSubRace(centerwin, centerwin_x_max, char_race);

        }
        wclear(centerwin);
        box(centerwin, 0, 0);
        // For debugging purposes
        if (has_sub == true)
        {
            mvwprintw(centerwin, centerwin_y_max - 7, 2, "Player Name: %s", player_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 6, 2, "Character Name: %s", char_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 5, 2, "Class: %s",  char_class.c_str());
            mvwprintw(centerwin, centerwin_y_max - 4, 2, "Race: %s", char_race.c_str());
            mvwprintw(centerwin, centerwin_y_max - 3, 2, "Has Sub?: %d", has_sub);
            mvwprintw(centerwin, centerwin_y_max - 2, 2, "Sub-Race: %s", char_sub.c_str());
        } else {
            mvwprintw(centerwin, centerwin_y_max - 5, 2, "Player Name: %s", player_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 4, 2, "Character Name: %s", char_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 3, 2, "Class: %s",  char_class.c_str());
            mvwprintw(centerwin, centerwin_y_max - 2, 2, "Race: %s", char_race.c_str());
        }
           
        wrefresh(centerwin);
    }
    endwin();
}


std::string getPlayerName(WINDOW *win, int y_max, int x_max)
{
    std::string player_name;
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, y_max / 2, x_max / 2 - 15, "Enter Your (the Player's) name:");

    int mainwin_y_max, mainwin_x_max;
    getmaxyx(stdscr, mainwin_y_max, mainwin_x_max);
    WINDOW *textwin = newwin(3, 20, mainwin_y_max / 2 + 1, mainwin_x_max / 2 - 12);
    box(textwin, 0, 0);

    curs_set(1);
    echo();

    wrefresh(win);
    wrefresh(textwin);
    wmove(textwin, 1, 1);
    char ch = wgetch(textwin);
    while (ch != '\n')
    {
       player_name.push_back(ch); 
       ch = wgetch(textwin);
    }


    curs_set(0);
    noecho();
    endwin();

    return player_name;
}

std::string getCharName(WINDOW *win, int y_max, int x_max)
{
    std::string char_name;
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, y_max / 2, x_max / 2 - 14, "Enter Your Character's Name:");

    int mainwin_y_max, mainwin_x_max;
    getmaxyx(stdscr, mainwin_y_max, mainwin_x_max);
    WINDOW *textwin = newwin(3, 20, mainwin_y_max / 2 + 1, mainwin_x_max / 2 - 12);
    box(textwin, 0, 0);

    curs_set(1);
    echo();

    wrefresh(win);
    wrefresh(textwin);
    wmove(textwin, 1, 1);
    char ch = wgetch(textwin);
    while (ch != '\n')
    {
       char_name.push_back(ch); 
       ch = wgetch(textwin);
    }


    curs_set(0);
    noecho();
    endwin();

    return char_name;
}

std::string getCharClass(WINDOW *win, int x_max)
{
    wclear(win);
    box(win, 0, 0);
   
    std::string selected_class;
    std::string class_list[12] = {"Barbarian", "Bard", "Cleric", "Druid",
                                  "Fighter", "Monk", "Paladin", "Ranger",
                                  "Rogue", "Sorcerer", "Warlock", "Wizard"};
    std::string stat_suggestions[12] = {"Top Stats: Str, Con",
                                        "Top Stats: Cha, Dex",
                                        "Top Stats: Wis, Con",
                                        "Top Stats: Wis, Dex",
                                        "Top Stats: Str, Con",
                                        "Top Stats: Dex, Con / Str, Con, / Wis, Con (Depending on build)",
                                        "Top Stats: Cha, Str/Con (Depending on build)",
                                        "Top Stats: Dex, Wis",
                                        "Top Stats: Dex, Wis/Cha (Depending on build, RP purposes)",
                                        "Top Stats: Cha, Con",
                                        "Top Stats: Cha, Dex/Con (Depending on build)",
                                        "Top Stats: Int, Dex"};

    int choice;
    int highlight = 0;
    while(1)
    {
        for (int i = 0; i < 12; ++i)
        {
           if (i == highlight)
           {
               wattron(win, A_REVERSE);
           }
           mvwprintw(win, i + 5, 1, "%s", class_list[i].c_str());
           wattroff(win, A_REVERSE);
           mvwprintw(win, 1, x_max / 2 - 19, "Choose Your Class From the List Below:");
           mvwprintw(win, 2, x_max / 2 - stat_suggestions[highlight].length() / 2, "%s", stat_suggestions[highlight].c_str());
        }

        choice = wgetch(win);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 11;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 11;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 12)
                    highlight = 0;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case 106:
                highlight++;
                if (highlight == 12)
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
    }

    selected_class = class_list[highlight];
    wclear(win);
    endwin();

    return selected_class;
}

std::string getCharRace(WINDOW *win, int x_max)
{
    wclear(win);
    box(win, 0, 0);

    std::string selected_race;
    std::string race_list[9] = {"Dragonborn", "Dwarf", "Elf", "Gnome", "Half-Elf",
                                 "Half-Orc", "Halfling", "Human", "Tiefling"};
    std::string race_desc[9] = {"+2 Str, +1 Cha, Breath Weapon",
                                "+2 Con, +2 Str/+1 Wis (Depending on subrace), Darkvision",
                                "+2 Dex, +1 Cha/Int/Wis (Depending on subrace), Darkvision",
                                "+2 Int, +1 Dex/Con (Depending on subrace), Darkvision",
                                "+2 Cha, +1 to 2 Stats of player choice, Darkvision",
                                "+2 Str, +1 Con, Darkvision",
                                "+2 Des, +1 Cha/Con (Depending on subrace)",
                                "+1 All Stats/+1 to 2 Stats of player choice + 1 Feat (Variant Option)",
                                "+2 Cha, +1 Int, Darkvision"};

    int choice;
    int highlight = 0;
    while(1)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (i == highlight)
            {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, 5 + i, 1, "%s", race_list[i].c_str());
            wattroff(win, A_REVERSE);
            mvwprintw(win, 1, x_max / 2 - 18, "Choose Your Race From the List Below:");
            mvwprintw(win, 2, (x_max / 2) - (race_desc[highlight].length() / 2), "%s", race_desc[highlight].c_str());
        }

        choice = wgetch(win);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 8;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 8;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 9)
                    highlight = 0;
                wclear(win);
                box(win, 0, 0);
                wrefresh(win);
                break;
            case 106:
                highlight++;
                if (highlight == 9)
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
    }

    selected_race = race_list[highlight];
    wclear(win);
    endwin();

    return selected_race;
}

bool checkForSub(std::string race)
{
    std::string race_list[9] = {"Dragonborn", "Dwarf", "Elf", "Gnome", "Half-Elf",
                             "Half-Orc", "Halfling", "Human", "Tiefling"};
    bool has_sub[9] = {true, true, true, true, true, false, true, true, false};

    for (int i = 0; i < 9; ++i)
    {
        if (race == race_list[i])
            return has_sub[i];
    }
}

std::string getCharSubRace(WINDOW *win, int x_max, std::string race)
{
    std::string race_list[9] = {"Dragonborn", "Dwarf", "Elf", "Gnome", "Half-Elf",
                             "Halfling", "Human"};
    int race_index;
    std::string chosen_sub;

    std::string stats_list[6] = {"Str", "Dex", "Con", "Int", "Wis", "Cha"};

    std::string db_subs[10] = {"Black", "Blue", "Brass", "Bronze", "Copper",
                               "Gold", "Green", "Red", "Silver", "White"};
    std::string db_sub_desc[10] = {"Breath: Acid, 5x30ft line (Dex Save)",
                                   "Breath: Lightning, 5x30ft line (Dex Save)",
                                   "Breath: Fire, 5x30ft line (Dex Save)",
                                   "Breath: Lightning, 5x30ft line (Dex Save)",
                                   "Breath: Acid, 5x30ft line (Dex Save)",
                                   "Breath: Fire, 15ft cone (Dex Save)",
                                   "Breath: Poison, 15ft cone (Con Save)",
                                   "Breath: Fire, 15ft cone (Dex Save)",
                                   "Breath: Cold, 15ft cone (Con Save)",
                                   "Breath: Cold, 15ft cone (Con Save)"};
    std::string dwarf_subs[2] = {"Hill", "Mountain"};
    std::string dwarf_sub_desc[2] = {"Stat Mods: +2 Con, +1 Wis",
                                     "Stat Mods: +2 Con, +2 Str"};
    std::string elf_subs[3] = {"Drow", "High", "Wood"};
    std::string elf_sub_desc[3] = {"Stat Mods: +2 Dex, +1 Cha",
                                   "Stat Mods: +2 Dex, +1 Int",
                                   "Stat Mods: +2 Dex, +1 Wis"};
    std::string gnome_subs[2] = {"Forest", "Rock"};
    std::string gnome_sub_desc[2] = {"Stat Mods: +2 Int, +1 Dex",
                                     "Stat Mods: +2 Int, +1 Con"};
    std::string halfling_subs[2] = {"Lightfoot", "Stout"};
    std::string halfling_sub_desc[2] = {"Stat Mods: +2 Dex, +1 Cha",
                                        "Stat Mods: +2 Dex, +1 Con"};
    std::string human_subs[2] = {"Base", "Variant"};
    std::string human_sub_desc[2] = {"+1 to all stats",
                                     "+1 to 2 stats of player choice, 1 feat"};

    int index = 0;
    while(1)
    {
        if (race != race_list[index])
        {
            ++index;
        } else {
            race_index = index;
            break;
        }
    }


    int choice;
    int highlight = 0;
    bool end = false;
    switch(race_index)
    {
        case 0:
            wclear(win);
            box(win, 0, 0);
            while(end == false)
            {
                for (int i = 0; i < 10; ++i)
                {
                    if (i == highlight)
                    {
                        wattron(win, A_REVERSE);
                    }
                    mvwprintw(win, 5 + i, 1, "%s", db_subs[i].c_str());
                    wattroff(win, A_REVERSE);
                    mvwprintw(win, 1, x_max / 2 - 20, "Choose Your Sub-Race From the List Below:");
                    mvwprintw(win, 2, x_max / 2 - db_sub_desc[highlight].length() / 2, "%s", db_sub_desc[highlight].c_str());
                }

                choice = wgetch(win);

                switch(choice)
                {
                    case KEY_UP:
                        highlight--;
                        if (highlight == -1)
                            highlight = 9;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 107:
                        highlight--;
                        if (highlight == -1)
                            highlight = 9;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case KEY_DOWN:
                        highlight++;
                        if (highlight == 10)
                            highlight = 0;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 106:
                        highlight++;
                        if (highlight == 10)
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
                {
                    chosen_sub = db_subs[highlight];
                    end = true;
                    break;
                }
            }
        case 1:
            wclear(win);
            box(win, 0, 0);
            while(end == false)
            {
                for (int i = 0; i < 2; ++i)
                {
                    if (i == highlight)
                    {
                        wattron(win, A_REVERSE);
                    }
                    mvwprintw(win, i + 5, 1, "%s", dwarf_subs[i].c_str());
                    wattroff(win, A_REVERSE);
                    mvwprintw(win, 1, x_max / 2 - 20, "Choose Your Sub-Race From the List Below:");
                    mvwprintw(win, 2, x_max / 2 - dwarf_sub_desc[highlight].length() / 2, "%s", dwarf_sub_desc[highlight].c_str());
                }

                choice = wgetch(win);

                switch(choice)
                {
                    case KEY_UP:
                        highlight--;
                        if (highlight == -1)
                            highlight = 1;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 107:
                        highlight--;
                        if (highlight == -1)
                            highlight = 1;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case KEY_DOWN:
                        highlight++;
                        if (highlight == 2)
                            highlight = 0;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 106:
                        highlight++;
                        if (highlight == 2)
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
                {
                    chosen_sub = dwarf_subs[highlight];
                    end = true;
                    break;
                }
            }
        case 2:
            wclear(win);
            box(win, 0, 0);
            while(end == false)
            {
                for (int i = 0; i < 3; ++i)
                {
                    if (i == highlight)
                    {
                        wattron(win, A_REVERSE);
                    }
                    mvwprintw(win, i + 5, 1, "%s", elf_subs[i].c_str());
                    wattroff(win, A_REVERSE);
                    mvwprintw(win, 1, x_max / 2 - 20, "Choose Your Sub-Race From the List Below:");
                    mvwprintw(win, 2, x_max / 2 - elf_sub_desc[highlight].length() / 2, "%s", elf_sub_desc[highlight].c_str());
                }

                choice = wgetch(win);

                switch(choice)
                {
                    case KEY_UP:
                        highlight--;
                        if (highlight == -1)
                            highlight = 2;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 107:
                        highlight--;
                        if (highlight == -1)
                            highlight = 2;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case KEY_DOWN:
                        highlight++;
                        if (highlight == 3)
                            highlight = 0;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 106:
                        highlight++;
                        if (highlight == 3)
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
                {
                    chosen_sub = elf_subs[highlight];
                    end = true;
                    break;
                }
            }
        case 3:
            wclear(win);
            box(win, 0, 0);
            while(end == false)
            {
                for (int i = 0; i < 2; ++i)
                {
                    if (i == highlight)
                    {
                        wattron(win, A_REVERSE);
                    }
                    mvwprintw(win, i + 5, 1, "%s", gnome_subs[i].c_str());
                    wattroff(win, A_REVERSE);
                    mvwprintw(win, 1, x_max / 2 - 20, "Choose Your Sub-Race From the List Below:");
                    mvwprintw(win, 2, x_max / 2 - gnome_sub_desc[highlight].length() / 2, "%s", gnome_sub_desc[highlight].c_str());
                }

                choice = wgetch(win);

                switch(choice)
                {
                    case KEY_UP:
                        highlight--;
                        if (highlight == -1)
                            highlight = 1;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 107:
                        highlight--;
                        if (highlight == -1)
                            highlight = 1;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case KEY_DOWN:
                        highlight++;
                        if (highlight == 2)
                            highlight = 0;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 106:
                        highlight++;
                        if (highlight == 2)
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
                {
                    chosen_sub = gnome_subs[highlight];
                    end = true;
                    break;
                }
            }
        case 4:
            wclear(win);
            box(win, 0, 0);
            break;
        case 5:
            wclear(win);
            box(win, 0, 0);
            while(end == false)
            {
                for (int i = 0; i < 2; ++i)
                {
                    if (i == highlight)
                    {
                        wattron(win, A_REVERSE);
                    }
                    mvwprintw(win, i + 5, 1, "%s", halfling_subs[i].c_str());
                    wattroff(win, A_REVERSE);
                    mvwprintw(win, 1, x_max / 2 - 20, "Choose Your Sub-Race From the List Below:");
                    mvwprintw(win, 2, x_max / 2 - halfling_sub_desc[highlight].length() / 2, "%s", halfling_sub_desc[highlight].c_str());
                }

                choice = wgetch(win);

                switch(choice)
                {
                    case KEY_UP:
                        highlight--;
                        if (highlight == -1)
                            highlight = 1;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 107:
                        highlight--;
                        if (highlight == -1)
                            highlight = 1;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case KEY_DOWN:
                        highlight++;
                        if (highlight == 2)
                            highlight = 0;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 106:
                        highlight++;
                        if (highlight == 2)
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
                {
                    chosen_sub = halfling_subs[highlight];
                    end = true;
                    break;
                }
            }
        case 6:
            wclear(win);
            box(win, 0, 0);
            while(end == false)
            {
                for (int i = 0; i < 2; ++i)
                {
                    if (i == highlight)
                    {
                        wattron(win, A_REVERSE);
                    }
                    mvwprintw(win, i + 5, 1, "%s", human_subs[i].c_str());
                    wattroff(win, A_REVERSE);
                    mvwprintw(win, 1, x_max / 2 - 20, "Choose Your Sub-Race From the List Below:");
                    mvwprintw(win, 2, x_max / 2 - human_sub_desc[highlight].length() / 2, "%s", human_sub_desc[highlight].c_str());
                }

                choice = wgetch(win);

                switch(choice)
                {
                    case KEY_UP:
                        highlight--;
                        if (highlight == -1)
                            highlight = 1;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 107:
                        highlight--;
                        if (highlight == -1)
                            highlight = 1;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case KEY_DOWN:
                        highlight++;
                        if (highlight == 2)
                            highlight = 0;
                        wclear(win);
                        box(win, 0, 0);
                        wrefresh(win);
                        break;
                    case 106:
                        highlight++;
                        if (highlight == 2)
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
                {
                    chosen_sub = human_subs[highlight];
                    end = true;
                    break;
                }
            }
        default:
            break;
    }
    
    wclear(win);
    endwin();

    return chosen_sub;
}
