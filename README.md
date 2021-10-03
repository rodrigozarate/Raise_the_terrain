# Raise_the_terrain
Optional project at Holberton School
### Requirements
This program is developed on C
This program is intended to be used on MAC
- GCC
- SDL2
- XCode
### Installation
Open Terminal
On Mac OS X, *run* `brew install sdl2`

#### Compilation
Link with the gcc -m flag to be able to use the math library
`gcc -Wall -Werror -Wextra -pedantic *.c -lm $(sdl2-config --cflags --libs) -o terrain`

## USAGE
`terrain <elevation>`
There's some sample files:
 - elevation_0 Square grid eight by eoght
 - elevation_1 Square grid no elevation
 - elevation_2 Rectangle grid five by eight
 - elevation_3 two by two grid
 - elevation_4 simple square

- You can use your own file of elevations, use a text editor like vi
- Separate the values by spaces.
- Arrange the values in rows and columns to determine the size of the grid.
#### Example
	0 0 0 0
	0 5 2 0
	0 5 2 0
	0 0 0 0

That will create a grid of four by four with a little bump in the middle.


## Tasks
### 0. Basics
Isometric projection

Draw a grid using an isometric projection

#### Use SDL2

### 1. Rotation
Rotate the grid when the user press left or right arrows

