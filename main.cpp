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
    Button button_settings(500.f, 500.f,200.f, 100.f, "cccc", "base_for_buttons");
    Button button_back(100.f, 100.f,200.f, 100.f, "cccc", "base_for_buttons");
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
            button_settings.draw_button(window);
            button_settings.get_pressed(event);
            if (button_settings.pressed) {
                if (currentState == GameState::Start) {
                    currentState = GameState::Settings;
                }
                
            }
        }
        else if (currentState == GameState::Settings) {
            renderGame(window);
            button_back.draw_button(window);
            button_back.get_pressed(event);
            if (button_back.pressed) {
                if (currentState == GameState::Settings) {
                    currentState = GameState::Game;
                }
                
            }
        }  
        else if (currentState == GameState::Level) {
            renderGame(window);
        }
        else if (currentState == GameState::Game) {
            renderGame(window);
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

