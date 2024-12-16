#include <iostream>
#include <SFML/Graphics.hpp>
#include "visual.h"
#include "buttons.h"
#include "functions.h"
#include "class.h"
#include <filesystem>


int main() 
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    int WIDTH = static_cast<const int>(desktop.width * 0.9);
    int HEIGHT = (WIDTH * 943-WIDTH*943%1880)/1880;
    //int WIDTH = 1880, HEIGHT = 943;
    int x = WIDTH / 7;
    int y = HEIGHT / 7;
    int x1 = WIDTH / 25;
    int y1 = HEIGHT / 10;
    int Coord[32][2] = { {x, y},{2 * x, y + 10},{3 * x, y + 20}, {4 * x, y + 30},{5 * x, y + 40},{6 * x, y + 50},{7 * x, y + 60},{8 * x, y + 70},
    {8 * x, 2 * y},{7 * x, 2 * y + 10},{6 * x, 2 * y + 20},{5 * x, 2 * y + 30},{4 * x, 2 * y + 40},{3 * x, 2 * y + 50},{2 * x, 2 * y + 60}, {x, 2 * y + 70},
    {x, 3 * y},{2 * x, 3 * y + 10},{3 * x, 3 * y + 20}, {4 * x, 3 * y + 30},{5 * x, 3 * y + 40},{6 * x, 3 * y + 50},{7 * x, 3 * y + 60},{8 * x, 3 * y + 70},
    {8 * x, 4 * y},{7 * x, 4 * y + 10},{6 * x, 4 * y + 20},{5 * x, 4 * y + 30},{4 * x, 4 * y + 40},{3 * x, 4 * y + 50},{2 * x, 4 * y + 60}, {x, 4 * y + 70} };
    
    // Заведем переменные
    int My_Coins_Coord[4][2] = { {x1, y1}, {x1, 2 * y1}, {x1, 3 * y1}, {x1, 4 * y1} };
    int Other_Coins_Coord[4][2] = { {x1, 6 * y1}, { x1, 7 * y1}, {x1, 8 * y1}, {x1, 9 * y1} };

    std::vector<Coin> My_Coins;
    std::vector<Coin> Other_Coins;


    std::vector<int> Triangle = Generate_Random_Array(0, 3);
    std::vector<int> Square = Generate_Random_Array(4, 7);
    std::vector<int> Pentagon = Generate_Random_Array(8, 11);
    std::vector<int> Hexagon = Generate_Random_Array(12, 15);



    std::vector<Coin> All_Coins;
    for (int i = 0; i < 8; i++)
    {

        All_Coins.emplace_back("Triangle", Triangle[i], Coord[i][0], Coord[i][1]);
    }
    for (int i = 8; i < 16; i++)
    {
        All_Coins.emplace_back("Square", Square[i-8], Coord[i][0], Coord[i][1]);
    }
    for (int i = 16; i < 24; i++)
    {
        All_Coins.emplace_back("Pentagon", Pentagon[i-16], Coord[i][0], Coord[i][1]);
    }
    for (int i = 24; i < 32; i++)
    {
        All_Coins.emplace_back("Hexagon", Hexagon[i-24], Coord[i][0], Coord[i][1]);

    }

    Player My_Player;
    Player Other_Player;

    Submarine Submarine;


    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "XY");
    GameState currentState = GameState::Start;
    // ЗАГРУЗКА ТЕКСТУР
    std::filesystem::path folder = "Pictures";
    TextureManager textureManager;
    textureManager.loadTexture("Start new game", (folder / "base_for_buttons.png").string());
    textureManager.loadTexture("Continue the game", (folder / "base_for_buttons.png").string());
    textureManager.loadTexture("Settings", (folder / "button_menu.png").string());
    textureManager.loadTexture("Close", (folder / "button_close.png").string());
    textureManager.loadTexture("Stop", (folder / "button_stop.png").string());
    textureManager.loadTexture("Back", (folder / "button_back.png").string());
    textureManager.loadTexture("Question", (folder / "button_question.png").string());

    textureManager.loadTexture("Triangle", (folder/"coin_3.png").string());
    textureManager.loadTexture("Square", (folder /"coin_4.png").string());
    textureManager.loadTexture("Pentagon", (folder/"coin_5.png").string());
    textureManager.loadTexture("Hexagon", (folder/"coin_6.png").string());

    textureManager.loadTexture("Player", (folder / "button_back.png").string());
    textureManager.loadTexture("f1", (folder / "f1.png").string());
    textureManager.loadTexture("f2", (folder / "f2.png").string());
    textureManager.loadTexture("f3", (folder / "f3.png").string());
    textureManager.loadTexture("f4", (folder / "f4.png").string());
    textureManager.loadTexture("f5", (folder / "f5.png").string());
    textureManager.loadTexture("f6", (folder / "f6.png").string());
    textureManager.loadTexture("f7", (folder / "f7.png").string());
    textureManager.loadTexture("f8", (folder / "f8.png").string());
    textureManager.loadTexture("f9", (folder / "f9.png").string());

    std::vector<std::string> textureNames = {"f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "f9"};
    Animation animation(textureManager, textureNames, 0.1f);



    //массивы с кнопками
    std::vector<Button> buttons_start;
    buttons_start.emplace_back(WIDTH / 2 - WIDTH / 8, HEIGHT / 2 + HEIGHT / 14, WIDTH / 4, HEIGHT / 7, "Start new game");
    buttons_start.emplace_back(WIDTH / 2 - WIDTH / 8, HEIGHT / 2 + 3 * HEIGHT / 14, WIDTH / 4, HEIGHT / 7, "Continue the game");
    buttons_start.emplace_back(WIDTH - WIDTH / 20 - WIDTH / 200, WIDTH / 200, WIDTH / 20, WIDTH / 20, "Settings");
    buttons_start.emplace_back(WIDTH - 2 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Question");
    buttons_start.emplace_back(WIDTH - 3 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Back");

    std::vector<Button> buttons_settings;
    buttons_settings.emplace_back(WIDTH / 2 - 100.0, 150.0, 200, 50, "Back");
    buttons_settings.emplace_back(WIDTH / 2 - 100.0, 250.0, 200, 50, "Back");
    buttons_settings.emplace_back(WIDTH / 2 - 100.0, 350.0, 200, 50, "Back");
    buttons_settings.emplace_back(WIDTH / 2 - 100.0, 450.0, 200, 50, "Back");
    buttons_settings.emplace_back(WIDTH / 2 - 100.0, 550.0, 200, 50, "Back");
    buttons_settings.emplace_back(WIDTH - 100.0, 0.0, 100, 100, "Back");

    std::vector<Button> buttons_game;
    buttons_game.emplace_back(WIDTH - WIDTH / 20 - WIDTH / 200, WIDTH / 200, WIDTH / 20, WIDTH / 20, "Settings");
    buttons_game.emplace_back(WIDTH - 2 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Question");
    buttons_game.emplace_back(WIDTH - 3 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Back");
    buttons_game.emplace_back(WIDTH/2 - WIDTH / 40, HEIGHT*3 / 4, WIDTH / 20, WIDTH / 20, "Back");
    buttons_game.emplace_back(WIDTH/2 + WIDTH / 40, HEIGHT*3 / 4, WIDTH / 20, WIDTH / 20, "Forward");

    while (window.isOpen())
    {
        sf::Event event;
 
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Добавляем новый Ripple на позицию курсора
                    ripples.emplace_back(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
            }
        }

        // Отрисовка в зависимости от текущего состояния
        if (currentState == GameState::Start)
        {
            renderStart(window);
            //std::filesystem::path folder = "Pictures";
            //drawImage(window, "Triangle", 100.0, 100.0, 50.0, 50.0, textureManager);
            for (auto &button : buttons_start)
            {
                button.draw_button(window, textureManager);
                button.get_pressed(event);
            }
            if (buttons_start[0].pressed)
            {
                if (currentState == GameState::Start)
                {
                    currentState = GameState::Game;
                    buttons_start[0].pressed = false;
                }
            }
            if (buttons_start[1].pressed)
            {
                if (currentState == GameState::Start)
                {
                    currentState = GameState::Game;
                    buttons_start[1].pressed = false;
                }
            }
            if (buttons_start[2].pressed)
            {
                if (currentState == GameState::Start)
                {
                    currentState = GameState::Settings;
                    buttons_start[2].pressed = false;
                }
            }
            if (buttons_start[3].pressed)
            {
                if (currentState == GameState::Start)
                {
                    currentState = GameState::Game;
                    buttons_start[3].pressed = false;
                }
            }
            if (buttons_start[4].pressed)
            {
                if (currentState == GameState::Start)
                {
                    currentState = GameState::Settings;
                    buttons_start[4].pressed = false;
                }
            }
        }

        else if (currentState == GameState::Settings) {
            renderGame(window);

            for (auto &button : buttons_settings)
            {
                button.draw_button(window, textureManager);
                button.get_pressed(event);
            }
            if (buttons_settings[0].pressed)
            {
                if (currentState == GameState::Settings)
                {
                    currentState = GameState::Game;
                    buttons_settings[0].pressed = false;
                }
            }
            if (buttons_settings[1].pressed)
            {
                if (currentState == GameState::Settings)
                {
                    currentState = GameState::Game;
                    buttons_settings[1].pressed = false;
                }
            }
            if (buttons_settings[2].pressed)
            {
                if (currentState == GameState::Settings)
                {
                    currentState = GameState::Start;
                    buttons_settings[2].pressed = false;
                }
            }
            if (buttons_settings[3].pressed)
            {
                if (currentState == GameState::Settings)
                {
                    currentState = GameState::Level;
                    buttons_settings[3].pressed = false;
                }
            }
            if (buttons_settings[4].pressed)
            {
                if (currentState == GameState::Settings)
                {
                    currentState = GameState::Rating;
                    buttons_settings[4].pressed = false;
                }
            }
            if (buttons_settings[5].pressed)
            {
                if (currentState == GameState::Settings)
                {
                    currentState = GameState::Game;
                    buttons_settings[5].pressed = false;
                }
            }
            
        }

        else if (currentState == GameState::Level)
        {
            renderGame(window);
        }

        else if (currentState == GameState::Game)
        {
            renderGame(window);
            for (int i = 0; i < 32; i++)
            {

                drawImage(window, All_Coins[i].get_Type(), All_Coins[i].get_x(), All_Coins[i].get_y(), x / 2, x / 2, textureManager);
            }
            drawImage(window, "Player", Coord[My_Player.get_Index()][0], Coord[My_Player.get_Index()][1], x / 2, x / 2, textureManager);
            drawImage(window, "Player", Coord[Other_Player.get_Index()][0] + x / 10, Coord[Other_Player.get_Index()][0], 100, 100, textureManager);
            for (auto& button : buttons_game) {
                button.draw_button(window, textureManager);
                button.get_pressed(event);
            }
            
            if (buttons_game[0].pressed)
            {
                if (currentState == GameState::Game)
                {
                    currentState = GameState::Settings;
                    buttons_game[0].pressed = false;
                }
            }
            if (buttons_game[1].pressed)
            {
                if (currentState == GameState::Game)
                {
                    currentState = GameState::Settings;
                    buttons_game[1].pressed = false;
                }
            }
            if (buttons_game[2].pressed)
            {
                if (currentState == GameState::Game)
                {
                    currentState = GameState::Start;
                    buttons_game[2].pressed = false;
                }
            }
            if (buttons_game[3].pressed)
            {
                if (currentState == GameState::Game)
                {
                    My_Player.Direction=1;   
                    buttons_game[3].pressed = false;
                }
            }
            if (buttons_game[4].pressed)
            {
                if (currentState == GameState::Game)
                {
                    //вызов функции движения игрока
                }
            }
            
        
        }

        else if (currentState == GameState::Final)
        {
            renderGame(window);
        }
        else if (currentState == GameState::Rating)
        {
            renderGame(window);
        }
         
        animation.update(200.0f); // Примерное время между кадрами (60 FPS
        animation.draw(window, 100, 100); // Отображаем анимацию в координатах (100, 100)
        
        for (auto& ripple : ripples) {
            ripple.update();
        }

        // Удаляем завершенные ряды
        ripples.erase(std::remove_if(ripples.begin(), ripples.end(),
                                     [](const Ripple &ripple)
                                     { return ripple.isFinished(); }),
                      ripples.end());
        // Отрисовка
        for (auto &ripple : ripples)
        {
            ripple.draw(window);
        }

        window.display();
    }

    return 0;
}

