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
    // create logo window
    int logowin_y_max, logowin_x_max;
    WINDOW *logowin = newwin(mainwin_y_max / 2, mainwin_x_max - 2, 1, 1);
    getmaxyx(logowin, logowin_y_max, logowin_x_max);
    wrefresh(logowin);

    // create window for lower half of screen
    int bottomwin_y_max, bottomwin_x_max;
    WINDOW *bottomwin = newwin((mainwin_y_max / 2) - 2, mainwin_x_max - 2, (mainwin_y_max / 2) + 1, 1);
    //box(bottomwin, 0, 0);
    getmaxyx(bottomwin, bottomwin_y_max, bottomwin_x_max);
    wrefresh(bottomwin);

    // print logo in middle of logo window
    // if the window is large enough, print out an ASCII art logo
    // print out the program title and version number regardless of window size
    printLogo(logowin, logowin_y_max, logowin_x_max);
    // app description, default descwin text
    std::string initdesc[4] = {"A compilation of D&D 5e tools.", "Works best with a full screen terminal", "Arrow keys or J/K to navigate, Enter to select", "Ctrl-C to exit at any time"};
    for (int i = 0; i < 4; i++)
    {
        mvwprintw(logowin, logowin_y_max - 5 + i, 1, "%s", initdesc[i].c_str());
    }
    wrefresh(logowin);


    // **** MAIN MENU ****
    // window to hold the menu section
    int menuwin_y_max, menuwin_x_max;
    WINDOW *menuwin = newwin(bottomwin_y_max - 2, (bottomwin_x_max / 2) - 2, bottomwin_y_max + 4, 2);
    box(menuwin, 0, 0);
    getmaxyx(menuwin, menuwin_y_max, menuwin_x_max);
    keypad(menuwin, true);

    // window to hold descriptions of menu items
    int descwin_y_max, descwin_x_max;
    WINDOW *descwin = newwin(bottomwin_y_max - 2, (bottomwin_x_max / 2) - 2, bottomwin_y_max + 4, menuwin_x_max + 4);
    box(descwin, 0, 0);
    getmaxyx(descwin, descwin_y_max, descwin_x_max);
    wrefresh(descwin);
    
    wrefresh(descwin);

    // create menu items
    std::string choices[2] = {"DiceRoll", "Character Creator"};
    std::string descriptions[2] = {"A simple dice roll simulator", "A step-by-step first level character creator"};
    int choice;
    int highlight = 0;

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
                    highlight = 0;
                wclear(descwin);
                mvwprintw(descwin, 1, 1, "%s", descriptions[highlight].c_str());
                box(descwin, 0, 0);
                wrefresh(descwin);
                break;
            // press k to move cursor up
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                wclear(descwin);
                mvwprintw(descwin, 1, 1, "%s", descriptions[highlight].c_str());
                box(descwin, 0, 0);
                wrefresh(descwin);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 2)
                    highlight = 1;
                wclear(descwin);
                mvwprintw(descwin, 1, 1, "%s", descriptions[highlight].c_str());
                box(descwin, 0, 0);
                wrefresh(descwin);
                break;
            // press j to move cursor down
            case 106:
                highlight++;
                if (highlight == 2)
                    highlight = 1;
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
    wrefresh(menuwin);
    wrefresh(descwin);


    // **** END SECTION ****
    // wait for input before ending ncurses, then end the program
    //getch();
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

    WINDOW *rollwin = newwin(7, 19, mainwin_y_max / 2 + 1, mainwin_x_max / 2 - 14);
    box(rollwin, 0, 0);
    wrefresh(rollwin);


    std::string choices1[4] = {"Number of Dice", "Dice Type", "Mods", "Roll!"};
    std::string descriptions1[3] = {"Enter the number of dice you'd like to roll:", "Select the type of dice you'd like to roll:", "Enter a modifier if you'd like (- for subtraction, leave blank or enter 0 for 0):"};
    //int desc_length[3] = {descriptions1[0].length(), descriptions1[1].length(), descriptions1[2].length()};
    int choice;
    int highlight = 0;

    // diceroll variables
    int num_dice = 0;
    int type_dice = 0;
    int mod = 0;
    int roll;

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
            mvwprintw(centerwin, centerwin_y_max / 2, centerwin_x_max / 2 - 6, "%dd%d%d", num_dice, type_dice, mod);
        }
        else
        {
            mvwprintw(centerwin, centerwin_y_max / 2, centerwin_x_max / 2 - 6, "%dd%d+%d", num_dice, type_dice, mod);
        }
        choice = wgetch(centerwin);
        
        refresh();
        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                wclear(centerwin);
                mvwprintw(centerwin, centerwin_y_max - 1, 1, "%s", descriptions1[highlight].c_str());
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            case 107:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                wclear(centerwin);
                mvwprintw(centerwin, centerwin_y_max - 1, 1, "%s", descriptions1[highlight].c_str());
                //mvwprintw(centerwin, 1, centerwin_x_max - desc_length[highlight], "%s", descriptions1[highlight].c_str());
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 4)
                    highlight = 3;
                wclear(centerwin);
                mvwprintw(centerwin, centerwin_y_max - 2, 1, "%s", descriptions1[highlight].c_str());
                //mvwprintw(centerwin, 1, centerwin_x_max - desc_length[highlight], "%s", descriptions1[highlight].c_str());
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            case 106:
                highlight++;
                if (highlight == 4)
                    highlight = 3;
                wclear(centerwin);
                mvwprintw(centerwin, centerwin_y_max - 1, 1, "%s", descriptions1[highlight].c_str());
                //mvwprintw(centerwin, 1, centerwin_x_max - desc_length[highlight], "%s", descriptions1[highlight].c_str());
                box(centerwin, 0, 0);
                wrefresh(centerwin);
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
            //mvwprintw(centerwin, centerwin_y_max / 2 + 5, centerwin_x_max / 2 - 6, "%d", roll);
            box(centerwin, 0, 0);
            wrefresh(centerwin);
            printAscii(rollwin, roll);
            box(rollwin, 0, 0);
            wrefresh(rollwin);
        }

    }
    wrefresh(centerwin);


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
    mvwprintw(centerwin, 3, instruct.length() / 2 - 6, "%s", instruct.c_str());
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

    std::string choices[3] = {"Player Name", "Character Name", "Class"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for (int i = 0; i < 3; i++)
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
                if (highlight == 3)
                    highlight = 2;
                wclear(centerwin);
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            case 106:
                highlight++;
                if (highlight == 3)
                    highlight = 2;
                wclear(centerwin);
                box(centerwin, 0, 0);
                wrefresh(centerwin);
                break;
            default:
                break;
        }
        if (choice == 113)
            break;
    }
    clear();
    endwin();
}
