#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include "class.h"
#pragma once
int Roll_Dice();
int Roll_Random(int f, int s);
std::vector<int> Generate_Random_Array(int f, int s);
int Move_Player(int roll, int MyIndex, int OtherIndex, int Napravlenie);
void Take_Coin(Player& Player, int Coin_Index, int newX, int newY, std::vector<Coin>& All_Coins);
int Number_Of_Type(std::string Type);
bool Other_Take_Coins(Player& Player);
void Leave_Coin(Player& Player, const std::string& Type, std::vector<Coin>& All_Coins, int(*Coord)[2], size_t Coord_Rows);
#endif // FUNCTIONS_H