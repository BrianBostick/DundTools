#include "../include/spells.h"
#include "../include/character_creator.h"
#include <string>

Spell bardCantrips(int index)
{
    Spell BladeWard(0, "Blade Ward", "Abjuration", "1 Action", "1 Round", "V/S", "N/A", "Self",
            "You have resistance against weapon attacks until the end of your next turn.", false);
    Spell DancingLights(0, "Dancing Lights", "Evocation", "1 Action", "1 Minute", "V/S/M", "N/A",
            "Self", "Create 4 hovering, torch-sized lights within range. Light shines in a 10ft radius. Can move them up to 60ft as a bonus action.", true);
    Spell Friends(0, "Friends", "Enchantment", "1 Action", "1 Minute", "S/M", "N/A", "Self",
            "Adv on Cha checks directed at one creature of your choice that isn't hostile. Creature will know it was charmed when spell ends, and may become hostile.", true);
    Spell Light(0, "Light", "Evocation", "1 Action", "1 Hour", "V/M", "N/A", "Touch",
            "An object <10ft in size you touch sheds bright light in a 20ft radius (and dim light for an additional 20ft). If directed at an object wielded by a hostile creature, they must succeed a Dex saving throw to avoid the spell.", true);
    Spell MageHand(0, "Mage Hand", "Conjuration", "1 Action", "1 Minute", "V/S", "N/A", "30ft",
            "Conjure a spectral, floating hand within range. Can maniuplate non-magical objects up to 10 lbs and unlocked doorsHand takes it's turn after yours during the duration of the spell, and can move up to 30ft per turn.", false);
    Spell Mending(0, "Mending", "Transmutation", "1 Minute", "Instant", "V/S/M", "N/A", "Touch",
            "Repair a single break or tear in an object you touch. Break/Tear cannot be larger than 1ft in any dimension. Works on magical items, but cannot restore magic to the item.", false);
    Spell Message(0, "Message", "Transmutation", "1 Action", "1 Round", "V/S/M", "N/A", "120ft",
            "You choose a creature within range and whisper it a message that only it can hear. If willing, the creature can reply in a whisper that only you can hear.", false);
    Spell MinorIllusion(0, "Minor Illusion", "Illusion", "1 Action", "1 Minute", "S/M", "30ft",
            "Create a sound or image of an object (within a 5ft cube) within range. If a creature examines the sound/image, they can determine that it is an illusion with a successful investigation check.", false);
    Spell Prestidigitation(0, "Prestidigitation", "Transmuation", "1 Action", "1 Hour", "V/S", "N/A", "10ft",
            "Create a minor sensory effect (smell, image, sound, etc) within range. Up to 3 non-instantaneous effects can be active at one time.", false);
    Spell TrueStrike(0, "True Strike", "Divination", "1 Action", "1 Round", "S", "N/A", "30ft",
            "Gain insight to your target's defenses - you have advantage on your first attack roll against the target on your next turn.", true);
    Spell ViciousMockery(0, "Vicious Mockery", "Enchantment", "1 Action", "Instant", "V", "1d4", "60ft",
            "You hurl an enchantment disguised as an insult at a creature within range that can hear you. If it fails a Wis save, it takes 1d4 Psychic damage and has disadvantage on it's next attack roll.", false);

    Spell New_Spell(0," "," "," "," "," "," "," "," ",false);

    switch(index)
    {
        case 0:
            New_Spell = BladeWard;
            break;
        case 1:
            New_Spell = DancingLights;
            break;
        case 2:
            New_Spell = Friends;
            break;
        case 3:
            New_Spell = Light;
            break;
        case 4:
            New_Spell = MageHand;
            break;
        case 5:
            New_Spell = Mending;
            break;
        case 6:
            New_Spell = Message;
            break;
        case 7:
            New_Spell = MinorIllusion;
            break;
        case 8:
            New_Spell = Prestidigitation;
            break;
        case 9:
            New_Spell = TrueStrike;
            break;
        case 10:
            New_Spell = ViciousMockery;
            break;
        default:
            break;
    }

    return New_Spell;
}
