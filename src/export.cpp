#include "../include/character_creator.h"
#include "../include/equipment.h"
#include "../include/export.h"
#include "../include/stats.h"
#include "OpenXLSX/OpenXLSX.hpp"
#include <string>
#include <sstream>


void createSpreadsheet(std::string p_name, std::string c_name, std::string c_class,
                       std::string c_race, std::string c_sub, Character character, StatMods mods)
{
    // Get list indicies to use later
    int class_index = 0;
    int race_index = 0;
    int sub_index = 0;

    std::string class_list[12] = {"Barbarian", "Bard", "Cleric", "Druid",
                                  "Fighter", "Monk", "Paladin", "Ranger",
                                  "Rogue", "Sorcerer", "Warlock", "Wizard"};
    std::string race_list[9] = {"Dragonborn", "Dwarf", "Elf", "Gnome", "Half-Elf",
                                 "Half-Orc", "Halfling", "Human", "Tiefling"};
    std::string sub_races[11] = {"Hill", "Mountain", "Drow", "High", "Wood",
                                 "Forest", "Rock", "Lightfoot", "Stout", "Base", "Variant"};

    for (int i = 0; i < 12; ++i)
    {
        if (c_class == class_list[i])
        {
            class_index = i;
            break;
        }
    }
    for (int i = 0; i < 9; ++i)
    {
        if (c_race == race_list[i])
        {
            race_index = i;
            break;
        }
    }
    for (int i = 0; i < 11; ++i)
    {
        if (c_sub == " ")
        {
            // If there is no sub class, set the index outside the available list values
            sub_index = 12;
            break;
        } else if (c_sub == sub_races[i]) {
            sub_index = i;
            break;
        }
    }

    // Load character sheet template
    OpenXLSX::XLDocument doc;
    doc.open("../files/Character Sheet (Template).xlsx");
    auto wks1 = doc.workbook().worksheet("Character");
    auto wks2 = doc.workbook().worksheet("Skills");


    // Player/Character Information (Worksheet1) //
    wks1.cell("F2").value() = p_name;
    wks1.cell("F3").value() = c_name;
    wks1.cell("J2").value() = c_class;
    // "Drow Elf" isn't a thing, so just print Drow
    if (sub_index == 2)
    {
        wks1.cell("J3").value() = c_sub;
    
    } else if (c_sub == " ") {
        wks1.cell("J3").value() = c_race;
    } else {
        std::string full_race = c_sub + " " + c_race;
        wks1.cell("J3").value() = full_race;
    }

    // Character Stats //
    wks1.cell("C6").value() = character.str_base;
    wks1.cell("F6").value() = character.dex_base;
    wks1.cell("I6").value() = character.con_base;
    wks1.cell("L6").value() = character.int_base;
    wks1.cell("O6").value() = character.wis_base;
    wks1.cell("R6").value() = character.cha_base;
    // Stat Mods
    wks1.cell("D8").value() = mods.str_mod;
    wks1.cell("G8").value() = mods.dex_mod;
    wks1.cell("J8").value() = mods.con_mod;
    wks1.cell("M8").value() = mods.int_mod;
    wks1.cell("P8").value() = mods.wis_mod;
    wks1.cell("S8").value() = mods.cha_mod;

    // Proficiency Mod
    wks1.cell("U6").value() = 2;

    // Starting HP
    wks1.cell("E11").value() = getHP(c_class, c_sub, mods.con_mod);
    wks1.cell("E12").value() = getHP(c_class, c_sub, mods.con_mod);

    // Hit die
    if (sub_index == 0)
    {
        wks1.cell("E15").value() = getHP(c_class, c_sub, mods.con_mod) - mods.con_mod;
    } else {
        wks1.cell("E15").value() = getHP(c_class, c_sub, mods.con_mod) - mods.con_mod - 1;
    }

    // Initiative
    wks1.cell("P11").value() = mods.dex_mod;

    // Proficiencies
    // Class Proficiencies
    switch(class_index)
    {
        case 0:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E22").value() = "Martial";
            wks1.cell("E28").value() = "Light";
            wks1.cell("E29").value() = "Medium";
            wks1.cell("E30").value() = "Shields";
            break;
        case 1:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E22").value() = "Hand Crossbows";
            wks1.cell("E23").value() = "Longswords";
            wks1.cell("E24").value() = "Rapiers";
            wks1.cell("E25").value() = "Shortswords";
            wks1.cell("E28").value() = "Light";
            break;
        case 2:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E28").value() = "Light";
            wks1.cell("E29").value() = "Medium";
            wks1.cell("E30").value() = "Shields";
            break;
        case 3:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E28").value() = "Light (Non-Metal)";
            wks1.cell("E29").value() = "Medium (Non-Metal)";
            break;
        case 4:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E22").value() = "Martial";
            wks1.cell("E28").value() = "Light";
            wks1.cell("E29").value() = "Medium";
            wks1.cell("E30").value() = "Heavy";
            wks1.cell("E31").value() = "Shields";
            break;
        case 5:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E22").value() = "Shortswords";
            break;
        case 6:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E22").value() = "Martial";
            wks1.cell("E28").value() = "Light";
            wks1.cell("E29").value() = "Medium";
            wks1.cell("E30").value() = "Heavy";
            wks1.cell("E31").value() = "Shields";
            break;
        case 7:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E22").value() = "Martial";
            wks1.cell("E28").value() = "Light";
            wks1.cell("E29").value() = "Medium";
            wks1.cell("E30").value() = "Shields";
            break;
        case 8:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E22").value() = "Hand Crossbows";
            wks1.cell("E23").value() = "Longswords";
            wks1.cell("E24").value() = "Rapiers";
            wks1.cell("E25").value() = "Shortswords";
            wks1.cell("E28").value() = "Light";
            break;
        case 9:
            wks1.cell("E21").value() = "Daggers";
            wks1.cell("E22").value() = "Darts";
            wks1.cell("E23").value() = "Slings";
            wks1.cell("E24").value() = "Quarterstaffs";
            wks1.cell("E25").value() = "Light Crossbows";
            break;
        case 10:
            wks1.cell("E21").value() = "Simple";
            wks1.cell("E28").value() = "Light";
            break;
        case 11:
            wks1.cell("E21").value() = "Daggers";
            wks1.cell("E22").value() = "Darts";
            wks1.cell("E23").value() = "Slings";
            wks1.cell("E24").value() = "Quarterstaffs";
            wks1.cell("E25").value() = "Light Crossbows";
            break;
        default:
            break;
    }

    // Languages
    wks1.cell("E33").value() = "Common";


    // Skills (Worksheet2) //
    // Stats
    wks2.cell("C4").value() = wks1.cell("C6").value();
    wks2.cell("F4").value() = wks1.cell("F6").value();
    wks2.cell("I4").value() = wks1.cell("I6").value();
    wks2.cell("L4").value() = wks1.cell("L6").value();
    wks2.cell("O4").value() = wks1.cell("O6").value();
    wks2.cell("R4").value() = wks1.cell("R6").value();
    // Modifiers
    wks2.cell("D6").value() = mods.str_mod;
    wks2.cell("G6").value() = mods.dex_mod;
    wks2.cell("J6").value() = mods.con_mod;
    wks2.cell("M6").value() = mods.int_mod;
    wks2.cell("P6").value() = mods.wis_mod;
    wks2.cell("S6").value() = mods.cha_mod;
    // Proficiency
    wks2.cell("U4").value() = wks1.cell("U6").value();

    // Saving Throw Proficiency
    savingThrowProfs(wks2, class_index);

    // Weapons
    Weapon New_Weapon(" ", 0, " ", " ", false);
    New_Weapon = martialWeapons(0);
    wks2.cell("M11").value() = New_Weapon.name;
    wks2.cell("O11").value() = New_Weapon.range;
    wks2.cell("Q11").value() = New_Weapon.damage;
    wks2.cell("S11").value() = New_Weapon.dmg_type;

    // Armor
    Armor New_Armor(0,0,false);
    New_Armor = lightArmor(1, mods);
// 7-18

    // Save spreadsheet
    std::string filename = "../files/characters/" + c_name + ".xlsx";
    doc.saveAs(filename);
}

void savingThrowProfs(OpenXLSX::XLWorksheet& wks, int class_index)
{
    //auto wks = doc.workbook().worksheet("Skills");

    switch(class_index)
    {
        case 0:
            wks.cell("B10").value() = "X";
            wks.cell("B12").value() = "X";
            break;
        case 1:
            wks.cell("B11").value() = "X";
            wks.cell("B15").value() = "X";
            break;
        case 2:
            wks.cell("B14").value() = "X";
            wks.cell("B15").value() = "X";
            break;
        case 3:
            wks.cell("B13").value() = "X";
            wks.cell("B14").value() = "X";
            break;
        case 4:
            wks.cell("B10").value() = "X";
            wks.cell("B12").value() = "X";
            break;
        case 5:
            wks.cell("B10").value() = "X";
            wks.cell("B14").value() = "X";
            break;
        case 6:
            wks.cell("B14").value() = "X";
            wks.cell("B15").value() = "X";
            break;
        case 7:
            wks.cell("B10").value() = "X";
            wks.cell("B11").value() = "X";
            break;
        case 8:
            wks.cell("B11").value() = "X";
            wks.cell("B13").value() = "X";
            break;
        case 9:
            wks.cell("B12").value() = "X";
            wks.cell("B15").value() = "X";
            break;
        case 10:
            wks.cell("B14").value() = "X";
            wks.cell("B15").value() = "X";
            break;
        case 11:
            wks.cell("B13").value() = "X";
            wks.cell("B14").value() = "X";
            break;
        default:
            break;
    }
}
