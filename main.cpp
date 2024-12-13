#include <iostream>
#include <SFML/Graphics.hpp>
#include "visual.h"
#include "buttons.h"
#include "functions.h"
#include "class.h"
#include <filesystem>

int main() {

    std::vector<Ripple> ripples;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    int WIDTH = static_cast<const int>(desktop.width * 0.9);
    const int HEIGHT = (WIDTH * 943 - WIDTH * 943 % 1880) / 1880;
    //int WIDTH = 1880, HEIGHT = 943;
   
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
    textureManager.loadTexture("Triangle", (folder / "Coin_3.png").string());
    textureManager.loadTexture("Square", (folder / "Coin_4.png").string());
    textureManager.loadTexture("Pentagon", (folder / "Coin_5.png").string());
    textureManager.loadTexture("Hexagon", (folder / "Coin_6.png").string());

    textureManager.loadTexture("Player", (folder / "button_back.png").string());



    //массивы с кнопками
    std::vector<Button> buttons_start;
    buttons_start.emplace_back( WIDTH/2- WIDTH / 8, HEIGHT/2+ HEIGHT / 14, WIDTH/4, HEIGHT/7, "Start new game");
    buttons_start.emplace_back(WIDTH / 2 - WIDTH / 8, HEIGHT / 2 +3* HEIGHT / 14, WIDTH / 4, HEIGHT / 7, "Continue the game");
    buttons_start.emplace_back(WIDTH - WIDTH / 20 - WIDTH / 200, WIDTH / 200, WIDTH / 20, WIDTH / 20, "Settings");
    buttons_start.emplace_back(WIDTH - 2 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Question");
    buttons_start.emplace_back(WIDTH - 3 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Back");
  
    int x = WIDTH / 7;
    int y = HEIGHT / 7;
    int Coord[32][2] = { {x, y},{2 * x, y + 10},{3 * x, y + 20}, {4 * x, y + 30},{5 * x, y + 40},{6 * x, y + 50},{7 * x, y + 60},{8 * x, y + 70},
    {8 * x, 2 * y},{7 * x, 2 * y + 10},{6 * x, 2 * y + 20},{5 * x, 2 * y + 30},{4 * x, 2 * y + 40},{3 * x, 2 * y + 50},{2 * x, 2 * y + 60}, {x, 2 * y + 70},
    {x, 3 * y},{2 * x, 3 * y + 10},{3 * x, 3 * y + 20}, {4 * x, 3 * y + 30},{5 * x, 3 * y + 40},{6 * x, 3 * y + 50},{7 * x, 3 * y + 60},{8 * x, 3 * y + 70},
    {8 * x, 4 * y},{7 * x, 4 * y + 10},{6 * x, 4 * y + 20},{5 * x, 4 * y + 30},{4 * x, 4 * y + 40},{3 * x, 4 * y + 50},{2 * x, 4 * y + 60}, {x, 4 * y + 70} };

    // Заведем переменные

    std::vector<Coin> All_Coins;
    for (int i = 0; i < 8; i++)
    {
        int res = i / 2;
        All_Coins.emplace_back("Triangle", res, Coord[i][0], Coord[i][1]);
    }
    for (int i = 8; i < 16; i++)
    {
        int res = i / 2;
        All_Coins.emplace_back("Square", res, Coord[i][0], Coord[i][1]);
    }
    for (int i = 16; i < 24; i++)
    {
        int res = i / 2;
        All_Coins.emplace_back("Pentagon", res, Coord[i][0], Coord[i][1]);
    }
    for (int i = 24; i < 32; i++)
    {
        int res = i / 2;
        All_Coins.emplace_back("Hexagon", res, Coord[i][0], Coord[i][1]);
    }

    Player My_Player;
    Player Other_Player;

    Submarine Submarine;

    std::vector<Button> buttons_settings;
    buttons_settings.emplace_back(WIDTH / 2 - 100.0, 150.0, 200, 50, "Back");
    buttons_settings.emplace_back( WIDTH/2-100.0, 250.0, 200, 50, "Back");
    buttons_settings.emplace_back( WIDTH/2-100.0, 350.0, 200, 50, "Back");
    buttons_settings.emplace_back( WIDTH/2-100.0, 450.0, 200, 50, "Back");
    buttons_settings.emplace_back( WIDTH/2-100.0, 550.0, 200, 50, "Back");
    buttons_settings.emplace_back( WIDTH-100.0, 0.0, 100, 100, "Back");

    std::vector<Button> buttons_game;
    buttons_game.emplace_back(WIDTH - WIDTH / 20 - WIDTH / 200, WIDTH / 200, WIDTH / 20, WIDTH / 20, "Settings");
    buttons_game.emplace_back(WIDTH - 2 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Question");
    buttons_game.emplace_back(WIDTH - 3 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Back");

    while (window.isOpen()) {
        sf::Event event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {}
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();

            }    
        }
       
        // Отрисовка в зависимости от текущего состояния
        if (currentState == GameState::Start) {
            renderStart(window);

            for (auto& button : buttons_start) {
            button.draw_button(window, textureManager);
            button.get_pressed(event);
        }
            if(buttons_start[0].pressed){
                if(currentState == GameState::Start){
                    currentState = GameState::Game;
                    buttons_start[0].pressed = false;
                }
            }
            if(buttons_start[1].pressed){
                if(currentState == GameState::Start){
                    currentState = GameState::Game;
                    buttons_start[1].pressed = false;
                }
            }
            if(buttons_start[2].pressed){
                if(currentState == GameState::Start){
                    currentState = GameState::Settings;
                    buttons_start[2].pressed = false;
                }
            }
            if (buttons_start[3].pressed) {
                if (currentState == GameState::Start) {
                    currentState = GameState::Game;
                    buttons_start[3].pressed = false;
                }
            }
            if (buttons_start[4].pressed) {
                if (currentState == GameState::Start) {
                    currentState = GameState::Settings;
                    buttons_start[4].pressed = false;

            }  
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Добавляем новый Ripple на позицию курсора
                    ripples.emplace_back(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

                }
            }

        }


        else if (currentState == GameState::Settings) {

            renderGame(window);

            for (auto& button : buttons_settings) {
            button.draw_button(window, textureManager);
            button.get_pressed(event);
        }
            if(buttons_settings[0].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Game;
                    buttons_settings[0].pressed = false;
                }
            }
            if(buttons_settings[1].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Game;
                    buttons_settings[1].pressed = false;
                }
            }
            if(buttons_settings[2].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Start;
                    buttons_settings[2].pressed = false;
                }
            }
            if(buttons_settings[3].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Level;
                    buttons_settings[3].pressed = false;
                }
            }
            if(buttons_settings[4].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Rating;
                    buttons_settings[4].pressed = false;
                }
            }
            if(buttons_settings[5].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Game;
                    buttons_settings[5].pressed = false;
                }
            }
        }  

        else if (currentState == GameState::Level) {
            renderGame(window);
        }

        else if (currentState == GameState::Game) {
            renderGame(window);
            for (int i = 0; i < 32; i++)
            {
                drawImage(window, All_Coins[i].get_Type(), All_Coins[i].get_x(), All_Coins[i].get_y(), x/2, x/2, textureManager);
            }
            drawImage(window, "Player", Coord[My_Player.get_Index()][0], Coord[My_Player.get_Index()][1], x/2, x/2, textureManager);
            drawImage(window, "Player", Coord[Other_Player.get_Index()][0] + x/10, Coord[Other_Player.get_Index()][0], 100, 100, textureManager);

            for (auto& button : buttons_game) {
                button.draw_button(window, textureManager);
                button.get_pressed(event);
            }
        }

        else if (currentState == GameState::Final) {
            renderGame(window);
        }
        else if (currentState == GameState::Rating) {
            renderGame(window);
        }

        for (auto& ripple : ripples) {
            ripple.update();
        }
        // Удаляем завершенные ряды
        ripples.erase(std::remove_if(ripples.begin(), ripples.end(),
            [](const Ripple& ripple) { return ripple.isFinished(); }), ripples.end());
        // Отрисовка
        for (auto& ripple : ripples) {
            ripple.draw(window);
        }

        window.display();
     }


    return 0;
}

