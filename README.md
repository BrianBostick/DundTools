# DundTools
A collection of TUI and CLI tools for D&D 5e games.

<hr>
Dependencies:

Ncurses
[OpenXLSX](https://github.com/troldal/OpenXLSX)
<hr>

**This has only been tested on Linux systems. Specifically Linux Mint 21.3, Arch Linux, and a Raspberry Pi OS 32-bit. It should *in theory* work on MacOS, but I have no way of testing it on Windows.**

After cloning the repo:

`cd DundTools/src`
To compile just the TUI application: `make tui`
To compile just the CLI dice roller: `make rolldice`
To compile both: `make all` (Just `make` also works if you're lazy)

As long as you have the correct Ncurses library installed, you should be able to compile and run the applications from here with `./tui` and `./rolldice`.

If it doesn't work, I'm afraid I'm not going to be a whole lot of help.

Also keep in mind that this is *very* much a WIP - expect lots of bugs, errors, crashes, and general not-good times. I'm always happy to receive bug reports.

So far I plan on adding the following modules:
(C = Completed, W = WIP, P = Planned)

- Dice Roller (Standalone (C) & TUI (C))
- Character Creator (W)
    - Import/Export characters from .xlsx files (W)
    - Edit existing characters (P)
    - Level up characters (P)
    - (Character sheet is itself a WIP)
- Notes App (P)
- DM Screen (P)
    - Notes (P)
    - Name Generator (P)
    - Beastiary/Stat Blocks (P)
    - Dice Roller (P)
    - Initiative Tracker (P)
    - +/- Counter (P)
- Rules Reference (P)
- Spell List (P)

I haven't decided yet if I'm going to try and make all of the above modules into standalone applications. I've already done the dice roller, but the notes app and name generator sound like good candidates as well.

I'm going to have to look into some legal stuff once I get into the later modules - I don't want Hasbro coming after me for uploading content from paid sourcebooks onto Github.

A GUI version of the app may also be a consideration for the future. But for now, I'm going to stick with CLI/TUI based graphics. I want to be able to use the application on any device - possibly even over SSH.


# RollDice
RollDice is a standalone CLI dice rolling simulator.

After cloning the repo, use the following commands:

`cd DundTools/src`
`make rolldice`

Run the program with:

`./rolldice <number of dice> <type of dice> <mod>`

(Use a negative number to subtract the modifier)
