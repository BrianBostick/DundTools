#ifndef IO_H
#define IO_H

#include <string>

// get input that returns a string
std::string getString();
// get input that returns an int
int getNum();
// see if "choice" == y, if so, return true
bool checkChoice( char );
// get player input for their race
int getRace();
// get player input for their sub-race, if applicable
int getSubRace( int );

#endif