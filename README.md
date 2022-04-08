# Arcade

This project was made in collaboration with `yannick.ferrard@epitech.eu`'s group.

----
## Introduction

Arcade is a .....

To use it, you will need some shared libraries representing your games and displays. Some are already implemented and available in the `lib/` folder.

----
## Core program necessities

Libraries must have a `createInstance` function that creates a new pointer to a variable of the class it implements. This implemented class must inherit from `IDisplayModule` or `IGameModule` for display and game libraries, respectively.

Program must be started with the following command line :
```bash
./arcade lib/my_display_lib.so
```

Then you will be able to see every single lib that is available in the game.

## Our libraries

Here are the libs that we implemented :
```
displays: sdl2, sfml, ncurses
games: nibbler, centipede
```

For more informations see [the docs](https://github.com/EpitechPromo2025/B-OOP-400-LYN-4-1-arcade-marvin.flamand/tree/dev/doc)
