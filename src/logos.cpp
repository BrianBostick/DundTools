#include "../include/logos.h"
#include <ncurses.h>

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
