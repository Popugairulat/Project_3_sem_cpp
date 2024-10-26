#include <SFML/Graphics.hpp>
#include "visual.h"
#include "buttons.h"
#include "functions.h"
#include "class.h"


int main() {
    int WIDTH = 1080, HEIGHT = 720;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "XYI");
    GameState currentState = GameState::Start;
    // Create a circle shape
    

     // Начальная позиция квадрата в центре окна

    while (window.isOpen()) {
        sf::Event event;

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
            drawSquare(window, 200, 300 );
        }
        else if (currentState == GameState::Level) {
            renderGame(window);
            drawSquare(window, 200, 300);
        }
        else if (currentState == GameState::Game) {
            renderGame(window);
            drawSquare(window, 200, 300);
        }
        else if (currentState == GameState::Final) {
            renderGame(window);
            drawSquare(window, 200, 300);
        }
        else if (currentState == GameState::Rating) {
            renderGame(window);
            drawSquare(window, 200, 300);
        }


        window.display();
    }


    return 0;
}
