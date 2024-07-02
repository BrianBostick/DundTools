# DundTools
A collection of TUI and CLI tools for D&D 5e games.

**This has only been tested on Linux systems. Specifically Linux Mint 21.3, Arch Linux, and a Raspberry Pi OS 32-bit. It should *in theory* work on MacOS, but I have no way of testing it on Windows.**

The only dependency is Ncurses.

If you want to build the program, install the Ncurses library (should be available in your package manager, I believe it was `libncurses-dev` for Ubuntu-based Linux distros), clone the repo, cd into the `src` directory, and run `make`. As long as you have the correct Ncurses library installed, you should be able to run the application from here with `./tui`.

If it doesn't work, I'm afraid I'm not going to be a whole lot of help.

Also keep in mind that this is *very* much a WIP - expect lots of bugs, errors, crashes, and general not-good times. I'm always happy to receive bug reports.

So far I plan on adding the following modules:
(C = Completed, W = WIP, P = Planned)

- Dice Roller (Standalone (C) & TUI (C))
- Character Creator (W)
    - Import/Export characters from .xlsx files (P)
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

Compile it with `make` and run it with:

`./rolldice <number of dice> <type of dice> <mod>`

(Use a negative number to subtract the modifier)

I wrote this when I was *first starting* to learn C++, so it's pretty rough. I plan on rewriting it soon now that I've learned a bit more.

As of right now, it throws an error if you don't include all 3 arguments.

