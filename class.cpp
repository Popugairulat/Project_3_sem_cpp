#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "class.h"
#include <iostream>

using namespace std;


// класс Сокровища
Coin::Coin(const std::string& type, int price, int x, int y) : Type(type), Price(price), x(x), y(y) {}
Coin::~Coin() {}
std::string Coin::get_Type() const { return Type; }
int Coin::get_Price() const { return Price; }
int Coin::get_x() const { return x; }
int Coin::get_y() const { return y; }
void Coin::set_x(int newX) { x = newX; }
void Coin::set_y(int newY) { y = newY; }

Bunch_Of_Coins::Bunch_Of_Coins() {}
Bunch_Of_Coins::~Bunch_Of_Coins()
{
    for (Coin* coin : Coins)
    {
        delete coin;
    }
    Coins.clear();
}
void Bunch_Of_Coins::Add_Coin(Coin* coin)
{
    Coins.push_back(coin);
}
void Bunch_Of_Coins::Print_Coins() const
{
    for (const Coin* coin : Coins)
    {
        std::cout << "Type: " << coin->get_Type() << ", Price: " << coin->get_Price() << std::endl;
    }
}

Player::Player() : My_Index(0), Direction(0), Number_Of_Coins(0) {}

void Player::set_Index(int Index) { My_Index = Index; }

std::vector<Coin>& Player::get_My_Coins() { return My_Coins; }

int Player::get_Number_Of_Coins() const { return Number_Of_Coins; }
void Player::set_Number_Of_Coins(int Plus) { Number_Of_Coins += Plus; }
int Player::get_Index() const { return My_Index; }


void Player::Take_Coin(const Coin& Coin)
{
    My_Coins.emplace_back(Coin.get_Type(), Coin.get_Price(), Coin.get_x(), Coin.get_y());
    Number_Of_Coins++;
}

void Player::Leave_Coin(int Сoin_Index)
{
    My_Coins.erase(My_Coins.begin() + Сoin_Index);
    Number_Of_Coins--;
}



// класс подводная лодка
Submarine::Submarine() : Level_Of_Oxygen(0) {}

void Submarine::Change_Level(int m)
{
    Level_Of_Oxygen -= m;
}

