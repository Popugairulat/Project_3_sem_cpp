#ifndef CLASS_H
#define CLASS_H
#include <string> 
#include <SFML/Graphics.hpp>

class Coin
{
private:
    std::string Type;
    int Price;
    int x;
    int y;
public:
    Coin(const std::string& type, int price, int x, int y);
    virtual ~Coin();
    std::string get_Type() const;
    int get_Price() const;
    int get_x() const;
    int get_y() const;
};

class Bunch_Of_Coins
{
private:
    std::vector<Coin*> Coins;
public:
    Bunch_Of_Coins();
    ~Bunch_Of_Coins();
    void Add_Coin(Coin* coin);
    void Print_Coins() const;
};

class Player
{
private:
    int Number_Of_Coins;
    int My_Index;
    std::vector<Coin> My_Coins;
    int Napravlenie;

public:
    Player();
    void Take_Coin(const std::string& type, int price);
    void Leave_Coin(const std::string& type);
    int get_Number_Of_Coins() const;
    int get_Index() const;
};

class Submarine
{
private:
    int Level_Of_Oxygen;

public:
    Submarine();
    void Change_Level(int m);
};

#endif // CLASS_H
