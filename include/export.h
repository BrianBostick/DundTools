#ifndef EXPORT
#define EXPORT

#include "character_creator.h"
#include "OpenXLSX/OpenXLSX.hpp"
#include <string>

void createSpreadsheet(std::string, std::string, std::string,
                       std::string, std::string, Character);

#endif
