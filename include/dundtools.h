#ifndef TUI_H
#define TUI_H

#include <ncurses.h>
#include <inttypes.h>
#include <string>

// Window management
void refreshWindow(WINDOW *);

// Home Screen
void genHomeWindow(WINDOW *, int, int, WINDOW *, WINDOW *, WINDOW *);
void genLogoWindow(WINDOW *, int, int);

// Character creator
void genCCWindow();

// Name generator
void genNameGenerator();

#endif
