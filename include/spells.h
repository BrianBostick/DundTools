#ifndef SPELLS_H
#define SPELLS_H

#include <string>

class Spell
{
    public:
        int level;
        std::string name;
        std::string school;
        std::string cast_time;
        std::string duration;
        std::string components;
        std::string damage;
        std::string range;
        std::string description;
        bool concentration;

        Spell(int a, std::string b, std::string c, std::string d, std::string e,
                std::string f, std::string g, std::string h, std::string i, bool j)
        {
            level = a;
            name = b;
            school = c;
            cast_time = d;
            duration = e;
            components = f;
            damage = g;
            range = h;
            description = i;
            concentration = j;
        }
};

#endif
