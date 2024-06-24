#include "../include/diceroll.h"
#include "../include/ascii_nums.h"
#include <ncurses.h>
#include <inttypes.h>
#include <string>


// print an ASCII art logo & version info
void printLogo(WINDOW *, int, int);
void printDRLogo(WINDOW *, int, int);
void printCCLogo(WINDOW *, int, int);

// program functions
void genHomeWindow(WINDOW *, int, int, WINDOW *, WINDOW *, WINDOW *);
void genDicerollWindow();
void genCCWindow();

// main menu functions
// the windows will have already been created, this is just doing things like creating the boxes and refreshing the content
void genLogoWindow(WINDOW *, int, int);
void genBottomWindow(WINDOW *);
void genMenuWindow(WINDOW *);
void genDescWindow(WINDOW *);

// diceroll functions
int getNumDice(int, int);
int getTypeDice(int, int);
int getDiceMod(int, int);
int rollDice(int, int, int);

// character creator
std::string getPlayerName(WINDOW *, int, int);
std::string getCharName(WINDOW *, int, int);
std::string getCharClass(WINDOW *, int);
std::string getCharRace(WINDOW *, int);
bool checkForSub(std::string);
std::string getCharSubRace(WINDOW *, int, std::string);

int main(int argc, char ** argv)
{
    // starts ncurses
    initscr();
    // keeps input from being printed to screen
    noecho();
    // forces Ctrl+C to work
    cbreak();
    // make cursor invisible when not needed
    curs_set(0);

    // get size of terminal
    int mainwin_y_max, mainwin_x_max;
    getmaxyx(stdscr, mainwin_y_max, mainwin_x_max);
    // draw a box around the screen
    box(stdscr, 0, 0);
    refresh();


    // **** HOMEPAGE WINDOWS ****
    int logowin_y_max, logowin_x_max;
    WINDOW *logowin = newwin(mainwin_y_max / 2, mainwin_x_max - 2, 1, 1);
    getmaxyx(logowin, logowin_y_max, logowin_x_max);
    wrefresh(logowin);

    int bottomwin_y_max, bottomwin_x_max;
    WINDOW *bottomwin = newwin((mainwin_y_max / 2) - 2, mainwin_x_max - 2, (mainwin_y_max / 2) + 1, 1);
    //box(bottomwin, 0, 0);
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
    int menuwin_y_max, menuwin_x_max;
    WINDOW *menuwin = newwin(bottomwin_y_max - 2, (bottomwin_x_max / 2) - 2, bottomwin_y_max + 4, 2);
    box(menuwin, 0, 0);
    getmaxyx(menuwin, menuwin_y_max, menuwin_x_max);
    keypad(menuwin, true);

    int descwin_y_max, descwin_x_max;
    WINDOW *descwin = newwin(bottomwin_y_max - 2, (bottomwin_x_max / 2) - 2, bottomwin_y_max + 4, menuwin_x_max + 4);
    box(descwin, 0, 0);
    getmaxyx(descwin, descwin_y_max, descwin_x_max);
    

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
            genDicerollWindow();
            genHomeWindow(logowin, logowin_y_max, logowin_x_max, bottomwin, menuwin, descwin);
        }
        if (choice == 10 && highlight == 1) {
            genCCWindow();
            genHomeWindow(logowin, logowin_y_max, logowin_x_max, bottomwin, menuwin, descwin);
        }
    }

    endwin();

    return 0;
}


// diceroller
void genDicerollWindow()
{
    // starts ncurses
    initscr();
    // keeps input from being printed to screen
    noecho();
    // forces Ctrl+C to work
    cbreak();
    // make cursor invisible when not needed
    curs_set(0);

    // get size of terminal
    int mainwin_y_max, mainwin_x_max;
    getmaxyx(stdscr, mainwin_y_max, mainwin_x_max);
    // draw a box around the screen
    box(stdscr, 0, 0);
    move(1, 1);

    // I think I just played myself. I wanted to print the logo up in the top left
    // corner, but I set up the logo function to print in the middle. So to get it
    // up there I'm setting y_max to 2 / 2 (1) and x_max to 50 / 2 - 24 (also 1).
    // That sets the max size too low so the ASCII art doesn't print, but I kinda
    // like the look of just the text over top the box in the corner.
    //
    // I might play around with this more in the future, but for now I'm just
    // going to keep doing it like this.
    printLogo(stdscr, 2, 50);
    printDRLogo(stdscr, mainwin_y_max, mainwin_x_max);
    refresh();


    int centerwin_y_max, centerwin_x_max;
    WINDOW *centerwin = newwin(mainwin_y_max / 2, mainwin_x_max / 2, mainwin_y_max / 4, mainwin_x_max / 4);
    getmaxyx(centerwin, centerwin_y_max, centerwin_x_max);
    box(centerwin, 0, 0);
    wrefresh(centerwin);
    keypad(centerwin, true);

    WINDOW *rollwin = newwin(7, 19, mainwin_y_max / 2 + 1, mainwin_x_max / 2 - 10);
    box(rollwin, 0, 0);
    wrefresh(rollwin);


    std::string choices1[4] = {"Number of Dice", "Dice Type", "Mods", "Roll!"};
    std::string descriptions1[3] = {"Enter the number of dice you'd like to roll:",
                                    "Select the type of dice you'd like to roll:",
                                    "Enter a modifier if you'd like (- for subtraction, leave blank or enter 0 for 0):"};
    int choice;
    int highlight = 0;

    // diceroll variables
    int num_dice = 0;
    int type_dice = 0;
    int mod = 0;
    int roll;
    mvwprintw(centerwin, centerwin_y_max - 2, 1, "%s", descriptions1[highlight].c_str());
    wrefresh(centerwin);

    while(1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == highlight)
            {
                wattron(centerwin, A_REVERSE);
            }
            mvwprintw(centerwin, i + 1, 1, "%s", choices1[i].c_str());
            wattroff(centerwin, A_REVERSE);
        }
        if (mod < 0)
        {
            mvwprintw(centerwin, centerwin_y_max / 2, centerwin_x_max / 2 - 3, "%dd%d%d", num_dice, type_dice, mod);
        }
        else
        {
            mvwprintw(centerwin, centerwin_y_max / 2, centerwin_x_max / 2 - 3, "%dd%d+%d", num_dice, type_dice, mod);
        }
        choice = wgetch(centerwin);
        mvwprintw(centerwin, centerwin_y_max - 2, 1, "%s", descriptions1[highlight].c_str());
        
        refresh();
        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 3;
                wclear(centerwin);
                if (highlight < 3)
                    mvwprintw(centerwin, centerwin_y_max - 2, 1, "%s", descriptions1[highlight].c_str());
                box(centerwin, 0, 0);
                box(rollwin, 0, 0);
                wrefresh(centerwin);
                wrefresh(rollwin);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 3;
                wclear(centerwin);
                if (highlight < 3)
                    mvwprintw(centerwin, centerwin_y_max - 2, 1, "%s", descriptions1[highlight].c_str());
                box(centerwin, 0, 0);
                box(rollwin, 0, 0);
                wrefresh(centerwin);
                wrefresh(rollwin);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 4)
                    highlight = 0;
                wclear(centerwin);
                if (highlight < 3)
                    mvwprintw(centerwin, centerwin_y_max - 2, 1, "%s", descriptions1[highlight].c_str());
                box(centerwin, 0, 0);
                box(rollwin, 0, 0);
                wrefresh(centerwin);
                wrefresh(rollwin);
                break;
            case 106:
                highlight++;
                if (highlight == 4)
                    highlight = 0;
                wclear(centerwin);
                if (highlight < 3)
                    mvwprintw(centerwin, centerwin_y_max - 2, 1, "%s", descriptions1[highlight].c_str());
                box(centerwin, 0, 0);
                box(rollwin, 0, 0);
                wrefresh(centerwin);
                wrefresh(rollwin);
                break;
            default:
                break;

        }
        if (choice == 113)
            break;
        if (choice == 10 && highlight == 0)
            num_dice = getNumDice(mainwin_y_max, mainwin_x_max);
        if (choice == 10 && highlight == 1)
            type_dice = getTypeDice(mainwin_y_max, mainwin_x_max);
        if (choice == 10 && highlight == 2)
            mod = getDiceMod(mainwin_y_max, mainwin_x_max);
        if (choice == 10 && highlight == 3)
        {
            wclear(centerwin);
            wclear(rollwin);
            roll = rollDice(num_dice, type_dice, mod);
            box(centerwin, 0, 0);
            if (num_dice == 1 && type_dice == 20 && roll - mod == 20) {
                wattron(rollwin, A_BOLD | A_REVERSE);
                mvwprintw(centerwin, centerwin_y_max - 2, centerwin_x_max / 2 - 3, "Nat 20!");
                printAscii(rollwin, roll);
                wattroff(rollwin, A_BOLD | A_REVERSE);
            } else {
                printAscii(rollwin, roll);
            }
            box(rollwin, 0, 0);
            wrefresh(centerwin);
            wrefresh(rollwin);
        }
        box(rollwin, 0, 0);
        wrefresh(rollwin);

    }
    //wrefresh(centerwin);


    clear();
    endwin();
}

// Logos
void printLogo(WINDOW *win, int y_max, int x_max)
{
    if (x_max >= 50)
    {
        mvwprintw(win, y_max / 2 - 6, x_max / 2 - 24, " ____                  _ _____           _");
        mvwprintw(win, y_max / 2 - 5, x_max / 2 - 24, "|  _ \\ _   _ _ __   __| |_   _|__   ___ | |___");
        mvwprintw(win, y_max / 2 - 4, x_max / 2 - 24, "| | | | | | | '_ \\ / _` | | |/ _ \\ / _ \\| / __|");
        mvwprintw(win, y_max / 2 - 3, x_max / 2 - 24, "| |_| | |_| | | | | (_| | | | (_) | (_) | \\__ \\");
        mvwprintw(win, y_max / 2 - 2, x_max / 2 - 24, "|____/ \\__,_|_| |_|\\__,_| |_|\\___/ \\___/|_|___/");
    }
    mvwprintw(win, y_max / 2 - 1, x_max / 2 - 24, "DundTools v0.1");
}
void printDRLogo(WINDOW *win, int y_max, int x_max)
{
    if (x_max >= 46 && y_max >= 28)
    {
        mvwprintw(win, y_max / 4 - 6, x_max / 2 - 21, " ____  _          ____       _ _           ");
        mvwprintw(win, y_max / 4 - 5, x_max / 2 - 21, "|  _ \\(_) ___ ___|  _ \\ ___ | | | ___ _ __ ");
        mvwprintw(win, y_max / 4 - 4, x_max / 2 - 21, "| | | | |/ __/ _ \\ |_) / _ \\| | |/ _ \\ '__|");
        mvwprintw(win, y_max / 4 - 3, x_max / 2 - 21, "| |_| | | (_|  __/  _ < (_) | | |  __/ |   ");
        mvwprintw(win, y_max / 4 - 2, x_max / 2 - 21, "|____/|_|\\___\\___|_| \\_\\___/|_|_|\\___|_|   ");
    }
    mvwprintw(win, 1, 1, "DiceRoller");
}
void printCCLogo(WINDOW *win, int y_max, int x_max)
{
    if (x_max >= 85 && y_max >= 28)
    {
        mvwprintw(win, y_max / 4 - 6, x_max / 2 - 41, "  ____ _                          _             ____                _             ");
        mvwprintw(win, y_max / 4 - 5, x_max / 2 - 41, " / ___| |__   __ _ _ __ __ _  ___| |_ ___ _ __ / ___|_ __ ___  __ _| |_ ___  _ __ ");
        mvwprintw(win, y_max / 4 - 4, x_max / 2 - 41, "| |   | '_ \\ / _` | '__/ _` |/ __| __/ _ \\ '__| |   | '__/ _ \\/ _` | __/ _ \\| '__|");
        mvwprintw(win, y_max / 4 - 3, x_max / 2 - 41, "| |___| | | | (_| | | | (_| | (__| ||  __/ |  | |___| | |  __/ (_| | || (_) | |   ");
        mvwprintw(win, y_max / 4 - 2, x_max / 2 - 41, " \\____|_| |_|\\__,_|_|  \\__,_|\\___|\\__\\___|_|   \\____|_|  \\___|\\__,_|\\__\\___/|_|   ");
    }
    mvwprintw(win, 1, 1, "CharacterCreator");
}

void genHomeWindow(WINDOW *logo, int y_max, int x_max, WINDOW *bottom, WINDOW *menu, WINDOW *desc)
{
    clear();
    box(stdscr, 0, 0);
    refresh();
    genLogoWindow(logo, y_max, x_max);
    genBottomWindow(bottom);
    genMenuWindow(menu);
    genDescWindow(desc);
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
void genBottomWindow(WINDOW *win)
{
    wclear(win);
    wrefresh(win);
}
void genMenuWindow(WINDOW *win)
{
    wclear(win);
    box(win, 0, 0);
    wrefresh(win);
}
void genDescWindow(WINDOW *win)
{
    box(win, 0, 0);
    wrefresh(win);
}


// diceroll functions
int getNumDice(int y_max, int x_max)
{
    char input[10];
    std::string instruct = "Enter the number of dice you'd like to roll and press the Enter key";

    WINDOW *centerwin = newwin(y_max / 2, x_max / 2, y_max / 4, x_max / 4);
    wclear(centerwin);
    mvwprintw(centerwin, 3, 1, "%s", instruct.c_str());
    box(centerwin, 0, 0);

    WINDOW *textbox = newwin(3, 10, y_max / 2, x_max / 2 - 6);
    box(textbox, 0, 0);

    wrefresh(centerwin);
    wrefresh(textbox);

    keypad(textbox, true);

    // turn echoing and the cursor ON
    echo();
    curs_set(1);
    wmove(textbox, 1, 1);

    input[0] = wgetch(textbox);
    int i = 1;
    while (input[i - 1] != '\n')
    {
        input[i] = wgetch(textbox);
        if (input[i - 1] == KEY_BACKSPACE)
        {
            wmove(textbox, 1, i);
            wprintw(textbox, "  ");
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
    int num_dice = strtoimax(input, &endp, 10);

    // turn echoing and the cursor back OFF
    noecho();
    curs_set(0);
    wclear(centerwin);
    box(centerwin, 0, 0);
    wrefresh(centerwin);

    endwin();
    return num_dice;    
}

int getTypeDice(int y_max, int x_max)
{
    char input[10];
    std::string instruct = "Enter the number of sides on the dice you'd like to roll (ex. 20 for d20, 6 for d6, etc)";

    WINDOW *centerwin = newwin(y_max / 2, x_max / 2, y_max / 4, x_max / 4);
    wclear(centerwin);
    mvwprintw(centerwin, 3, 1, "%s", instruct.c_str());
    box(centerwin, 0, 0);

    WINDOW *textbox = newwin(3, 10, y_max / 2, x_max / 2 - 6);
    box(textbox, 0, 0);

    wrefresh(centerwin);
    wrefresh(textbox);

    // turn echoing and the cursor ON
    echo();
    curs_set(1);
    wmove(textbox, 1, 1);

    input[0] = wgetch(textbox);
    int i = 1;
    while (input[i - 1] != '\n')
    {
        input[i] = wgetch(textbox);
        if (input[i - 1] == KEY_BACKSPACE)
        {
            wmove(textbox, 1, i);
            wprintw(textbox, "  ");
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
    int type_dice = strtoimax(input, &endp, 10);

    // turn echoing and the cursor back OFF
    noecho();
    curs_set(0);
    wclear(centerwin);
    box(centerwin, 0, 0);
    wrefresh(centerwin);

    endwin();
    return type_dice;
}

int getDiceMod(int y_max, int x_max)
{
    char input[10];
    std::string instruct = "Enter any mods to your roll (-n to subtract)";

    WINDOW *centerwin = newwin(y_max / 2, x_max / 2, y_max / 4, x_max / 4);
    wclear(centerwin);
    mvwprintw(centerwin, 3, instruct.length() / 2 - 6, "%s", instruct.c_str());
    box(centerwin, 0, 0);

    WINDOW *textbox = newwin(3, 10, y_max / 2, x_max / 2 - 6);
    box(textbox, 0, 0);

    wrefresh(centerwin);
    wrefresh(textbox);

    // turn echoing and the cursor ON
    echo();
    curs_set(1);
    wmove(textbox, 1, 1);

    input[0] = wgetch(textbox);
    int i = 1;
    while (input[i - 1] != '\n')
    {
        input[i] = wgetch(textbox);
        if (input[i - 1] == KEY_BACKSPACE)
        {
            wmove(textbox, 1, i);
            wprintw(textbox, "  ");
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
    int mod = strtoimax(input, &endp, 10);

    // turn echoing and the cursor back OFF
    noecho();
    curs_set(0);
    wclear(centerwin);
    box(centerwin, 0, 0);
    wrefresh(centerwin);

    endwin();
    return mod;
}

int rollDice(int dice, int sides, int mod)
{
    int roll = diceRoll(dice, sides) + mod;

    if (roll < 0) {
        roll = 0;
    }

    return roll;
}


// character creator stuff
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


        // NEW SECTIONS ABOVE THIS LINE
        default:
            break;
    }
    
    wclear(win);
    endwin();

    return chosen_sub;
}
