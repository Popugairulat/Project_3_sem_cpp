#include <SFML/Graphics.hpp>
#include <string> 
#include "buttons.h"

// Реализация функций, связанных с кнопками
Button::Button(float x, float y, float width, float height,const std::string& text): x(x), y(y), height(height), width(width), text(text) {}
sf::RectangleShape Button::createSquare() {
        sf::RectangleShape rectangle(sf::Vector2f(width, height));
        rectangle.setPosition(x, y);
        rectangle.setFillColor(sf::Color::Green);
        return rectangle;
    }
void Button::draw_button(sf::RenderWindow& window) {
        sf::RectangleShape body = Button::createSquare();
        body.setFillColor(sf::Color::Green);

        // Можно добавить текст на кнопку
        // sf::Font font; // Не забудьте загрузить шрифт!
        // if (!font.loadFromFile("path/to/font.ttf")) {
        //     // Обработка ошибки загрузки шрифта
        // }
        
        // sf::Text bodyText;
        // bodyText.setFont(font);
        // bodyText.setString(text);
        // bodyText.setCharacterSize(24); // Размер текста
        // bodyText.setFillColor(sf::Color::White); // Цвет текста
        
        // Центрируем текст
        // bodyText.setPosition(x + (width - bodyText.getGlobalBounds().width) / 2,
        //                      y + (height - bodyText.getGlobalBounds().height) / 2);

        // Рисуем кнопку и текст
        window.draw(body);
        //window.draw(bodyText);
    }
