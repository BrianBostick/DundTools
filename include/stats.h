#ifndef STATS_H
#define STATS_H

#include "diceroll.h"
#include "logos.h"
#include <ncurses.h>
#include <string>

class StatMods
{
    public:
        std::string name;
        int str_mod;
        int dex_mod;
        int con_mod;
        int int_mod;
        int wis_mod;
        int cha_mod;

        StatMods(std::string name, int a, int b, int c, int d, int e, int f)
        {
            name = name;
            str_mod = a;
            dex_mod = b;
            con_mod = c;
            int_mod = d;
            wis_mod = e;
            cha_mod = f;
        }
};

int rollStats();

int getStrNoSub(std::string);
int getStrSub(std::string);
int getDexNoSub(std::string);
int getDexSub(std::string);
int getConNoSub(std::string);
int getConSub(std::string);
int getIntNoSub(std::string);
int getIntSub(std::string);
int getWisNoSub(std::string);
int getWisSub(std::string);
int getChaNoSub(std::string);
int getChaSub(std::string);
void stdArray1(WINDOW *, int, std::string);

#endif
