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


// Функция, определяющая новое положение игрока, вызывается как: Player.set_New_Index=Move_Player(...)
int Move_Player(int roll, int My_Index, int Other_Index, int Direction) // индекс - это от 1 до 32 - номер позиции игрока, Нулевой индекс - это подводная лодка
{
    if (Direction < 1)
    {
        int Final_Index = My_Index + roll;
        if (Other_Index <= Final_Index && Other_Index >= My_Index)
        {
            if (Final_Index > 32)
            {
                Final_Index = 32;
            }
            return Final_Index + 1; // Т к одну монету он перепрыгнет
        }
        if (Final_Index > 32)
        {
            Final_Index = 32;
        }
        return Final_Index;
    }
    else
    {
        int Final_Index = My_Index - roll;
        if (Other_Index >= Final_Index && Other_Index <= My_Index)
        {
            if (Final_Index < 0)
            {
                Final_Index = 0;
            }
            return Final_Index - 1; // Т к одну монету он перепрыгнет, значит будет на 1 ближе к началу
        }
        if (Final_Index < 0)
        {
            Final_Index = 0;
        }
        return Final_Index;
    }
}

// Вызывается так: Take_Coin(My_Player, My_Player.get_Index(), newX, newY, All_Coins)
void Take_Coin(Player& Player, int Coin_Index, int newX, int newY, std::vector<Coin>& All_Coins)
{
    Player.get_My_Coins().push_back(All_Coins[Coin_Index]); // Копируем монету из allCoins в My_Coins игрока
    Player.Take_Coin(All_Coins[Coin_Index]); // Добавляем цену и меняем кол-во монет
    //Лера тебе сюда
    All_Coins[Coin_Index].set_x(newX); // Меняем координаты монетки в All_Coins
    All_Coins[Coin_Index].set_y(newY);
}