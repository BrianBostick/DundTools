#ifndef CHARACTER_CREATOR_H
#define CHARACTER_CREATOR_H

#include <ncurses.h>
#include <string>

void genCCWindow();
std::string getPlayerName(WINDOW *, int, int);
std::string getCharName(WINDOW *, int, int);
std::string getCharClass(WINDOW *, int);
std::string getCharRace(WINDOW *, int);
bool checkForSub(std::string);
std::string getCharSubRace(WINDOW *, int, std::string);

#endif
