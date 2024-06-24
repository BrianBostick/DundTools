#include "../include/diceroll.h"
#include "../include/ascii_nums.h"
#include "../include/character_creator.h"
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
