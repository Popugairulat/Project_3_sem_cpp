#include <SFML/Graphics.hpp>
#include "functions.h"
#include <vector>
#include <string>
#include "class.h"
#include <iostream>
#include <random>


int Roll_Dice() // страшно, наверно можно проще сильно
{
    static std::random_device rd; // Получаем случайное число от устройства
    static std::mt19937 gen(rd()); // Инициализируем генератор с помощью случайного числа
    static std::uniform_int_distribution<> dis(1, 3); // Определяем равномерное распределение от 1 до 3

    // Генерируем и возвращаем сумму двух случайных чисел от 1 до 3
    return dis(gen) + dis(gen);
}

// Ф-ция, возвращающая рандомное число от f до s
int Roll_Random(int f, int s)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(f, s);

    return dis(gen);
}


// Передаем например от 4 до 8 - значение Price у монеток
std::vector<int> Generate_Random_Array(int f, int s)

// Функция, поределяющая новое положение игрока, вызывается как: New_Index=Move_Player(...)

{
    std::vector<int> result;

    for (int i = f; i <= s; i++)
    {
        result.push_back(i);
        result.push_back(i);
    }
    // Перемешиваем массив с помощью алгоритма Фишера-Йетса
    for (int i = result.size() - 1; i > 0; i--)
    {
        int j = Roll_Random(0, i); // Получаем случайный индекс
        std::swap(result[i], result[j]);
    }
    return result;
}


// Функция, определяющая новое положение игрока, вызывается как: Player.set_new_Index=Move_Player(...)
int Move_Player(int roll, int My_Index, int Other_Index, int Direction)
{
    int Final_Index = My_Index; 
    if (Direction < 1) 
    {
        for (int i = 0; i < roll; ++i)
        {
            Final_Index++;
            if (Final_Index == Other_Index)
            {
                Final_Index++;  
            }
        }
    }
    else 
    {
        for (int i = 0; i < roll; ++i)
        {
            Final_Index--;
            if (Final_Index == Other_Index)
            {
                Final_Index--; 
            }
        }
    }

    if (Final_Index < 0)
    {
        Final_Index = 0;
    }
    if (Final_Index > 33)
    {
        Final_Index = 33;
    }

    return Final_Index;
}

// Вызывается так: Take_Coin(My_Player, My_Player.get_Index(), newX, newY, All_Coins)
void Take_Coin(Player& Player, int Coin_Index, int newX, int newY, std::vector<Coin>& All_Coins)
{
    Player.Take_Coin(All_Coins[Coin_Index]); // Добавляем цену и меняем кол-во монет
    All_Coins[Coin_Index].set_x(newX); // Меняем координаты монетки в All_Coins
    All_Coins[Coin_Index].set_y(newY);
}


int Number_Of_Type(std::string Type)
{
    if (Type == "Triangle")
    {
        return 0;
    }
    if (Type == "Invisible")
    {
        return 0;
    }
    if (Type == "Square")
    {
        return 1;
    }
    if (Type == "Pentagon")
    {
        return 2;
    }
    if (Type == "Hexagon")
    {
        return 3;
    }
}
 
bool Other_Take_Coins(Player& Player)
{
    if (Player.get_Index() == 0) 
    { 
        return true; 
    }
    else
    {
        if (Player.get_Number_Of_Coins() <= 2) { return true; }
        else
        {

            if (Player.get_Index() >= 24)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}