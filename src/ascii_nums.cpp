#include "../include/ascii_nums.h"
#include <ncurses.h>


void over100(WINDOW *win)
{
    mvwprintw(win, 3, 1, ">100");
}

void zeroRoll(WINDOW *win)
{
    mvwprintw(win, 3, 1, "0");
}

void nat20(WINDOW *win)
{
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    wattron(win, COLOR_PAIR(1) | A_BOLD);

    mvwprintw(win, 1, 1, " ____    ___  ");
    mvwprintw(win, 2, 1, "|___ \\  / _ \\ ");
    mvwprintw(win, 3, 1, "  __) || | | |");
    mvwprintw(win, 4, 1, " / __/ | |_| |");
    mvwprintw(win, 5, 1, "|_____| \\___/ ");

    wattroff(win, COLOR_PAIR(1) | A_BOLD);
}
// P A I N

void ascii1(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _ ");
    mvwprintw(win, 2, 1, "/ |");
    mvwprintw(win, 3, 1, "| |");
    mvwprintw(win, 4, 1, "| |");
    mvwprintw(win, 5, 1, "|_|");
}
void ascii2(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____  ");
    mvwprintw(win, 2, 1, "|___ \\ ");
    mvwprintw(win, 3, 1, "  __) |");
    mvwprintw(win, 4, 1, " / __/ ");
    mvwprintw(win, 5, 1, "|_____|");
}
void ascii3(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____ ");
    mvwprintw(win, 2, 1, "|___ / ");
    mvwprintw(win, 3, 1, "  |_ \\ ");
    mvwprintw(win, 4, 1, " ___) |");
    mvwprintw(win, 5, 1, "|____/ ");
}
void ascii4(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _   ");
    mvwprintw(win, 2, 1, "| || |  ");
    mvwprintw(win, 3, 1, "| || |_ ");
    mvwprintw(win, 4, 1, "|__   _|");
    mvwprintw(win, 5, 1, "   |_|  ");
}
void ascii5(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____  ");
    mvwprintw(win, 2, 1, "| ___| ");
    mvwprintw(win, 3, 1, "|___ \\ ");
    mvwprintw(win, 4, 1, " ___) |");
    mvwprintw(win, 5, 1, "|____/ ");
}
void ascii6(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __   ");
    mvwprintw(win, 2, 1, " / /_  ");
    mvwprintw(win, 3, 1, "| '_ \\ ");
    mvwprintw(win, 4, 1, "| (_) |");
    mvwprintw(win, 5, 1, " \\___/ ");
}
void ascii7(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____ ");
    mvwprintw(win, 2, 1, "|___  |");
    mvwprintw(win, 3, 1, "   / / ");
    mvwprintw(win, 4, 1, "  / /  ");
    mvwprintw(win, 5, 1, " /_/   ");
}
void ascii8(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  ");
    mvwprintw(win, 2, 1, " ( _ ) ");
    mvwprintw(win, 3, 1, " / _ \\ ");
    mvwprintw(win, 4, 1, "| (_) |");
    mvwprintw(win, 5, 1, " \\___/ ");
}
void ascii9(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  ");
    mvwprintw(win, 2, 1, " / _ \\ ");
    mvwprintw(win, 3, 1, "| (_) |");
    mvwprintw(win, 4, 1, " \\__, |");
    mvwprintw(win, 5, 1, "   /_/ ");
}
void ascii10(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _   ___  ");
    mvwprintw(win, 2, 1, "/ | / _ \\ ");
    mvwprintw(win, 3, 1, "| || | | |");
    mvwprintw(win, 4, 1, "| || |_| |");
    mvwprintw(win, 5, 1, "|_| \\___/ ");
}
void ascii11(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _ ");
    mvwprintw(win, 2, 1, "/ |/ |");
    mvwprintw(win, 3, 1, "| || |");
    mvwprintw(win, 4, 1, "| || |");
    mvwprintw(win, 5, 1, "|_||_|");
}
void ascii12(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  ____  ");
    mvwprintw(win, 2, 1, "/ ||___ \\ ");
    mvwprintw(win, 3, 1, "| |  __) |");
    mvwprintw(win, 4, 1, "| | / __/ ");
    mvwprintw(win, 5, 1, "|_||_____|");
}
void ascii13(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _____ ");
    mvwprintw(win, 2, 1, "/ ||___ / ");
    mvwprintw(win, 3, 1, "| |  |_ \\ ");
    mvwprintw(win, 4, 1, "| | ___) |");
    mvwprintw(win, 5, 1, "|_||____/ ");
}
void ascii14(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _  _   ");
    mvwprintw(win, 2, 1, "/ || || |  ");
    mvwprintw(win, 3, 1, "| || || |_ ");
    mvwprintw(win, 4, 1, "| ||__   _|");
    mvwprintw(win, 5, 1, "|_|   |_|  ");
}
void ascii15(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  ____  ");
    mvwprintw(win, 2, 1, "/ || ___| ");
    mvwprintw(win, 3, 1, "| ||___ \\ ");
    mvwprintw(win, 4, 1, "| | ___) |");
    mvwprintw(win, 5, 1, "|_||____/ ");
}
void ascii16(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _   __   ");
    mvwprintw(win, 2, 1, "/ | / /_  ");
    mvwprintw(win, 3, 1, "| || '_ \\ ");
    mvwprintw(win, 4, 1, "| || (_) |");
    mvwprintw(win, 5, 1, "|_| \\___/ ");
}
void ascii17(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _____ ");
    mvwprintw(win, 2, 1, "/ ||___  |");
    mvwprintw(win, 3, 1, "| |   / / ");
    mvwprintw(win, 4, 1, "| |  / /  ");
    mvwprintw(win, 5, 1, "|_| /_/   ");
}
void ascii18(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _   ___  ");
    mvwprintw(win, 2, 1, "/ | ( _ ) ");
    mvwprintw(win, 3, 1, "| | / _ \\ ");
    mvwprintw(win, 4, 1, "| || (_) |");
    mvwprintw(win, 5, 1, "|_| \\___/ ");
}
void ascii19(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _   ___  ");
    mvwprintw(win, 2, 1, "/ | / _ \\ ");
    mvwprintw(win, 3, 1, "| || (_) |");
    mvwprintw(win, 4, 1, "| | \\__, |");
    mvwprintw(win, 5, 1, "|_|   /_/ ");
}
void ascii20(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____    ___  ");
    mvwprintw(win, 2, 1, "|___ \\  / _ \\ ");
    mvwprintw(win, 3, 1, "  __) || | | |");
    mvwprintw(win, 4, 1, " / __/ | |_| |");
    mvwprintw(win, 5, 1, "|_____| \\___/ ");
}
void ascii21(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   _ ");
    mvwprintw(win, 2, 1, "|___ \\ / |");
    mvwprintw(win, 3, 1, "  __) || |");
    mvwprintw(win, 4, 1, " / __/ | |");
    mvwprintw(win, 5, 1, "|_____||_|");
}
void ascii22(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   ____  ");
    mvwprintw(win, 2, 1, "|___ \\ |___ \\ ");
    mvwprintw(win, 3, 1, "  __) |  __) |");
    mvwprintw(win, 4, 1, " / __/  / __/ ");
    mvwprintw(win, 5, 1, "|_____||_____|");
}
void ascii23(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   _____ ");
    mvwprintw(win, 2, 1, "|___ \\ |___ / ");
    mvwprintw(win, 3, 1, "  __) |  |_ \\ ");
    mvwprintw(win, 4, 1, " / __/  ___) |");
    mvwprintw(win, 5, 1, "|_____||____/ ");
}
void ascii24(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   _  _   ");
    mvwprintw(win, 2, 1, "|___ \\ | || |  ");
    mvwprintw(win, 3, 1, "  __) || || |_ ");
    mvwprintw(win, 4, 1, " / __/ |__   _|");
    mvwprintw(win, 5, 1, "|_____|   |_|  ");
}
void ascii25(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   ____  ");
    mvwprintw(win, 2, 1, "|___ \\ | ___| ");
    mvwprintw(win, 3, 1, "  __) ||___ \\ ");
    mvwprintw(win, 4, 1, " / __/  ___) |");
    mvwprintw(win, 5, 1, "|_____||____/ ");
}
void ascii26(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____    __   ");
    mvwprintw(win, 2, 1, "|___ \\  / /_  ");
    mvwprintw(win, 3, 1, "  __) || '_ \\ ");
    mvwprintw(win, 4, 1, " / __/ | (_) |");
    mvwprintw(win, 5, 1, "|_____| \\___/ ");
}
void ascii27(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____  _____ ");
    mvwprintw(win, 2, 1, "|___ \\|___  |");
    mvwprintw(win, 3, 1, "  __) |  / / ");
    mvwprintw(win, 4, 1, " / __/  / /  ");
    mvwprintw(win, 5, 1, "|_____|/_/   ");
}
void ascii28(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   ___  ");
    mvwprintw(win, 2, 1, "|___ \\ ( _ ) ");
    mvwprintw(win, 3, 1, "  __) |/ _ \\ ");
    mvwprintw(win, 4, 1, " / __/| (_) |");
    mvwprintw(win, 5, 1, "|_____|\\___/ ");
}
void ascii29(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____    ___  ");
    mvwprintw(win, 2, 1, "|___ \\  / _ \\ ");
    mvwprintw(win, 3, 1, "  __) || (_) |");
    mvwprintw(win, 4, 1, " / __/  \\__, |");
    mvwprintw(win, 5, 1, "|_____|   /_/ ");
}
void ascii30(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____   ___  ");
    mvwprintw(win, 2, 1, "|___ /  / _ \\ ");
    mvwprintw(win, 3, 1, "  |_ \\ | | | |");
    mvwprintw(win, 4, 1, " ___) || |_| |");
    mvwprintw(win, 5, 1, "|____/  \\___/ ");
}
void ascii31(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  _ ");
    mvwprintw(win, 2, 1, "|___ / / |");
    mvwprintw(win, 3, 1, "  |_ \\ | |");
    mvwprintw(win, 4, 1, " ___) || |");
    mvwprintw(win, 5, 1, "|____/ |_|");
}
void ascii32(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____ ____  ");
    mvwprintw(win, 2, 1, "|___ /|___ \\ ");
    mvwprintw(win, 3, 1, "  |_ \\  __) |");
    mvwprintw(win, 4, 1, " ___) |/ __/ ");
    mvwprintw(win, 5, 1, "|____/|_____|");
}
void ascii33(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____ _____ ");
    mvwprintw(win, 2, 1, "|___ /|___ / ");
    mvwprintw(win, 3, 1, "  |_ \\  |_ \\ ");
    mvwprintw(win, 4, 1, " ___) |___) |");
    mvwprintw(win, 5, 1, "|____/|____/ ");
}
void ascii34(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  _  _   ");
    mvwprintw(win, 2, 1, "|___ / | || |  ");
    mvwprintw(win, 3, 1, "  |_ \\ | || |_ ");
    mvwprintw(win, 4, 1, " ___) ||__   _|");
    mvwprintw(win, 5, 1, "|____/    |_|  ");
}
void ascii35(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____ ____  ");
    mvwprintw(win, 2, 1, "|___ /| ___| ");
    mvwprintw(win, 3, 1, "  |_ \\|___ \\ ");
    mvwprintw(win, 4, 1, " ___) |___) |");
    mvwprintw(win, 5, 1, "|____/|____/ ");
}
void ascii36(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____   __   ");
    mvwprintw(win, 2, 1, "|___ /  / /_  ");
    mvwprintw(win, 3, 1, "  |_ \\ | '_ \\ ");
    mvwprintw(win, 4, 1, " ___) || (_) |");
    mvwprintw(win, 5, 1, "|____/  \\___/ ");
}
void ascii37(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____ _____ ");
    mvwprintw(win, 2, 1, "|___ /|___  |");
    mvwprintw(win, 3, 1, "  |_ \\   / / ");
    mvwprintw(win, 4, 1, " ___) | / /  ");
    mvwprintw(win, 5, 1, "|____/ /_/   ");
}
void ascii38(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____   ___  ");
    mvwprintw(win, 2, 1, "|___ /  ( _ ) ");
    mvwprintw(win, 3, 1, "  |_ \\  / _ \\ ");
    mvwprintw(win, 4, 1, " ___) || (_) |");
    mvwprintw(win, 5, 1, "|____/  \\___/ ");
}
void ascii39(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  ___  ");
    mvwprintw(win, 2, 1, "|___ / / _ \\ ");
    mvwprintw(win, 3, 1, "  |_ \\| (_) |");
    mvwprintw(win, 4, 1, " ___) |\\__, |");
    mvwprintw(win, 5, 1, "|____/   /_/ ");
}
void ascii40(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _     ___  ");
    mvwprintw(win, 2, 1, "| || |   / _ \\ ");
    mvwprintw(win, 3, 1, "| || |_ | | | |");
    mvwprintw(win, 4, 1, "|__   _|| |_| |");
    mvwprintw(win, 5, 1, "   |_|   \\___/ ");
}
void ascii41(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _    _ ");
    mvwprintw(win, 2, 1, "| || |  / |");
    mvwprintw(win, 3, 1, "| || |_ | |");
    mvwprintw(win, 4, 1, "|__   _|| |");
    mvwprintw(win, 5, 1, "   |_|  |_|");
}
void ascii42(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _   ____  ");
    mvwprintw(win, 2, 1, "| || | |___ \\ ");
    mvwprintw(win, 3, 1, "| || |_  __) |");
    mvwprintw(win, 4, 1, "|__   _|/ __/ ");
    mvwprintw(win, 5, 1, "   |_| |_____|");
}
void ascii43(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _   _____ ");
    mvwprintw(win, 2, 1, "| || | |___ / ");
    mvwprintw(win, 3, 1, "| || |_  |_ \\ ");
    mvwprintw(win, 4, 1, "|__   _|___) |");
    mvwprintw(win, 5, 1, "   |_| |____/ ");
}
void ascii44(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _    _  _   ");
    mvwprintw(win, 2, 1, "| || |  | || |  ");
    mvwprintw(win, 3, 1, "| || |_ | || |_ ");
    mvwprintw(win, 4, 1, "|__   _||__   _|");
    mvwprintw(win, 5, 1, "   |_|     |_|  ");
}
void ascii45(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _   ____  ");
    mvwprintw(win, 2, 1, "| || | | ___| ");
    mvwprintw(win, 3, 1, "| || |_|___ \\ ");
    mvwprintw(win, 4, 1, "|__   _|___) |");
    mvwprintw(win, 5, 1, "   |_| |____/ ");
}
void ascii46(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _     __   ");
    mvwprintw(win, 2, 1, "| || |   / /_  ");
    mvwprintw(win, 3, 1, "| || |_ | '_ \\ ");
    mvwprintw(win, 4, 1, "|__   _|| (_) |");
    mvwprintw(win, 5, 1, "   |_|   \\___/ ");
}
void ascii47(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _  _____ ");
    mvwprintw(win, 2, 1, "| || ||___  |");
    mvwprintw(win, 3, 1, "| || |_  / / ");
    mvwprintw(win, 4, 1, "|__   _|/ /  ");
    mvwprintw(win, 5, 1, "   |_| /_/   ");
}
void ascii48(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _     ___  ");
    mvwprintw(win, 2, 1, "| || |   ( _ ) ");
    mvwprintw(win, 3, 1, "| || |_  / _ \\ ");
    mvwprintw(win, 4, 1, "|__   _|| (_) |");
    mvwprintw(win, 5, 1, "   |_|   \\___/ ");
}
void ascii49(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _  _    ___  ");
    mvwprintw(win, 2, 1, "| || |  / _ \\ ");
    mvwprintw(win, 3, 1, "| || |_| (_) |");
    mvwprintw(win, 4, 1, "|__   _|\\__, |");
    mvwprintw(win, 5, 1, "   |_|    /_/ ");
}
void ascii50(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____    ___  ");
    mvwprintw(win, 2, 1, "| ___|  / _ \\ ");
    mvwprintw(win, 3, 1, "|___ \\ | | | |");
    mvwprintw(win, 4, 1, " ___) || |_| |");
    mvwprintw(win, 5, 1, "|____/  \\___/ ");
}
void ascii51(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   _ ");
    mvwprintw(win, 2, 1, "| ___| / |");
    mvwprintw(win, 3, 1, "|___ \\ | |");
    mvwprintw(win, 4, 1, " ___) || |");
    mvwprintw(win, 5, 1, "|____/ |_|");
}
void ascii52(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____  ____  ");
    mvwprintw(win, 2, 1, "| ___||___ \\ ");
    mvwprintw(win, 3, 1, "|___ \\  __) |");
    mvwprintw(win, 4, 1, " ___) |/ __/ ");
    mvwprintw(win, 5, 1, "|____/|_____|");
}
void ascii53(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____  _____ ");
    mvwprintw(win, 2, 1, "| ___||___ / ");
    mvwprintw(win, 3, 1, "|___ \\  |_ \\ ");
    mvwprintw(win, 4, 1, " ___) |___) |");
    mvwprintw(win, 5, 1, "|____/|____/ ");
}
void ascii54(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   _  _   ");
    mvwprintw(win, 2, 1, "| ___| | || |  ");
    mvwprintw(win, 3, 1, "|___ \\ | || |_ ");
    mvwprintw(win, 4, 1, " ___) ||__   _|");
    mvwprintw(win, 5, 1, "|____/    |_|  ");
}
void ascii55(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____  ____  ");
    mvwprintw(win, 2, 1, "| ___|| ___| ");
    mvwprintw(win, 3, 1, "|___ \\|___ \\ ");
    mvwprintw(win, 4, 1, " ___) |___) |");
    mvwprintw(win, 5, 1, "|____/|____/ ");
}
void ascii56(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____    __   ");
    mvwprintw(win, 2, 1, "| ___|  / /_  ");
    mvwprintw(win, 3, 1, "|___ \\ | '_ \\ ");
    mvwprintw(win, 4, 1, " ___) || (_) |");
    mvwprintw(win, 5, 1, "|____/  \\___/ ");
}
void ascii57(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____  _____ ");
    mvwprintw(win, 2, 1, "| ___||___  |");
    mvwprintw(win, 3, 1, "|___ \\   / / ");
    mvwprintw(win, 4, 1, " ___) | / /  ");
    mvwprintw(win, 5, 1, "|____/ /_/   ");
}
void ascii58(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____    ___  ");
    mvwprintw(win, 2, 1, "| ___|  ( _ ) ");
    mvwprintw(win, 3, 1, "|___ \\  / _ \\ ");
    mvwprintw(win, 4, 1, " ___) || (_) |");
    mvwprintw(win, 5, 1, "|____/  \\___/ ");
}
void ascii59(WINDOW *win)
{
    mvwprintw(win, 1, 1, " ____   ___  ");
    mvwprintw(win, 2, 1, "| ___| / _ \\ ");
    mvwprintw(win, 3, 1, "|___ \\| (_) |");
    mvwprintw(win, 4, 1, " ___) |\\__, |");
    mvwprintw(win, 5, 1, "|____/   /_/ ");
}
void ascii60(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __     ___  ");
    mvwprintw(win, 2, 1, " / /_   / _ \\ ");
    mvwprintw(win, 3, 1, "| '_ \\ | | | |");
    mvwprintw(win, 4, 1, "| (_) || |_| |");
    mvwprintw(win, 5, 1, " \\___/  \\___/ ");
}
void ascii61(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __    _ ");
    mvwprintw(win, 2, 1, " / /_  / |");
    mvwprintw(win, 3, 1, "| '_ \\ | |");
    mvwprintw(win, 4, 1, "| (_) || |");
    mvwprintw(win, 5, 1, " \\___/ |_|");
}
void ascii62(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __   ____  ");
    mvwprintw(win, 2, 1, " / /_ |___ \\ ");
    mvwprintw(win, 3, 1, "| '_ \\  __) |");
    mvwprintw(win, 4, 1, "| (_) |/ __/ ");
    mvwprintw(win, 5, 1, " \\___/|_____|");
}
void ascii63(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __   _____ ");
    mvwprintw(win, 2, 1, " / /_ |___ / ");
    mvwprintw(win, 3, 1, "| '_ \\  |_ \\ ");
    mvwprintw(win, 4, 1, "| (_) |___) |");
    mvwprintw(win, 5, 1, " \\___/|____/ ");
}
void ascii64(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __    _  _   ");
    mvwprintw(win, 2, 1, " / /_  | || |  ");
    mvwprintw(win, 3, 1, "| '_ \\ | || |_ ");
    mvwprintw(win, 4, 1, "| (_) ||__   _|");
    mvwprintw(win, 5, 1, " \\___/    |_|  ");
}
void ascii65(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __   ____  ");
    mvwprintw(win, 2, 1, " / /_ | ___| ");
    mvwprintw(win, 3, 1, "| '_ \\|___ \\ ");
    mvwprintw(win, 4, 1, "| (_) |___) |");
    mvwprintw(win, 5, 1, " \\___/|____/ ");
}
void ascii66(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __     __   ");
    mvwprintw(win, 2, 1, " / /_   / /_  ");
    mvwprintw(win, 3, 1, "| '_ \\ | '_ \\ ");
    mvwprintw(win, 4, 1, "| (_) || (_) |");
    mvwprintw(win, 5, 1, " \\___/  \\___/ ");
}
void ascii67(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __  _____ ");
    mvwprintw(win, 2, 1, " / /_|___  |");
    mvwprintw(win, 3, 1, "| '_ \\  / / ");
    mvwprintw(win, 4, 1, "| (_) |/ /  ");
    mvwprintw(win, 5, 1, " \\___//_/   ");
}
void ascii68(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  __     ___  ");
    mvwprintw(win, 2, 1, " / /_   ( _ ) ");
    mvwprintw(win, 3, 1, "| '_ \\  / _ \\ ");
    mvwprintw(win, 4, 1, "| (_) || (_) |");
    mvwprintw(win, 5, 1, " \\___/  \\___/ ");
}
void ascii69(WINDOW *win)
{
// nice
    mvwprintw(win, 1, 1, "  __    ___  ");
    mvwprintw(win, 2, 1, " / /_  / _ \\ ");
    mvwprintw(win, 3, 1, "| '_ \\| (_) |");
    mvwprintw(win, 4, 1, "| (_) |\\__, |");
    mvwprintw(win, 5, 1, " \\___/   /_/ ");
}
void ascii70(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  ___  ");
    mvwprintw(win, 2, 1, "|___  |/ _ \\ ");
    mvwprintw(win, 3, 1, "   / /| | | |");
    mvwprintw(win, 4, 1, "  / / | |_| |");
    mvwprintw(win, 5, 1, " /_/   \\___/ ");
}
void ascii71(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  _ ");
    mvwprintw(win, 2, 1, "|___  |/ |");
    mvwprintw(win, 3, 1, "   / / | |");
    mvwprintw(win, 4, 1, "  / /  | |");
    mvwprintw(win, 5, 1, " /_/   |_|");
}
void ascii72(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  ____  ");
    mvwprintw(win, 2, 1, "|___  ||___ \\ ");
    mvwprintw(win, 3, 1, "   / /   __) |");
    mvwprintw(win, 4, 1, "  / /   / __/ ");
    mvwprintw(win, 5, 1, " /_/   |_____|");
}
void ascii73(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  _____ ");
    mvwprintw(win, 2, 1, "|___  ||___ / ");
    mvwprintw(win, 3, 1, "   / /   |_ \\ ");
    mvwprintw(win, 4, 1, "  / /   ___) |");
    mvwprintw(win, 5, 1, " /_/   |____/ ");
}
void ascii74(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  _  _   ");
    mvwprintw(win, 2, 1, "|___  || || |  ");
    mvwprintw(win, 3, 1, "   / / | || |_ ");
    mvwprintw(win, 4, 1, "  / /  |__   _|");
    mvwprintw(win, 5, 1, " /_/      |_|  ");
}
void ascii75(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  ____  ");
    mvwprintw(win, 2, 1, "|___  || ___| ");
    mvwprintw(win, 3, 1, "   / / |___ \\ ");
    mvwprintw(win, 4, 1, "  / /   ___) |");
    mvwprintw(win, 5, 1, " /_/   |____/ ");
}
void ascii76(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  __   ");
    mvwprintw(win, 2, 1, "|___  |/ /_  ");
    mvwprintw(win, 3, 1, "   / /| '_ \\ ");
    mvwprintw(win, 4, 1, "  / / | (_) |");
    mvwprintw(win, 5, 1, " /_/   \\___/ ");
}
void ascii77(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  _____ ");
    mvwprintw(win, 2, 1, "|___  ||___  |");
    mvwprintw(win, 3, 1, "   / /    / / ");
    mvwprintw(win, 4, 1, "  / /    / /  ");
    mvwprintw(win, 5, 1, " /_/    /_/   ");
}
void ascii78(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  ___  ");
    mvwprintw(win, 2, 1, "|___  |( _ ) ");
    mvwprintw(win, 3, 1, "   / / / _ \\ ");
    mvwprintw(win, 4, 1, "  / / | (_) |");
    mvwprintw(win, 5, 1, " /_/   \\___/ ");
}
void ascii79(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _____  ___  ");
    mvwprintw(win, 2, 1, "|___  |/ _ \\ ");
    mvwprintw(win, 3, 1, "   / /| (_) |");
    mvwprintw(win, 4, 1, "  / /  \\__, |");
    mvwprintw(win, 5, 1, " /_/     /_/ ");
}
void ascii80(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___    ___  ");
    mvwprintw(win, 2, 1, " ( _ )  / _ \\ ");
    mvwprintw(win, 3, 1, " / _ \\ | | | |");
    mvwprintw(win, 4, 1, "| (_) || |_| |");
    mvwprintw(win, 5, 1, " \\___/  \\___/ ");
}
void ascii81(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___   _ ");
    mvwprintw(win, 2, 1, " ( _ ) / |");
    mvwprintw(win, 3, 1, " / _ \\ | |");
    mvwprintw(win, 4, 1, "| (_) || |");
    mvwprintw(win, 5, 1, " \\___/ |_|");
}
void ascii82(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  ____  ");
    mvwprintw(win, 2, 1, " ( _ )|___ \\ ");
    mvwprintw(win, 3, 1, " / _ \\  __) |");
    mvwprintw(win, 4, 1, "| (_) |/ __/ ");
    mvwprintw(win, 5, 1, " \\___/|_____|");
}
void ascii83(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  _____ ");
    mvwprintw(win, 2, 1, " ( _ )|___ / ");
    mvwprintw(win, 3, 1, " / _ \\  |_ \\ ");
    mvwprintw(win, 4, 1, "| (_) |___) |");
    mvwprintw(win, 5, 1, " \\___/|____/ ");
}
void ascii84(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___   _  _   ");
    mvwprintw(win, 2, 1, " ( _ ) | || |  ");
    mvwprintw(win, 3, 1, " / _ \\ | || |_ ");
    mvwprintw(win, 4, 1, "| (_) ||__   _|");
    mvwprintw(win, 5, 1, " \\___/    |_|  ");
}
void ascii85(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  ____  ");
    mvwprintw(win, 2, 1, " ( _ )| ___| ");
    mvwprintw(win, 3, 1, " / _ \\|___ \\ ");
    mvwprintw(win, 4, 1, "| (_) |___) |");
    mvwprintw(win, 5, 1, " \\___/|____/ ");
}
void ascii86(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___    __   ");
    mvwprintw(win, 2, 1, " ( _ )  / /_  ");
    mvwprintw(win, 3, 1, " / _ \\ | '_ \\ ");
    mvwprintw(win, 4, 1, "| (_) || (_) |");
    mvwprintw(win, 5, 1, " \\___/  \\___/ ");
}
void ascii87(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  _____ ");
    mvwprintw(win, 2, 1, " ( _ )|___  |");
    mvwprintw(win, 3, 1, " / _ \\   / / ");
    mvwprintw(win, 4, 1, "| (_) | / /  ");
    mvwprintw(win, 5, 1, " \\___/ /_/   ");
}
void ascii88(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___    ___  ");
    mvwprintw(win, 2, 1, " ( _ )  ( _ ) ");
    mvwprintw(win, 3, 1, " / _ \\  / _ \\ ");
    mvwprintw(win, 4, 1, "| (_) || (_) |");
    mvwprintw(win, 5, 1, " \\___/  \\___/ ");
}
void ascii89(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___   ___  ");
    mvwprintw(win, 2, 1, " ( _ ) / _ \\ ");
    mvwprintw(win, 3, 1, " / _ \\| (_) |");
    mvwprintw(win, 4, 1, "| (_) |\\__, |");
    mvwprintw(win, 5, 1, " \\___/   /_/ ");
}
void ascii90(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___    ___  ");
    mvwprintw(win, 2, 1, " / _ \\  / _ \\ ");
    mvwprintw(win, 3, 1, "| (_) || | | |");
    mvwprintw(win, 4, 1, " \\__, || |_| |");
    mvwprintw(win, 5, 1, "   /_/  \\___/ ");
}
void ascii91(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___   _ ");
    mvwprintw(win, 2, 1, " / _ \\ / |");
    mvwprintw(win, 3, 1, "| (_) || |");
    mvwprintw(win, 4, 1, " \\__, || |");
    mvwprintw(win, 5, 1, "   /_/ |_|");
}
void ascii92(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  ____  ");
    mvwprintw(win, 2, 1, " / _ \\|___ \\ ");
    mvwprintw(win, 3, 1, "| (_) | __) |");
    mvwprintw(win, 4, 1, " \\__, |/ __/ ");
    mvwprintw(win, 5, 1, "   /_/|_____|");
}
void ascii93(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  _____ ");
    mvwprintw(win, 2, 1, " / _ \\|___ / ");
    mvwprintw(win, 3, 1, "| (_) | |_ \\ ");
    mvwprintw(win, 4, 1, " \\__, |___) |");
    mvwprintw(win, 5, 1, "   /_/|____/ ");
}
void ascii94(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___   _  _   ");
    mvwprintw(win, 2, 1, " / _ \\ | || |  ");
    mvwprintw(win, 3, 1, "| (_) || || |_ ");
    mvwprintw(win, 4, 1, " \\__, ||__   _|");
    mvwprintw(win, 5, 1, "   /_/    |_|  ");
}
void ascii95(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___   ____  ");
    mvwprintw(win, 2, 1, " / _ \\ | ___| ");
    mvwprintw(win, 3, 1, "| (_) ||___ \\ ");
    mvwprintw(win, 4, 1, " \\__, | ___) |");
    mvwprintw(win, 5, 1, "   /_/ |____/ ");
}
void ascii96(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___    __   ");
    mvwprintw(win, 2, 1, " / _ \\  / /_  ");
    mvwprintw(win, 3, 1, "| (_) || '_ \\ ");
    mvwprintw(win, 4, 1, " \\__, || (_) |");
    mvwprintw(win, 5, 1, "   /_/  \\___/ ");
}
void ascii97(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___  _____ ");
    mvwprintw(win, 2, 1, " / _ \\|___  |");
    mvwprintw(win, 3, 1, "| (_) |  / / ");
    mvwprintw(win, 4, 1, " \\__, | / /  ");
    mvwprintw(win, 5, 1, "   /_/ /_/   ");
}
void ascii98(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___    ___  ");
    mvwprintw(win, 2, 1, " / _ \\  ( _ ) ");
    mvwprintw(win, 3, 1, "| (_) | / _ \\ ");
    mvwprintw(win, 4, 1, " \\__, || (_) |");
    mvwprintw(win, 5, 1, "   /_/  \\___/ ");
}
void ascii99(WINDOW *win)
{
    mvwprintw(win, 1, 1, "  ___    ___  ");
    mvwprintw(win, 2, 1, " / _ \\  / _ \\ ");
    mvwprintw(win, 3, 1, "| (_) || (_) |");
    mvwprintw(win, 4, 1, " \\__, | \\__, |");
    mvwprintw(win, 5, 1, "   /_/    /_/ ");
}
void ascii100(WINDOW *win)
{
    mvwprintw(win, 1, 1, " _   ___    ___  ");
    mvwprintw(win, 2, 1, "/ | / _ \\  / _ \\ ");
    mvwprintw(win, 3, 1, "| || | | || | | |");
    mvwprintw(win, 4, 1, "| || |_| || |_| |");
    mvwprintw(win, 5, 1, "|_| \\___/  \\___/ ");
}

// I should start a GoFundMe for the RSI this is giving me
void printAscii(WINDOW *win, int roll)
{
    switch(roll)
    {
        case 0:
            zeroRoll(win);
            break;
        case 1:
            ascii1(win);
            break;
        case 2:
            ascii2(win);
            break;
        case 3:
            ascii3(win);
            break;
        case 4:
            ascii4(win);
            break;
        case 5:
            ascii5(win);
            break;
        case 6:
            ascii6(win);
            break;
        case 7:
            ascii7(win);
            break;
        case 8:
            ascii8(win);
            break;
        case 9:
            ascii9(win);
            break;
        case 10:
            ascii10(win);
            break;
        case 11:
            ascii11(win);
            break;
        case 12:
            ascii12(win);
            break;
        case 13:
            ascii13(win);
            break;
        case 14:
            ascii14(win);
            break;
        case 15:
            ascii15(win);
            break;
        case 16:
            ascii16(win);
            break;
        case 17:
            ascii17(win);
            break;
        case 18:
            ascii18(win);
            break;
        case 19:
            ascii19(win);
            break;
        case 20:
            ascii20(win);
            break;
        case 21:
            ascii21(win);
            break;
        case 22:
            ascii22(win);
            break;
        case 23:
            ascii23(win);
            break;
        case 24:
            ascii24(win);
            break;
        case 25:
            ascii25(win);
            break;
        case 26:
            ascii26(win);
            break;
        case 27:
            ascii27(win);
            break;
        case 28:
            ascii28(win);
            break;
        case 29:
            ascii29(win);
            break;
        case 30:
            ascii30(win);
            break;
        case 31:
            ascii31(win);
            break;
        case 32:
            ascii32(win);
            break;
        case 33:
            ascii33(win);
            break;
        case 34:
            ascii34(win);
            break;
        case 35:
            ascii35(win);
            break;
        case 36:
            ascii36(win);
            break;
        case 37:
            ascii37(win);
            break;
        case 38:
            ascii38(win);
            break;
        case 39:
            ascii39(win);
            break;
        case 40:
            ascii40(win);
            break;
        case 41:
            ascii41(win);
            break;
        case 42:
            ascii42(win);
            break;
        case 43:
            ascii43(win);
            break;
        case 44:
            ascii44(win);
            break;
        case 45:
            ascii45(win);
            break;
        case 46:
            ascii46(win);
            break;
        case 47:
            ascii47(win);
            break;
        case 48:
            ascii48(win);
            break;
        case 49:
            ascii49(win);
            break;
        case 50:
            ascii50(win);
            break;
        case 51:
            ascii51(win);
            break;
        case 52:
            ascii52(win);
            break;
        case 53:
            ascii53(win);
            break;
        case 54:
            ascii54(win);
            break;
        case 55:
            ascii55(win);
            break;
        case 56:
            ascii56(win);
            break;
        case 57:
            ascii57(win);
            break;
        case 58:
            ascii58(win);
            break;
        case 59:
            ascii59(win);
            break;
        case 60:
            ascii60(win);
            break;
        case 61:
            ascii61(win);
            break;
        case 62:
            ascii62(win);
            break;
        case 63:
            ascii63(win);
            break;
        case 64:
            ascii64(win);
            break;
        case 65:
            ascii65(win);
            break;
        case 66:
            ascii66(win);
            break;
        case 67:
            ascii67(win);
            break;
        case 68:
            ascii68(win);
            break;
        case 69:
            ascii69(win);
            break;
        case 70:
            ascii70(win);
            break;
        case 71:
            ascii71(win);
            break;
        case 72:
            ascii72(win);
            break;
        case 73:
            ascii73(win);
            break;
        case 74:
            ascii74(win);
            break;
        case 75:
            ascii75(win);
            break;
        case 76:
            ascii76(win);
            break;
        case 77:
            ascii77(win);
            break;
        case 78:
            ascii78(win);
            break;
        case 79:
            ascii79(win);
            break;
        case 80:
            ascii80(win);
            break;
        case 81:
            ascii81(win);
            break;
        case 82:
            ascii82(win);
            break;
        case 83:
            ascii83(win);
            break;
        case 84:
            ascii84(win);
            break;
        case 85:
            ascii85(win);
            break;
        case 86:
            ascii86(win);
            break;
        case 87:
            ascii87(win);
            break;
        case 88:
            ascii88(win);
            break;
        case 89:
            ascii89(win);
            break;
        case 90:
            ascii90(win);
            break;
        case 91:
            ascii91(win);
            break;
        case 92:
            ascii92(win);
            break;
        case 93:
            ascii93(win);
            break;
        case 94:
            ascii94(win);
            break;
        case 95:
            ascii95(win);
            break;
        case 96:
            ascii96(win);
            break;
        case 97:
            ascii97(win);
            break;
        case 98:
            ascii98(win);
            break;
        case 99:
            ascii99(win);
            break;
        case 100:
            ascii100(win);
            break;
        default:
            break;
    }
    if (roll > 100)
        over100(win);
}
