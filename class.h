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

    void set_x(int newX);
    void set_y(int newY);

};

class Player
{
private:
    int My_Index;
    std::vector<Coin> My_Coins;
    int Direction;
    int Number_Of_Coins;

public:
    Player();

    void Take_Coin(const Coin& coin);
    void set_Number_Of_Coins(int Plus);

    int get_Number_Of_Coins() const;
    int get_Index() const;
    void set_Index(int Index);
    std::vector<Coin>& get_My_Coins();
    void Leave_Coin(int coinIndex);
    int get_Direction();
    void set_Direction(int new_Direction);
};

#endif // CLASS_H