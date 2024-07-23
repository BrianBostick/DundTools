#include "../include/equipment.h"
#include "../include/export.h"
#include "../include/stats.h"
#include <string>

Weapon martialWeapons(int index)
{
    Weapon Battleaxe("Battleaxe (V)", 5, "1d8", "Slashing", true);
    Weapon Flail("Flail", 5, "1d8", "Bludgeoning", true);
    Weapon Glaive("Glaive", 10, "1d10", "Slashing", true);
    Weapon Greataxe("Greataxe", 5, "1d12", "Slashing", true);
    Weapon Greatsword("Greatsword", 5, "2d6", "Slashing", true);
    Weapon Halberd("Halberd", 10, "1d10", "Slashing", true);
    Weapon Lance("Lance", 10, "1d12", "Piercing", true);
    Weapon Longsword("Longsword (V)", 5, "1d8", "Slashing", true);
    Weapon Maul("Maul", 5, "2d6", "Bludgeoning", true);
    Weapon Morningstar("Morningstar", 5, "1d8", "Piercing", true);
    Weapon Pike("Pike", 10, "1d10", "Piercing", true);
    Weapon Rapier("Rapier (F)", 5, "1d8", "Piercing", true);
    Weapon Scimitar("Scimitar (F)", 5, "1d6", "Slashing", true);
    Weapon Shortsword("Shortsword (F/L)", 5, "1d6", "Piercing", true);
    Weapon Trident("Trident (V/T)", 5, "1d6", "Piercing", true);
    Weapon WarPick("War Pick", 5, "1d8", "Piercing", true);
    Weapon Warhammer("Warhammer (V)", 5, "1d8", "Bludgeoning", true);
    Weapon Whip("Whip (F/R)", 10, "1d4", "Slashing", true);
    Weapon Blowgun("Blowgun", 25, "1", "Piercing", true);
    Weapon HandCrossbow("Hand Crossbow (L)", 30, "1d6", "Piercing", true);
    Weapon HeavyCrossbow("Heavy Crossbow", 100, "1d10", "Piercing", true);
    Weapon Longbow("Longbow", 150, "1d8", "Piercing", true);
    Weapon Net("Net", 5, "N/A", "Grapple", true);

    Weapon New_Weapon(" ", 0, " ", " ", false);

    switch(index)
    {
        case 0:
            New_Weapon = Battleaxe;
            break;
        case 1:
            New_Weapon = Flail;
            break;
        case 2:
            New_Weapon = Glaive;
            break;
        case 3:
            New_Weapon = Greataxe;
            break;
        case 4:
            New_Weapon = Greatsword;
            break;
        case 5:
            New_Weapon = Halberd;
            break;
        case 6:
            New_Weapon = Lance;
            break;
        case 7:
            New_Weapon = Longsword;
            break;
        case 8:
            New_Weapon = Maul;
            break;
        case 9:
            New_Weapon = Morningstar;
            break;
        case 10:
            New_Weapon = Pike;
            break;
        case 11:
            New_Weapon = Rapier;
            break;
        case 12:
            New_Weapon = Scimitar;
            break;
        case 13:
            New_Weapon = Shortsword;
            break;
        case 14:
            New_Weapon = Trident;
            break;
        case 15:
            New_Weapon = WarPick;
            break;
        case 16:
            New_Weapon = Warhammer;
            break;
        case 17:
            New_Weapon = Whip;
            break;
        case 18:
            New_Weapon = Blowgun;
            break;
        case 19:
            New_Weapon = HandCrossbow;
            break;
        case 20:
            New_Weapon = HeavyCrossbow;
            break;
        case 21:
            New_Weapon = Longbow;
            break;
        case 22:
            New_Weapon = Net;
            break;
        default:
            break;
    }

    return New_Weapon;
}

Weapon simpleWeapons(int index)
{
    Weapon Club("Club (L)", 5, "1d4", "Bludgeoning", true);
    Weapon Dagger("Dagger (F/L/T)", 5, "1d4", "Piercing", true);
    Weapon Greatclub("Greatclub", 5, "1d8", "Bludgeoning", true);
    Weapon Handaxe("Handaxe (L/T)", 5, "1d6", "Slashing", true);
    Weapon Javelin("Javelin (T)", 30, "1d6", "Piercing", true);
    Weapon LightHammer("Light Hammer (L/T)", 5, "1d4", "Bludgeoning", true);
    Weapon Mace("Mace", 5, "1d4", "Bludgeoning", true);
    Weapon Quarterstaff("Quarterstaff (V)", 5, "1d6", "Bludgeoning", true);
    Weapon Sickle("Sickle (L)", 5, "1d4", "Slashing", true);
    Weapon Spear("Spear (T/V)", 5, "1d6", "Piercing", true);
    Weapon LightCrossbow("Light Crossbow", 80, "1d8", "Piercing", true);
    Weapon Dart("Dart (F)", 20, "1d4", "Piercing", true);
    Weapon Shortbow("Shortbow", 80, "1d6", "Piercing", true);
    Weapon Sling("Sling", 30, "1d4", "Bludgeoning", true);

    Weapon New_Weapon(" ", 0, " ", " ", false);

    switch(index)
    {
        case 0:
            New_Weapon = Club;
            break;
        case 1:
            New_Weapon = Dagger;
            break;
        case 2:
            New_Weapon = Greatclub;
            break;
        case 3:
            New_Weapon = Handaxe;
            break;
        case 4:
            New_Weapon = Javelin;
            break;
        case 5:
            New_Weapon = LightHammer;
            break;
        case 6:
            New_Weapon = Mace;
            break;
        case 7:
            New_Weapon = Quarterstaff;
            break;
        case 8:
            New_Weapon = Sickle;
            break;
        case 9:
            New_Weapon = Spear;
            break;
        case 10:
            New_Weapon = LightCrossbow;
            break;
        case 11:
            New_Weapon = Dart;
            break;
        case 12:
            New_Weapon = Shortbow;
            break;
        case 13:
            New_Weapon = Sling;
            break;
        default:
            break;
    }

    return New_Weapon;
}

Armor lightArmor(int index, StatMods mods)
{
    Armor Padded(11 + mods.dex_mod, 0, true);
    Armor Leather(11 + mods.dex_mod, 0, false);
    Armor StuddedLeather(12 + mods.dex_mod, 0, false);

    Armor New_Armor(0, 0, true);

    switch(index)
    {
        case 0:
            New_Armor = Padded;
            break;
        case 1:
            New_Armor = Leather;
            break;
        case 2:
            New_Armor = StuddedLeather;
            break;
        default:
            break;
    }

    return New_Armor;
}

Armor mediumArmor(int index, StatMods mods)
{
    Armor Hide(12, 0, false);
    Armor ChainShirt(13, 0, false);
    Armor ScaleMail(14, 0, true);
    Armor Breastplate(14, 0, false);
    Armor HalfPlate(15, 0, true);

    Armor New_Armor(0,0,false);

    switch(index)
    {
        case 0:
            New_Armor = Hide;
            break;
        case 1:
            New_Armor = ChainShirt;
            break;
        case 2:
            New_Armor = ScaleMail;
            break;
        case 3:
            New_Armor = Breastplate;
            break;
        case 4:
            New_Armor = HalfPlate;
            break;
        default:
            break;
    }

    if (mods.dex_mod < 3)
    {
        New_Armor.ac += mods.dex_mod;
    } else {
        New_Armor.ac += 2;
    }

    return New_Armor;
}

Armor heavyArmor(int index)
{
    Armor RingMail(14, 0, true);
    Armor ChainMail(16, 13, true);
    Armor Splint(17, 15, true);
    Armor Plate(18, 15, true);

    Armor New_Armor(0,0,false);

    switch(index)
    {
        case 0:
            New_Armor = RingMail;
            break;
        case 1:
            New_Armor = ChainMail;
            break;
        case 2:
            New_Armor = Splint;
            break;
        case 3:
            New_Armor = Plate;
            break;
        default:
            break;
    }

    return New_Armor;
}

Armor shield()
{
    Armor Shield(2, 0, false);

    return Shield;
}
