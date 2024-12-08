#include <iostream>
#include <SFML/Graphics.hpp>
#include "visual.h"
#include "buttons.h"
#include "functions.h"
#include "class.h"
#include <filesystem>

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    const int WIDTH = static_cast<const int>(desktop.width * 0.9);
    const int HEIGHT = (WIDTH * 943-WIDTH*943%1880)/1880;
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



    //массивы с кнопками
    std::vector<Button> buttons_start;
    buttons_start.emplace_back( WIDTH/2- WIDTH / 8, HEIGHT/2+ HEIGHT / 14, WIDTH/4, HEIGHT/7, "Start new game");
    buttons_start.emplace_back(WIDTH / 2 - WIDTH / 8, HEIGHT / 2 +3* HEIGHT / 14, WIDTH / 4, HEIGHT / 7, "Continue the game");
    buttons_start.emplace_back(WIDTH - WIDTH / 20 - WIDTH / 200, WIDTH / 200, WIDTH / 20, WIDTH / 20, "Settings");
    buttons_start.emplace_back(WIDTH - 2 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Question");
    buttons_start.emplace_back(WIDTH - 3 * (WIDTH / 20 + WIDTH / 200), WIDTH / 200, WIDTH / 20, WIDTH / 20, "Back");


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


        window.display();
     }


    return 0;
}

