#ifndef CHARACTER_CREATOR_H
#define CHARACTER_CREATOR_H

#include <ncurses.h>
#include <string>

class Character
{
    public:
        mutable int str_base;
        mutable int dex_base;
        mutable int con_base;
        mutable int int_base;
        mutable int wis_base;
        mutable int cha_base;

        Character(int a, int b, int c, int d, int e, int f)
        {
            str_base = a;
            dex_base = b;
            con_base = c;
            int_base = d;
            wis_base = e;
            cha_base = f;
        }
};

void genCCWindow();
std::string getPlayerName(WINDOW *, int, int);
std::string getCharName(WINDOW *, int, int);
std::string getCharClass(WINDOW *, int);
std::string getCharRace(WINDOW *, int);
bool checkForSub(std::string);
std::string getCharSubRace(WINDOW *, int, std::string);
std::string halfElf(WINDOW *, int);

#endif
