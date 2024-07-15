#include "../include/character_creator.h"
#include "../include/export.h"
#include "OpenXLSX/OpenXLSX.hpp"
#include <string>


void createSpreadsheet(std::string p_name, std::string c_name, std::string c_class,
                       std::string c_race, std::string c_sub, Character character)
{
    // Load character sheet template
    OpenXLSX::XLDocument doc;
    doc.open("../files/Character Sheet (Template).xlsx");
    auto wks = doc.workbook().worksheet("Character");


    // Player/Character Information //
    wks.cell("F2").value() = p_name;
    wks.cell("F3").value() = c_name;
    wks.cell("J2").value() = c_class;
    // "Drow Elf" isn't a thing, so just print Drow
    if (c_sub == "Drow")
    {
        wks.cell("J3").value() = c_sub;
    
    } else if (c_sub == " ") {
        wks.cell("J3").value() = c_race;
    } else {
        std::string full_race = c_sub + " " + c_race;
        wks.cell("J3").value() = full_race;
    }

    // Character Stats //
    wks.cell("C6").value() = character.str_base;
    wks.cell("F6").value() = character.dex_base;
    wks.cell("I6").value() = character.con_base;
    wks.cell("L6").value() = character.int_base;
    wks.cell("O6").value() = character.wis_base;
    wks.cell("R6").value() = character.cha_base;

    std::string filename = "../files/characters/" + c_name + ".xlsx";

    doc.saveAs(filename);
}
