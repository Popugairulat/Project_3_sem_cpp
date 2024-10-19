#ifndef VISUAL_H
#define VISUAL_H

#include <SFML/Graphics.hpp>
#include <string>

// Функция для инициализации окна
void createWindow(sf::RenderWindow& window, int width, int height, const std::string& title);

// Функция для отрисовки квадрата
void drawSquare(sf::RenderWindow& window, sf::RectangleShape& circle);

#endif // VISUAL_H
