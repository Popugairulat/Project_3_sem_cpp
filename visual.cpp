#include <SFML/Graphics.hpp>
#include "visual.h"

// Функция для инициализации окна
void createWindow(sf::RenderWindow& window, int width, int height, const std::string& title) {
    window.create(sf::VideoMode(width, height), title);
}

// Функция для отрисовки квадрата
void drawSquare(sf::RenderWindow& window, sf::RectangleShape& circle) {
    window.clear(sf::Color::Cyan); // Устанавливаем цвет фона (голубой)
    window.draw(circle); // Рисуем квадрат
    window.display(); // Отображаем содержимое окна
}
