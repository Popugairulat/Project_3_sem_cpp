#include <SFML/Graphics.hpp>
#include "visual.h"
#include "buttons.h"
#include "functions.h"


int main() {
    sf::RenderWindow window; // Объявляем окно
    createWindow(window, 1000, 800, "XYI"); // Инициализируем окно

    sf::RectangleShape square(sf::Vector2f(50.0f, 50.0f)); // Объявление переменной square
    square.setFillColor(sf::Color::Green);
    square.setPosition(375.0f, 275.0f); // Начальная позиция квадрата в центре окна

    // Главный игровой цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Обновление позиции квадрата
        const float speed = 0.08;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            square.move(-speed, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            square.move(speed, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            square.move(0.0f, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            square.move(0.0f, speed);
        }

        // Отрисовка квадрата
        drawSquare(window, square);
    }

    return 0;
}
