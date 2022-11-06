# Application of polish notation for whatever your soul may desire

This is a work in progress project.
Main idea goes as follows: a user inputs a formula, and we have to make a graph of it (tbd) and calculate it with the use of postfix notation.

## General structure
Formula is first read as a string.
It is first prepared (by removing all spaces and adding brackets in the beginning and in the end for simplification of future validation). 
Then it is transformed into a list of structures (all operations and structures themselves are described in structures.c and structures.h).
This list is then going on to be validated (which means checking the formula is valid by good old army of switches).
After that go the shunting yard and the calculation. Easy, right???

