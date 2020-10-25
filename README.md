# ASSERT_game1


Draft code of an [R-type game](https://en.wikipedia.org/wiki/R-Type) that displays on the Terminal.
Everything was made from scratch in C and with the ncurses library that handles printing out and stdin character
presses. Due to me not figuring out how to get key up events, this may be because terminals usually do not supporting such events,
multiple keys held seem to block each other off.

It was coded in a way that would in theory allow addition features to be added. New levels are possible, different enemy types, sprite animation, different spaceships, and special abilities. The gameplay below shows one of the enemies with a blinking animation, that has the capacity of firing. The enemy AI displays normal behavior when far away and changes to aggressive chase when near the player. The spaceship can also switch classes, which changes the type of
projectiles it spawns. This is shown midway through though the game play below. The bar near the player is a sprite that follows the player and display the players health.

<br>
<img align="top" height="600" src="https://github.com/ASSERT-game/ASSERT_game1/blob/master/resources/gameplay.gif" />
<br>

To run the game, do ```make all```, then the executable ```./beta_game1``` can be ran.

Controls:
* Movement:
```w a s d```
* Fire:
```(spacebar)```
* Change Class:
```t```
* Gain Health:
```h```

All sprite assets are in the [assets](https://github.com/ASSERT-game/ASSERT_game1/tree/master/srcs/assets) folder in srcs. The player sprite turns out to be
```spaceship_char_sprite = "^\n*EEE\no\n*EEE\nv\n";```

Which when expanded:
```
^
*EEE
o
*EEE
v
```

Colors however are however painfully made using ncurses attributes, and lining each of the attribute spots with the
correct sprite character. A time consuming task.

Usage of [macros](https://github.com/ASSERT-game/ASSERT_game1/blob/master/includes/macros.h), [unions, and structs](https://github.com/ASSERT-game/ASSERT_game1/blob/master/includes/entity.h) allow me to create template code that turns out to be the heart of game loop.
All that is needed then is to specify what those individual functions do, what keys to listen, how to initialize
the beginning state, how to clean up the state when the level is over. Each entity has its own collision function,
update, and is thus responsible for itself. All of this was however coded in C, and quite a while back, but even then
coming back to it to polish some loose ends was both easy and fun.
