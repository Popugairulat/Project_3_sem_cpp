#ifndef CLASS_H
#define CLASS_H
#include <string> 
#include <SFML/Graphics.hpp>

class Coin
{
private:
    std::string Type;
    int Price;
public:
    Coin(const std::string& type, int price);
    virtual ~Coin();
    std::string get_Type() const;
    int get_Price() const;
};

class Triangle_Coin : public Coin
{
public:
    Triangle_Coin(int P);
};

class Square_Coin : public Coin
{
public:
    Square_Coin(int P);
};

class Pentagon_Coin : public Coin
{
public:
    Pentagon_Coin(int P);
};

class Hexagon_Coin : public Coin
{
public:
    Hexagon_Coin(int P);
};

class No_Coin : public Coin
{
public:
    No_Coin(int P);
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
