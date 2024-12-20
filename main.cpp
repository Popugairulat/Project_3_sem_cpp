#include <iostream>
#include <SFML/Graphics.hpp>
#include "visual.h"
#include "buttons.h"
#include "functions.h"
#include "class.h"
#include <filesystem>
//ввела Софа
#include <chrono>
#include <thread>

int main()
{
    TextRenderer textRenderer("Roboto-Black.ttf"); // Убедитесь, что файл шрифта доступен

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    int WIDTH = static_cast<const int>(desktop.width * 0.9);
    int HEIGHT = (WIDTH * 943 - WIDTH * 943 % 1880) / 1880;
    //int WIDTH = 1880, HEIGHT = 943;
    int x = WIDTH / 7;
    int y = HEIGHT / 7;
    int x1 = WIDTH / 25;
    int y1 = HEIGHT / 10;
    int i = 100;

    int s = WIDTH / 110;
    int Coord[32][2] = { {WIDTH / 3.5, 8 * s},{WIDTH / 3.5 + 9 * s, 9 * s},{WIDTH / 3.5 + 18 * s, 10 * s}, {WIDTH / 3.5 + 27 * s, 11 * s},{WIDTH / 3.5 + 36 * s, 12 * s},
        {WIDTH / 3.5 + 45 * s, 13 * s},{WIDTH / 3.5 + 53 * s, 18 * s},{WIDTH / 3.5 + 48 * s, 25 * s},{WIDTH / 3.5 + 40 * s, 22 * s}, {WIDTH / 3.5 + 31 * s, 21 * s},{WIDTH / 3.5 + 22 * s, 20 * s},
        {WIDTH / 3.5 + 13 * s, 19 * s},{WIDTH / 3.5 + 4 * s, 18 * s},{WIDTH / 3.5 - 5 * s, 17 * s},{WIDTH / 3.5 - 12 * s,  22 * s},{WIDTH / 3.5 - 5 * s,  27 * s}, {WIDTH / 3.5 + 4 * s,  28 * s},
{WIDTH / 3.5 + 13 * s,  29 * s},{WIDTH / 3.5 + 22 * s,  30 * s},{WIDTH / 3.5 + 31 * s,  31 * s}, {WIDTH / 3.5 + 40 * s,  32 * s},{WIDTH / 3.5 + 48 * s,  36 * s},{WIDTH / 3.5 + 43 * s,  43 * s},{WIDTH / 3.5 + 34 * s,  42 * s},{WIDTH / 3.5 + 25 * s,  41 * s},
{WIDTH / 3.5 + 16 * s,  40 * s},{WIDTH / 3.5 + 7 * s,  39 * s},{WIDTH / 3.5 - 2 * s,  38 * s},{WIDTH / 3.5 - 9 * s,  44 * s},{WIDTH / 3.5 ,  47 * s}, {WIDTH / 3.5 + 9 * s ,  48 * s}, {WIDTH / 3.5 + 18 * s,  49 * s} };
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
        All_Coins.emplace_back("Square", Square[i - 8], Coord[i][0], Coord[i][1]);
    }
    for (int i = 16; i < 24; i++)
    {
        All_Coins.emplace_back("Pentagon", Pentagon[i - 16], Coord[i][0], Coord[i][1]);
    }
    for (int i = 24; i < 32; i++)
    {
        All_Coins.emplace_back("Hexagon", Hexagon[i - 24], Coord[i][0], Coord[i][1]);

    }

    for (int i = 0; i < 32; i++)
    {
        std::cout<<All_Coins[i].get_Type();
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

    textureManager.loadTexture("Game", (folder / "game.png").string());
    textureManager.loadTexture("Game", (folder / "game.png").string());


    textureManager.loadTexture("Triangle", (folder / "coin_3.png").string());
    textureManager.loadTexture("Square", (folder / "coin_4.png").string());
    textureManager.loadTexture("Pentagon", (folder / "coin_5.png").string());
    textureManager.loadTexture("Hexagon", (folder / "coin_6.png").string());
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
    textureManager.loadTexture("f11", (folder / "f11.png").string());
    textureManager.loadTexture("f12", (folder / "f12.png").string());
    textureManager.loadTexture("f13", (folder / "f13.png").string());
    textureManager.loadTexture("f14", (folder / "f14.png").string());
    textureManager.loadTexture("f15", (folder / "f15.png").string());
    textureManager.loadTexture("f16", (folder / "f16.png").string());
    textureManager.loadTexture("f17", (folder / "f17.png").string());
    textureManager.loadTexture("f18", (folder / "f18.png").string());
    textureManager.loadTexture("f10", (folder / "f10.png").string());
    std::vector<std::string> fish_go = { "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15", "f16", "f17", "f18" };
    Animation fish(textureManager, fish_go, 0.1f);


    textureManager.loadTexture("c1", (folder / "c1.png").string());
    textureManager.loadTexture("c2", (folder / "c2.png").string());
    textureManager.loadTexture("c3", (folder / "c3.png").string());
    textureManager.loadTexture("c4", (folder / "c4.png").string());
    textureManager.loadTexture("c5", (folder / "c5.png").string());
    textureManager.loadTexture("c6", (folder / "c6.png").string());
    textureManager.loadTexture("c7", (folder / "c7.png").string());
    textureManager.loadTexture("c8", (folder / "c8.png").string());
    textureManager.loadTexture("c9", (folder / "c9.png").string());
    textureManager.loadTexture("c11", (folder / "c11.png").string());
    textureManager.loadTexture("c12", (folder / "c12.png").string());
    textureManager.loadTexture("c13", (folder / "c13.png").string());
    textureManager.loadTexture("c14", (folder / "c14.png").string());
    textureManager.loadTexture("c15", (folder / "c15.png").string());
    textureManager.loadTexture("c16", (folder / "c16.png").string());
    textureManager.loadTexture("c17", (folder / "c17.png").string());
    textureManager.loadTexture("c18", (folder / "c18.png").string());
    textureManager.loadTexture("c10", (folder / "c10.png").string());
    std::vector<std::string> crocodile_go = { "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9", "c10", "c11", "c12", "c13", "c14", "c15", "c16", "c17", "c18"};
    Animation crocodile(textureManager, crocodile_go, 0.1f);



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
    buttons_game.emplace_back(WIDTH / 2 - WIDTH / 40, HEIGHT * 3 / 4, WIDTH / 20, WIDTH / 20, "Back");
    buttons_game.emplace_back(WIDTH / 2 + WIDTH / 40, HEIGHT * 3 / 4, WIDTH / 20, WIDTH / 20, "Back");
    buttons_game.emplace_back(WIDTH * 4 / 5, HEIGHT * 3 / 4, WIDTH / 20, WIDTH / 20, "Back");

    std::vector<Button> buttons_level;
    buttons_level.emplace_back(WIDTH - WIDTH / 20 - WIDTH / 200, WIDTH / 200, WIDTH / 20, WIDTH / 20, "Settings");
    buttons_level.emplace_back(WIDTH - 2 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Question");
    buttons_level.emplace_back(WIDTH - 3 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Back");
    buttons_level.emplace_back(WIDTH / 2 - WIDTH / 20, HEIGHT * 3 / 4, WIDTH / 20, WIDTH / 20, "Back");
    buttons_level.emplace_back(WIDTH / 2 + WIDTH / 20, HEIGHT * 3 / 4, WIDTH / 20, WIDTH / 20, "Back");

    Button button_rules=Button(WIDTH - WIDTH / 20 - WIDTH / 200, WIDTH / 200, WIDTH / 20, WIDTH / 20, "Back");
    int new_my_player_index=My_Player.get_Index(), new_other_player_index=Other_Player.get_Index();
    int step = 1, step_c=1;
    int my_player_x = Coord[My_Player.get_Index()][0];
    int my_player_y = Coord[My_Player.get_Index()][1];
    int other_player_x = Coord[Other_Player.get_Index()][0];
    int other_player_y = Coord[Other_Player.get_Index()][1];
    std::vector<Ripple> ripples;

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
                    ripples.emplace_back(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

                    // Добавляем новый Ripple на позицию курсора
                }
            }
        }
        // Отрисовка в зависимости от текущего состояния
        if (currentState == GameState::Start)
        {
            renderStart(window);
            //std::filesystem::path folder = "Pictures";
            //drawImage(window, "Triangle", 100.0, 100.0, 50.0, 50.0, textureManager);
            for (auto& button : buttons_start)
            {
                button.draw_button(window, textureManager);
                button.get_pressed(event);
            }
            if (buttons_start[0].pressed)
            {
                    currentState = GameState::Level;
                    buttons_start[0].pressed = false;
            }
            if (buttons_start[1].pressed)
            {
                    currentState = GameState::Game;
                    buttons_start[1].pressed = false;
            }
            if (buttons_start[2].pressed)
            {
                    currentState = GameState::Settings;
                    buttons_start[2].pressed = false;
            }
            if (buttons_start[3].pressed)
            {
                    buttons_start[3].pressed = false;
                }
            if (buttons_start[4].pressed)
            {
                    currentState = GameState::Start;
                    buttons_start[4].pressed = false;

            }
        }

        else if (currentState == GameState::Settings) {
            renderGame(window);

            for (auto& button : buttons_settings)
            {
                button.draw_button(window, textureManager);
                button.get_pressed(event);
            }
            if (buttons_settings[0].pressed)
            {
                    currentState = GameState::Game;
                    buttons_settings[0].pressed = false;
            }
            if (buttons_settings[1].pressed)
            {
                    currentState = GameState::Game;
                    buttons_settings[1].pressed = false;
            }
            if (buttons_settings[2].pressed)
            {
                    currentState = GameState::Start;
                    buttons_settings[2].pressed = false;
            }
            if (buttons_settings[3].pressed)
            {
                    currentState = GameState::Level;
                    buttons_settings[3].pressed = false;
            }
            if (buttons_settings[4].pressed)
            {
                    currentState = GameState::Rating;
                    buttons_settings[4].pressed = false;
            }
            if (buttons_settings[5].pressed)
            {
                    currentState = GameState::Game;
                    buttons_settings[5].pressed = false;
            }

        }

        else if (currentState == GameState::Level)
        {
            renderGame(window);
            for (auto& button : buttons_level) {
                button.draw_button(window, textureManager);
                button.get_pressed(event);
            }
            if (buttons_level[0].pressed)
            {
                currentState = GameState::Settings;
                buttons_level[0].pressed = false;
            }
            if (buttons_level[1].pressed)
            {
                
                buttons_level[1].pressed = false;
            }

            if (buttons_level[2].pressed)
            {
                currentState = GameState::Start;
                buttons_level[2].pressed = false;
            }
            if (buttons_level[3].pressed)
            {
                currentState = GameState::Game;
                buttons_level[3].pressed = false;
            }
            if (buttons_level[4].pressed)
            {
                currentState = GameState::Game;
                buttons_level[4].pressed = false;
            }

        }

        else if (currentState == GameState::Game)
        {
            renderGame(window);
            for (int i = 0; i < 32; i++)
            {
                drawImage(window, All_Coins[i].get_Type(), All_Coins[i].get_x(), All_Coins[i].get_y(), x / 2, x / 2, textureManager);
            }
            
            for (auto& button : buttons_game) {
                button.draw_button(window, textureManager);
                button.get_pressed(event);
            }
            if (buttons_game[0].pressed)
            {
                    currentState = GameState::Settings;
                    buttons_game[0].pressed = false;
            }
            if (buttons_game[1].pressed)
            {
                    currentState = GameState::Settings;
                    buttons_game[1].pressed = false;
            }
            if (buttons_game[2].pressed)
            {
                    currentState = GameState::Start;
                    buttons_game[2].pressed = false;
            }
            if (buttons_game[3].pressed)
            {
                    My_Player.set_Direction(1);
                    buttons_game[3].pressed = false;
            }
            if (buttons_game[4].pressed)
            {
                    // анимация Штурвала Лера
                    int roll_1 = Roll_Random(1, 3) + Roll_Random(1, 3);
                    new_my_player_index = Move_Player(roll_1, My_Player.get_Index(), Other_Player.get_Index(), My_Player.get_Direction());
                    int roll_2 = Roll_Random(1, 3) + Roll_Random(1, 3);
                    new_other_player_index = Move_Player(roll_2, Other_Player.get_Index(), My_Player.get_Index(), Other_Player.get_Direction());

                    // берет монетку
                    
                    buttons_game[4].pressed = false;
            }
            if (buttons_game[5].pressed)
            {
                //БЕРЕМ МОНЕТКУ
                int Type = Number_Of_Type(All_Coins[My_Player.get_Index()].get_Type());
                Take_Coin(My_Player, My_Player.get_Index(), My_Coins_Coord[Type][0], My_Coins_Coord[Type][1], All_Coins);
                buttons_game[5].pressed = false;
            }
            if (My_Player.get_Index() < new_my_player_index) {
                fish.setAnimating(true);
                int l = (Coord[My_Player.get_Index() + 1][0] - Coord[My_Player.get_Index()][0]) / 10;
                int h = (Coord[My_Player.get_Index() + 1][1] - Coord[My_Player.get_Index()][1]) / 10;
                if (step <10) {
                    my_player_x +=  l;
                    my_player_y += h;
                    step += 1;
                }
                else {
                    My_Player.set_Index(My_Player.get_Index() + 1);
                    step = 1;

                }
                fish.update(200.0f); // Примерное время между кадрами (60 FPS)
                fish.draw(window, my_player_x, my_player_y); // Отображаем анимацию в координатах (100, 100
            }
            else {
                fish.setAnimating(false);
                fish.draw(window, my_player_x, my_player_y);
            }
            if (Other_Player.get_Index() < new_other_player_index && My_Player.get_Index() == new_my_player_index) {
                crocodile.setAnimating(true);
                int l = (Coord[Other_Player.get_Index() + 1][0] - Coord[Other_Player.get_Index()][0]) / 10;
                int h = (Coord[Other_Player.get_Index() + 1][1] - Coord[Other_Player.get_Index()][1]) / 10;
                if (step_c <= 10) {
                    other_player_x += l;
                    other_player_y += h;
                    step_c += 1;
                }
                else {
                    Other_Player.set_Index(Other_Player.get_Index() + 1);
                    step_c = 1;

                }
                crocodile.update(200.0f); // Примерное время между кадрами (60 FPS)
                crocodile.draw(window, other_player_x+10, other_player_y+5); // Отображаем анимацию в координатах (100, 100
            }
            else {
                int Type = Number_Of_Type(All_Coins[Other_Player.get_Index()].get_Type());
                Take_Coin(Other_Player, Other_Player.get_Index(), Other_Coins_Coord[Type][0], Other_Coins_Coord[Type][1], All_Coins);
                crocodile.setAnimating(false);
                crocodile.draw(window, other_player_x+10, other_player_y+5);
            }
            //СОФА ФУНКЦИЯ КОТОРАЯ СЧИТАЕТ КОЛИЧЕСТВО МОНЕТ ПРИ СЕБЕ РАЗНЫХ ТИПОВ
            textRenderer.drawText(window, "X0", WIDTH / 8, WIDTH / 6, 30, sf::Color::White);


        }

        else if (currentState == GameState::Final)
        {
            renderGame(window);
        }

        else if (currentState == GameState::Rating)
        {
            renderGame(window);
        }

        


        for (auto& ripple : ripples) {
            ripple.update();
        }

        // Удаляем завершенные ряды
        ripples.erase(std::remove_if(ripples.begin(), ripples.end(),
            [](const Ripple& ripple) { return ripple.isFinished(); }), ripples.end());
        for (auto& ripple : ripples) {
            ripple.draw(window);
        }
        window.display();
    }

    return 0;
}
