#include <SFML/Graphics.hpp>
#include "visual.h"
#include "buttons.h"
#include "functions.h"


int main() {
    int WIDTH = 1080, HEIGHT = 720;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "XYI");
    GameState currentState = GameState::Start;
    // Create a circle shape
    sf::CircleShape circle(10); // Radius of 50 pixels circle.setFillColor(sf::Color::Green); // Fill color
    circle.setOutlineThickness(5); // Outline thickness circle.setOutlineColor(sf::Color::Red); // Outline color
    circle.setPosition(375, 275);

    sf::RectangleShape square(sf::Vector2f(50.0f, 50.0f)); // Объявление переменной square
    square.setFillColor(sf::Color::Green);
    square.setPosition(375.0f, 275.0f); // Начальная позиция квадрата в центре окна

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
        const float speed = 0.08;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            square.move(-speed, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            square.move(speed, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            square.move(0.0f, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            square.move(0.0f, speed);
        }

        // Отрисовка в зависимости от текущего состояния
        if (currentState == GameState::Start) {
            renderStart(window);
            drawSquare(window, square);
        }
        else if (currentState == GameState::Level) {
            renderGame(window);
            drawSquare(window, square);
        }
        else if (currentState == GameState::Game) {
            renderGame(window);
            window.draw(square);
        }
        else if (currentState == GameState::Final) {
            renderGame(window);
            window.draw(square);
        }
        else if (currentState == GameState::Rating) {
            renderGame(window);
            window.draw(circle);
        }


        window.display();
    }


    return 0;
}
