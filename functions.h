#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include "class.h"

int Roll_Dice();
int Move_Player(int roll, int Coord[32][2], int MyIndex, int OtherIndex, int Direction);

#endif // FUNCTIONS_H


