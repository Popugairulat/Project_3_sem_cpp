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
//СОФА НЕПРАВИЛЬНЫЙ ПОРЯДОК ИНИЦИАЛИЗАЦИИ
Player::Player() : Number_Of_Coins(0), My_Index(0), Direction(0) {}



void Player::Take_Coin(const std::string& type, int price)
{
    My_Coins.emplace_back(type, price, 0, 0); // предварительно, нужны координаты деревяшки
    Number_Of_Coins++;
}

void Player::Leave_Coin(const std::string& type)
{
    for (auto it = My_Coins.begin(); it != My_Coins.end(); ++it)
    {
        if (it->get_Type() == type)
        {
            My_Coins.erase(it);
            Number_Of_Coins--;
            return;
        }
    }
}

int Player::get_Number_Of_Coins() const { return Number_Of_Coins; }
int Player::get_Index() const { return My_Index; }


// класс подводная лодка
Submarine::Submarine() : Level_Of_Oxygen(0) {}

void Submarine::Change_Level(int m)
{
    Level_Of_Oxygen -= m;
}

