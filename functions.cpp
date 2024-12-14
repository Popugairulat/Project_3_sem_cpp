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

// Функция, поределяющая новое положение игрока, вызывается как: New_Index=Move_Player(...)
int Move_Player(int roll, int My_Index, int Other_Index, int Napravlenie) // индекс - это от 1 до 32 - номер позиции игрока, Нулевой индекс - это подводная лодка
{
    if (Napravlenie < 1)
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
            return Final_Index - 1; // Т к одну монету он перепрыгнет, значит будет на 1 ближе к концу
        }
        if (Final_Index < 0)
        {
            Final_Index = 0;
        }
        return Final_Index;
    }
}
