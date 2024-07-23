#ifndef EXPORT
#define EXPORT

#include "character_creator.h"
#include "equipment.h"
#include "stats.h"
#include "OpenXLSX/OpenXLSX.hpp"
#include <string>

void createSpreadsheet(std::string, std::string, std::string,
                       std::string, std::string, Character, StatMods);
void savingThrowProfs(OpenXLSX::XLWorksheet&, int);

#endif
