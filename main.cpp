#include <iostream>
#include <SFML/Graphics.hpp>
#include "visual.h"
#include "buttons.h"
#include "functions.h"
#include "class.h"
#include <filesystem>

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    int WIDTH = static_cast<int>(desktop.width * 0.8);
    int HEIGHT = static_cast<int>(desktop.height * 0.8);
    //int WIDTH = 1880, HEIGHT = 943;
    std::filesystem::path folder="Pictures";
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "XY");
    GameState currentState = GameState::Start;
    // Create a circle shape
    sf::CircleShape circle(10); // Radius of 50 pixels circle.setFillColor(sf::Color::Green); // Fill color
    circle.setOutlineThickness(5); // Outline thickness circle.setOutlineColor(sf::Color::Red); // Outline color
    circle.setPosition(375, 275);

    sf::RectangleShape square(sf::Vector2f(50.0f, 50.0f)); // Объявление переменной square
    square.setFillColor(sf::Color::Green);
    square.setPosition(375.0f, 275.0f); // Начальная позиция квадрата в центре окна

    //window.draw(square);
    
    
    
    //массивы с кнопками
    std::vector<Button> buttons_start;

    buttons_start.emplace_back(WIDTH/2-100.0, HEIGHT/2+50.0, 200, 50, "Start new game", "base_for_buttons");
    buttons_start.emplace_back(WIDTH/2-100.0, HEIGHT/2+150.0, 200, 50, "Continue the game", "base_for_buttons");
    buttons_start.emplace_back(WIDTH/2-100.0, HEIGHT/2+250.0, 200, 50, "Settings", "base_for_buttons");

    std::vector<Button> buttons_settings;

    buttons_settings.emplace_back(WIDTH/2-100.0, 150.0, 200, 50, "Sound", "base_for_buttons");
    buttons_settings.emplace_back(WIDTH/2-100.0, 250.0, 200, 50, "Music", "base_for_buttons");
    buttons_settings.emplace_back(WIDTH/2-100.0, 350.0, 200, 50, "Start menu", "base_for_buttons");
    buttons_settings.emplace_back(WIDTH/2-100.0, 450.0, 200, 50, "Level", "base_for_buttons");
    buttons_settings.emplace_back(WIDTH/2-100.0, 550.0, 200, 50, "Rating", "base_for_buttons");
    buttons_settings.emplace_back(WIDTH-100.0, 0.0, 100, 100, "Back", "base_for_buttons");

    std::vector<Button> buttons_game;

    buttons_game.emplace_back(WIDTH-100.0, 0.0, 100, 100, "Back", "base_for_buttons");
    
    
    
    while (window.isOpen()) {
        sf::Event event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    
}
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } 

            
            
            // Переключение состояния
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
                if (currentState == GameState::Start) {
                    currentState = GameState::Game;
                }
                else {
                    currentState = GameState::Start;
                }
            }
            
            
        }
       
        // Отрисовка в зависимости от текущего состояния
        if (currentState == GameState::Start) {
            renderStart(window);

            drawImage(window, folder/"coin_3.png", 50, 50, 300, 300);
            //drawPopup(window, "Menu");
            for (auto& button : buttons_start) {
            button.draw_button(window);
            button.get_pressed(event);
        }
            if(buttons_start[0].pressed){
                if(currentState == GameState::Start){
                    currentState = GameState::Game;
                }
            }
            if(buttons_start[1].pressed){
                if(currentState == GameState::Start){
                    currentState = GameState::Game;
                }
            }
            if(buttons_start[2].pressed){
                if(currentState == GameState::Start){
                    currentState = GameState::Settings;
                }
            }

        }
        else if (currentState == GameState::Settings) {

            renderGame(window);

            for (auto& button : buttons_settings) {
            button.draw_button(window);
            button.get_pressed(event);
        }
            if(buttons_settings[0].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Game;
                }
            }
            if(buttons_settings[1].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Game;
                }
            }
            if(buttons_settings[2].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Start;
                }
            }
            if(buttons_settings[3].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Level;
                }
            }
            if(buttons_settings[4].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Rating;
                }
            }
            if(buttons_settings[5].pressed){
                if(currentState == GameState::Settings){
                    currentState = GameState::Game;
                }
            }
        }  
        else if (currentState == GameState::Level) {
            renderGame(window);
        }
        else if (currentState == GameState::Game) {
            renderGame(window);
            for (auto& button : buttons_game) {
            button.draw_button(window);
            button.get_pressed(event);
        }
            if(buttons_game[0].pressed){
                if(currentState == GameState::Game){
                    currentState = GameState::Start;
                }
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

