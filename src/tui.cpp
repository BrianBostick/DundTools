#include "../include/ascii_nums.h"
#include "../include/character_creator.h"
#include "../include/diceroll.h"
#include "../include/logos.h"
#include "../include/stats.h"
#include "../include/tui.h"
#include <ncurses.h>
#include <inttypes.h>
#include <string>


int main()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    int mainwin_y_max, mainwin_x_max;
    getmaxyx(stdscr, mainwin_y_max, mainwin_x_max);

    box(stdscr, 0, 0);
    refresh();

    // **** HOMEPAGE WINDOWS ****
    int logowin_y_max, logowin_x_max;
    WINDOW *logowin = newwin(mainwin_y_max / 2, mainwin_x_max - 2, 1, 1);
    getmaxyx(logowin, logowin_y_max, logowin_x_max);
    wrefresh(logowin);

    int bottomwin_y_max, bottomwin_x_max;
    WINDOW *bottomwin = newwin((mainwin_y_max / 2) - 2, mainwin_x_max - 2, (mainwin_y_max / 2) + 1, 1);
    getmaxyx(bottomwin, bottomwin_y_max, bottomwin_x_max);
    wrefresh(bottomwin);

    // if the window is large enough, print out an ASCII art logo
    // print out the program title and version number regardless of window size
    printLogo(logowin, logowin_y_max, logowin_x_max);
    // app description, default descwin text
    std::string initdesc[4] = {"A compilation of D&D 5e tools.", "Works best with a full screen terminal", "Arrow keys or J/K to navigate, Enter to select", "Ctrl-C or Q to exit at any time"};
    for (int i = 0; i < 4; i++)
    {
        mvwprintw(logowin, logowin_y_max - 5 + i, 1, "%s", initdesc[i].c_str());
    }
    wrefresh(logowin);


    // **** MAIN MENU ****
    int menuwin_x_max;
    WINDOW *menuwin = newwin(bottomwin_y_max - 2, (bottomwin_x_max / 2) - 2, bottomwin_y_max + 4, 2);
    box(menuwin, 0, 0);
    menuwin_x_max = getmaxx(menuwin);
    keypad(menuwin, true);

    WINDOW *descwin = newwin(bottomwin_y_max - 2, (bottomwin_x_max / 2) - 2, bottomwin_y_max + 4, menuwin_x_max + 4);
    box(descwin, 0, 0);
    
    std::string choices[2] = {"DiceRoll", "Character Creator"};
    std::string descriptions[2] = {"A simple dice roll simulator", "A step-by-step first level character creator"};
    int choice;
    int highlight = 0;
    mvwprintw(descwin, 1, 1, "%s", descriptions[0].c_str());
    wrefresh(descwin);

    // Main loop
    while(1)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, "%s", choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 1;
                wclear(descwin);
                mvwprintw(descwin, 1, 1, "%s", descriptions[highlight].c_str());
                box(descwin, 0, 0);
                wrefresh(descwin);
                break;
            // press k to move cursor up
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 1;
                wclear(descwin);
                mvwprintw(descwin, 1, 1, "%s", descriptions[highlight].c_str());
                box(descwin, 0, 0);
                wrefresh(descwin);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 2)
                    highlight = 0;
                wclear(descwin);
                mvwprintw(descwin, 1, 1, "%s", descriptions[highlight].c_str());
                box(descwin, 0, 0);
                wrefresh(descwin);
                break;
            // press j to move cursor down
            case 106:
                highlight++;
                if (highlight == 2)
                    highlight = 0;
                wclear(descwin);
                mvwprintw(descwin, 1, 1, "%s", descriptions[highlight].c_str());
                box(descwin, 0, 0);
                wrefresh(descwin);
                break;
            default:
                break;
        }

        if (choice == 113) {
            break;
        }
        if (choice == 10 && highlight == 0) {
            endwin();
            genDicerollWindow();
            genHomeWindow(logowin, logowin_y_max, logowin_x_max, bottomwin, menuwin, descwin);
        }
        if (choice == 10 && highlight == 1) {
            endwin();
            genCCWindow();
            genHomeWindow(logowin, logowin_y_max, logowin_x_max, bottomwin, menuwin, descwin);
        }
    }

    endwin();

    return 0;
}

// Window management
void refreshWindow(WINDOW* win)
{
    wclear(win);
    box(win, 0, 0);
    wrefresh(win);
}

// Home Screen
void genHomeWindow(WINDOW *logo, int y_max, int x_max, WINDOW *bottom, WINDOW *menu, WINDOW *desc)
{
    clear();
    box(stdscr, 0, 0);
    refresh();
    genLogoWindow(logo, y_max, x_max);
    refreshWindow(bottom);
    refreshWindow(menu);
    refreshWindow(desc);
}
void genLogoWindow(WINDOW *win, int y_max, int x_max)
{
    printLogo(win, y_max, x_max);
    std::string initdesc[4] = {"A compilation of D&D 5e tools.", "Works best with a full screen terminal", "Arrow keys or J/K to navigate, Enter to select", "Ctrl-C to exit at any time"};
    for (int i = 0; i < 4; i++)
    {
        mvwprintw(win, y_max - 5 + i, 1, "%s", initdesc[i].c_str());
    }
    wrefresh(win);
}

// Character creator
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
        int plus_stat_1;
        int plus_stat_2;
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
                refreshWindow(centerwin);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                refreshWindow(centerwin);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 1)
                    highlight = 0;
                refreshWindow(centerwin);
                break;
            case 106:
                highlight++;
                if (highlight == 1)
                    highlight = 0;
                refreshWindow(centerwin);
                break;
            default:
                break;
        }
        if (choice == 113)
            break;
        if (choice == 10 && highlight == 0) {
            player_name = getPlayerName(centerwin, centerwin_x_max);
            char_name = getCharName(centerwin, centerwin_x_max);
            char_class = getCharClass(centerwin, centerwin_x_max);
            char_race = getCharRace(centerwin, centerwin_x_max);
            has_sub = checkForSub(char_race);
            if (char_race == "Half-Elf")
            {
                std::string stat_list[5] = {"Str", "Dex", "Con", "Int", "Wis"};
                int length = 4;
                plus_stat_1 = plusOne(centerwin, centerwin_x_max, stat_list, length);
                for (int i = plus_stat_1; i < 4; i++)
                {
                    stat_list[i] = stat_list[i + 1];
                }
                length = 3;
                plus_stat_2 = plusOne(centerwin, centerwin_x_max, stat_list, length) + 1;
                // If you select Dex as plus_stat_1 and Str as plus_stat_2, 2 points get
                // added to Dex. The following conditional fixes that
                if (plus_stat_2 == 1 && plus_stat_1 == 1)
                    plus_stat_2 = 0;
            } else if (has_sub == true) {
                char_sub = getCharSubRace(centerwin, centerwin_x_max, char_race);
            }
            if (char_sub == "Variant")
            {
                std::string stat_list[6] = {"Str", "Dex", "Con", "Int", "Wis", "Cha"};
                int length = 5;
                plus_stat_1 = plusOne(centerwin, centerwin_x_max, stat_list, length);
                for (int i = plus_stat_1; i < 5; i++)
                {
                    stat_list[i] = stat_list[i + 1];
                }
                length = 4;
                plus_stat_2 = plusOne(centerwin, centerwin_x_max, stat_list, length) + 1;
                // If you select Dex as plus_stat_1 and Str as plus_stat_2, 2 points get
                // added to Dex. The following conditional fixes that
                if (plus_stat_2 == 1 && plus_stat_1 == 1)
                    plus_stat_2 = 0;
            } 
        }
        refreshWindow(centerwin);

        // Character object & base stats set to 0
        Character New_Character(0, 0, 0, 0, 0, 0);
        if ((char_race == "Dragonborn") || (has_sub == false))
        {
            New_Character = Character(getStrNoSub(char_race), getDexNoSub(char_race),
                                      getConNoSub(char_race), getIntNoSub(char_race),
                                      getWisNoSub(char_race), getChaNoSub(char_race));
        } else if (char_race == "Half-Elf") {
            switch(plus_stat_1)
            {
            case 0:
                New_Character.str_base += 1;
                break;
            case 1:
                New_Character.dex_base += 1;
                break;
            case 2:
                New_Character.con_base += 1;
                break;
            case 3:
                New_Character.int_base += 1;
                break;
            case 4:
                New_Character.wis_base += 1;
                break;
            default:
                break;
            }

            switch(plus_stat_2)
            {
            case 0:
                New_Character.str_base += 1;
                break;
            case 1:
                New_Character.dex_base += 1;
                break;
            case 2:
                New_Character.con_base += 1;
                break;
            case 3:
                New_Character.int_base += 1;
                break;
            case 4:
                New_Character.wis_base += 1;
                break;
            default:
                break;
            }
            New_Character.cha_base += 2;
        } else if (char_sub == "Variant") {
            switch(plus_stat_1)
            {
            case 0:
                New_Character.str_base += 1;
                break;
            case 1:
                New_Character.dex_base += 1;
                break;
            case 2:
                New_Character.con_base += 1;
                break;
            case 3:
                New_Character.int_base += 1;
                break;
            case 4:
                New_Character.wis_base += 1;
                break;
            default:
                break;
            }

            switch(plus_stat_2)
            {
            case 0:
                New_Character.str_base += 1;
                break;
            case 1:
                New_Character.dex_base += 1;
                break;
            case 2:
                New_Character.con_base += 1;
                break;
            case 3:
                New_Character.int_base += 1;
                break;
            case 4:
                New_Character.wis_base += 1;
                break;
            default:
                break;
            }
            New_Character.cha_base += 2;
        } else if (char_race != "Dragonborn" && has_sub == true) {
            New_Character = Character(getStrSub(char_sub), getDexSub(char_sub),
                                      getConSub(char_sub), getIntSub(char_sub),
                                      getWisSub(char_sub), getChaSub(char_sub));
        }
        Character Char_Stats = genStatsWindow(centerwin, centerwin_x_max, New_Character, char_class);
        New_Character = Character(New_Character.str_base + Char_Stats.str_base,
                                  New_Character.dex_base + Char_Stats.dex_base,
                                  New_Character.con_base + Char_Stats.con_base,
                                  New_Character.int_base + Char_Stats.int_base,
                                  New_Character.wis_base + Char_Stats.wis_base,
                                  New_Character.cha_base + Char_Stats.cha_base);
        refreshWindow(centerwin);

        // For debugging purposes
        if (char_race == "Half-Elf")
        {
            mvwprintw(centerwin, centerwin_y_max - 7, 2, "Player Name: %s", player_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 6, 2, "Character Name: %s", char_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 5, 2, "Class: %s",  char_class.c_str());
            mvwprintw(centerwin, centerwin_y_max - 4, 2, "Race: %s", char_race.c_str());
            mvwprintw(centerwin, centerwin_y_max - 3, 2, "Has Sub?: %d", has_sub);
            mvwprintw(centerwin, centerwin_y_max - 2, 2, "+1's: %d & %d", plus_stat_1, plus_stat_2);

            mvwprintw(centerwin, centerwin_y_max - 7, 30, "Str: %d", New_Character.str_base);
            mvwprintw(centerwin, centerwin_y_max - 6, 30, "Dex: %d", New_Character.dex_base);
            mvwprintw(centerwin, centerwin_y_max - 5, 30, "Con: %d", New_Character.con_base);
            mvwprintw(centerwin, centerwin_y_max - 4, 30, "Int: %d", New_Character.int_base);
            mvwprintw(centerwin, centerwin_y_max - 3, 30, "Wis: %d", New_Character.wis_base);
            mvwprintw(centerwin, centerwin_y_max - 2, 30, "Cha: %d", New_Character.cha_base);
        } else if (has_sub == true) {
            mvwprintw(centerwin, centerwin_y_max - 7, 2, "Player Name: %s", player_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 6, 2, "Character Name: %s", char_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 5, 2, "Class: %s",  char_class.c_str());
            mvwprintw(centerwin, centerwin_y_max - 4, 2, "Race: %s", char_race.c_str());
            mvwprintw(centerwin, centerwin_y_max - 3, 2, "Has Sub?: %d", has_sub);
            mvwprintw(centerwin, centerwin_y_max - 2, 2, "Sub-Race: %s", char_sub.c_str());

            mvwprintw(centerwin, centerwin_y_max - 7, 30, "Str: %d", New_Character.str_base);
            mvwprintw(centerwin, centerwin_y_max - 6, 30, "Dex: %d", New_Character.dex_base);
            mvwprintw(centerwin, centerwin_y_max - 5, 30, "Con: %d", New_Character.con_base);
            mvwprintw(centerwin, centerwin_y_max - 4, 30, "Int: %d", New_Character.int_base);
            mvwprintw(centerwin, centerwin_y_max - 3, 30, "Wis: %d", New_Character.wis_base);
            mvwprintw(centerwin, centerwin_y_max - 2, 30, "Cha: %d", New_Character.cha_base);
        } else {
            mvwprintw(centerwin, centerwin_y_max - 5, 2, "Player Name: %s", player_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 4, 2, "Character Name: %s", char_name.c_str());
            mvwprintw(centerwin, centerwin_y_max - 3, 2, "Class: %s",  char_class.c_str());
            mvwprintw(centerwin, centerwin_y_max - 2, 2, "Race: %s", char_race.c_str());

            mvwprintw(centerwin, centerwin_y_max - 7, 30, "Str: %d", New_Character.str_base);
            mvwprintw(centerwin, centerwin_y_max - 6, 30, "Dex: %d", New_Character.dex_base);
            mvwprintw(centerwin, centerwin_y_max - 5, 30, "Con: %d", New_Character.con_base);
            mvwprintw(centerwin, centerwin_y_max - 4, 30, "Int: %d", New_Character.int_base);
            mvwprintw(centerwin, centerwin_y_max - 3, 30, "Wis: %d", New_Character.wis_base);
            mvwprintw(centerwin, centerwin_y_max - 2, 30, "Cha: %d", New_Character.cha_base);
        }
           
        wrefresh(centerwin);
    }

    endwin();
}

