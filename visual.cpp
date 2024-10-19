#include <SFML/Graphics.hpp>
#include "visual.h"

// Функция для отрисовки квадрата
void drawSquare(sf::RenderWindow& window, sf::RectangleShape& circle) {
    window.draw(circle); // Рисуем квадрат
}

void drawCircle(sf::RenderWindow& window, sf::CircleShape& circle) {
    window.draw(circle); // Рисуем круг
}


void renderStart(sf::RenderWindow& window) {
    window.clear(sf::Color::Red); // Цвет фона для заставки // Здесь можно добавить текст или графику для заставки
    sf::Font font;
    font.loadFromFile("arial.ttf"); // Убедитесь, что у вас есть шрифт
    sf::Text text("Заставка", font, 50);
    text.setFillColor(sf::Color::Green);
    text.setPosition(400, 300);
    window.draw(text);
}

void renderLevel(sf::RenderWindow& window) {
    window.clear(sf::Color::Yellow); // Цвет фона для игры
    // Здесь можно добавить графику или элементы игры
    sf::Font font;
    font.loadFromFile("arial.ttf"); // Убедитесь, что у вас есть шрифт
    sf::Text text("Игра", font, 50);
    text.setFillColor(sf::Color::White);
    text.setPosition(450, 300);
    window.draw(text);
}

void renderGame(sf::RenderWindow& window) {
    window.clear(sf::Color::Green); // Цвет фона для игры
    // Здесь можно добавить графику или элементы игры
    sf::Font font;
    font.loadFromFile("arial.ttf"); // Убедитесь, что у вас есть шрифт
    sf::Text text("Игра", font, 50);
    text.setFillColor(sf::Color::White);
    text.setPosition(450, 300);
    window.draw(text);
}

void renderFinal(sf::RenderWindow& window) {
    window.clear(sf::Color::Blue); // Цвет фона для игры
    // Здесь можно добавить графику или элементы игры
    sf::Font font;
    font.loadFromFile("arial.ttf"); // Убедитесь, что у вас есть шрифт
    sf::Text text("Игра", font, 50);
    text.setFillColor(sf::Color::White);
    text.setPosition(450, 300);
    window.draw(text);
}

void renderRating(sf::RenderWindow& window) {
    window.clear(sf::Color::Cyan); // Цвет фона для игры
    // Здесь можно добавить графику или элементы игры
    sf::Font font;
    font.loadFromFile("arial.ttf"); // Убедитесь, что у вас есть шрифт
    sf::Text text("Игра", font, 50);
    text.setFillColor(sf::Color::White);
    text.setPosition(450, 300);
    window.draw(text);
}