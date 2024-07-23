#ifndef DICEROLL_H
#define DICEROLL_H

#include "name_generator.h"
#include "../include/ascii_nums.h"
#include "../include/logos.h"
#include "../include/tui.h"
#include <inttypes.h>
#include <ncurses.h>
#include <random>
#include <string>

// roll x y-sided dice
int diceRoll( int, int );
void genDicerollWindow();
int getNumDice(int, int);
int getTypeDice(int, int);
int getDiceMod(int, int);
int rollDice(int, int, int);
int getStats();

#endif
