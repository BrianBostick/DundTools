# DundTools
A collection of TUI and CLI tools for D&D 5e games.

<hr>
<h3>Dependencies:</h3>

Ncurses<br>
[OpenXLSX](https://github.com/troldal/OpenXLSX)

**This has only been tested on Linux systems. Specifically Linux Mint 21.3, Arch Linux, and Raspberry Pi OS 32-bit. It should *in theory* work on MacOS, but I have no way of testing it on Windows.**

<hr>

<h2>Build Instructions</h2>

After cloning the repo:

`cd DundTools/src`<br>
To compile just the TUI application: `make tui`<br>
To compile just the CLI dice roller: `make rolldice`<br>
To compile just the CLI name generator: `make namegen`<br>
To compile everything: `make all` (Just `make` also works if you're lazy)

As long as you have the correct libraries installed, you should be able to compile and run the applications from here with `./tui`, `./rolldice`, and `./namegen`. Specific instructions for running each program will be listed in their respective sections below.

If it doesn't work, I'm afraid I'm not going to be a whole lot of help.

Executables will be found in `DundTools/bin` after compiling.

Also keep in mind that this is *very* much a WIP - expect lots of bugs, errors, crashes, and general not-good times. I'm always happy to receive bug reports.

<hr>

So far I plan on adding the following modules:
(C = Completed, W = WIP, P = Planned)

- Dice Roller (Standalone (C) & TUI (C))
- Character Creator (W)
    - Import/Export characters from .xlsx files (W)
    - Edit existing characters (P)
    - Level up characters (P)
    - (Character sheet is itself a WIP)
- Random Name Generator (Standalone (C) & TUI (W))
- Notes App (P)
- DM Screen (P)
    - Notes (P)
    - Name Generator (P)
    - Beastiary/Stat Blocks (P)
    - Dice Roller (P)
    - Initiative Tracker (P)
    - +/- Counter (P)
- Rules Reference (P)
- Spell List (W)

I haven't decided yet if I'm going to try and make all of the above modules into standalone applications. I've already done the dice roller, but the notes app and name generator sound like good candidates as well.

I'm going to have to look into some legal stuff once I get into the later modules - I don't want Hasbro coming after me for uploading content from paid sourcebooks onto Github.

A GUI version of the app may also be a consideration for the future. But for now, I'm going to stick with CLI/TUI based graphics. I want to be able to use the application on any device - possibly even over SSH.

<hr>

# RollDice
RollDice is a standalone CLI dice rolling simulator.

After cloning the repo, use the following commands:

`cd DundTools/src`<br>
`make rolldice`

The `rolldice` executable will be found in `DundTools/bin`.

Run the program with:

`./rolldice <number of dice> <type of dice> <mod>`

(Use a negative number to subtract the modifier)

<hr>

# NameGen
NameGen is a standalone CLI pseudo-random name generator. It uses a previously mentioned RollDice function to generate a random first and last name (sometimes just a first, which is undefined behavior but I like it so I'm leaving it in) using a list of names (located in `DundTools/files/name_generator/names.txt`).

The list of names was found at [this webpage](https://hanleybrady.com/fantasy-name-bank/).

I've copied 3109 names from that page into names.txt. If my math is correct, that means there are **over 12,000** possible name combinations.

(But don't quote me on that; math was my weakest subject in school)

After cloning the repo, use the following commands to build:

`cd DundTools/src`<br>
`make namegen`

The executable will be found in `DundTools/bin`.

Run the program with:

`./namegen`

A random name will be printed to the console.
