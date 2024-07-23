#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "export.h"
#include "stats.h"
#include <string>

class Weapon
{
    public:
        std::string name;
        int range;
        std::string damage;
        std::string dmg_type;
        bool prof;

        Weapon(std::string a, int b, std::string c, std::string d, bool e)
        {
            name = a;
            range = b;
            damage = c;
            dmg_type = d;
            prof = e;
        }
};

class Armor
{
    public:
        int ac;
        int min_str;
        bool disadvantage;

        Armor(int a, int b, bool c)
        {
            ac = a;
            min_str = b;
            disadvantage = c;
        }
};

Weapon martialWeapons(int);
Weapon simpleWeapons(int);
Armor lightArmor(int, StatMods);
Armor mediumArmor(int, StatMods);
Armor heavyArmor(int);
Armor shield();

#endif
