#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include "class.h"

int Roll_Random(int f, int s);
std::vector<int> Generate_Random_Array(int f, int s);
int Move_Player(int roll, int MyIndex, int OtherIndex, int Napravlenie);
void Take_Coin(Player& Player, int Coin_Index, int newX, int newY, std::vector<Coin>& All_Coins);

#endif // FUNCTIONS_H

