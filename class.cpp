#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "class.h"

using namespace std;

int WIDTH=1080;
int HEIGHT=720;
int x=WIDTH/10, y=/10;
int Coord[32][2]=[[x, y], [2*x, y+10], [3*x, y+20], [4*x, y+30], [5*x, y+40], [6*x, y+50], [7*x, y+40], [8*x, y+50], 
[x, 2*y], [2*x, 2*y+10], [3*x, 2*y+20], [4*x, 2*y+30], [5*x, 2*y+40], [6*x, 2*y+5[7*x0], , 2*y+40], [8*x, 2*y+50],
[x, 3*y], [2*x, 3*y+10], [3*x, 3*y+20], [4*x, 3*y+30], [5*x, 3*y+40], [6*x, 3*y+50], [7*x, 3*y+40], [8*x, 3*y+50],
[x, 4*y], [2*x, 4*y+10], [3*x, 4*y+20], [4*x, 4*y+30], [5*x, 4*y+40], [6*x, 4*y+50], [7*x, 4*y+40], [8*x, 4*y+50]]

// класс Сокровища
class Coin
{
public:
    int Price;
    string Type;
    Coin(string T, int P): Type(T), Price(P) {}

};

class Triangle_Coin : public Coin
{
    Triangle_Coin(int P) : Coin("Triangle", P) {}
};

class Square_Coin : public Coin
{
    Square_Coin(int P) : Coin("Square", P) {}
};

class Pentagon_Coin : public Coin
{
    Pentagon_Coin(int P) : Coin("Pentagon", P) {}
};

class Hexagon_Coin : public Coin
{
    Hexagon_Coin(int P) : Coin("Hexagon", P) {}
};

class No_Coin : public Coin
{
    No_Coin(int P) : Coin("No", P) {}
};

class Bunch_Of_Coins : public Coin
{
private:
    vector<Coin*> Coins;
public:
    Bunch_Of_Coins(const vector<Coin*>) {}

};

// класс Игрок
class Player
{
public:
    int Number_Of_Coins, x, y;
    vector<Coin> My_Coins;
    

    void Take_Coin(const string& Type, int Price)
    {
        Coin.push_back(Coin(Type, Price));
    }

    void Leave_Coin(const string& Type)
    {
        for(auto i = My_Coins.begin(), i!=My_Coins.end(), ++i)
        {
            if(i->Type == Type)
            {
                My_Coins.erase(i);
            }
        }
    }

    void Go(int x, y)
    {

    }
};
