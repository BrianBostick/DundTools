#ifndef RACE_STATS_H
#define RACE_STATS_H
#include <string>

// list of player-selectable races
const std::string race_list[9] = { "Dragonborn", "Dwarf", "Elf",
                                 "Gnome", "Half-Elf", "Half-Orc",
                                 "Halfling", "Human", "Tiefling" };
// all of the sub races available for each race
const std::string db_sub_races[10] = { "Black", "Blue", "Brass", "Bronze", "Copper",
                                     "Gold", "Green", "Red", "Silver", "White" };
const std::string dwarf_sub_races[2] = { "Hill", "Mountain" };
const std::string elf_sub_races[3] = { "Drow", "High", "Wood" };
const std::string gnome_sub_races[2] = { "Forest", "Rock" };
const std::string halfling_sub_races[2] = { "Lightfoot", "Stout" };
const std::string human_sub_races[2] = { "Base", "Variant" };

// race stats
class Race
{
public:

    int m_str{};
    int m_dex{};
    int m_con{};
    int m_int{};
    int m_wis{};
    int m_cha{};

    std::string_view m_name{};
    bool m_has_subrace;
    int m_list_index{};
    
    void setStats(int str, int dex, int con,
                 int intel, int wis, int cha,
                 std::string name, bool has_sub);
};

// subrace stats
class SubRace
{
public:

    int m_str{};
    int m_dex{};
    int m_con{};
    int m_int{};
    int m_wis{};
    int m_cha{};

    std::string_view m_name{};
    int m_list_index{};
    int m_sub_index{};
    
    void setSubStats(int str, int dex, int con, int intel,
                    int wis, int cha, std::string name,
                    int race_index, int sub_index);
};

// set stats for each race by defining them as class objects
void setRaceStats();
// apply the stats to the race class objects
void defRaceStats();
// do the same thing for the subraces
std::string defSubList( int, int );

#endif