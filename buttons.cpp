#include <SFML/Graphics.hpp>
#include <string> 
#include <filesystem>
#include "buttons.h"
#include "visual.h"

// Реализация функций, связанных с кнопками

//FIX предупреждение про порядок инициализации



// Button::Button(float x, float y, float width, float height, const std::string& text, std::filesystem::path file)
//     : x(x), y(y), height(height), width(width), text(text), pressed(false), file(file) {}
Button::Button(sf::RenderWindow& window, float x, float y, float width, float height, const std::string& text, const std::filesystem::path& folder, const std::filesystem::path& file)
        : window(window), x(x), y(y), width(width), height(height), text(text), folder(folder), file(file), pressed(false) {}

sf::RectangleShape Button::createSquare() {
    /*
    вспомогательный метод для отрисовки кнопки
    */
        sf::RectangleShape rectangle(sf::Vector2f(width, height));
        rectangle.setPosition(x, y);
        rectangle.setFillColor(sf::Color::Red);
        return rectangle;
    }
void Button::draw_button() {
    /*
    метод для отрисовки кнопки
    */
        sf::RectangleShape body = Button::createSquare();
        body.setFillColor(sf::Color::Red);

        // Можно добавить текст на кнопку
        sf::Font font; 
        if (!font.loadFromFile("Roboto-Black.ttf")) {
        //     // Обработка ошибки загрузки шрифта
        }
        
        sf::Text bodyText;
        bodyText.setFont(font);
        bodyText.setString(text);
        bodyText.setCharacterSize(40); // Размер текста
        bodyText.setFillColor(sf::Color::Black); // Цвет текста
        
        // Центрируем текст
        bodyText.setPosition(x + (width - bodyText.getGlobalBounds().width) / 2,
                              y + (height - bodyText.getGlobalBounds().height) / 2);

        // Рисуем кнопку и текст
        window.draw(body);
        window.draw(bodyText);
    }
void Button::get_pressed(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.x >= x && event.mouseButton.x <= x + width) {
            if (event.mouseButton.y >= y && event.mouseButton.y <= y + height) {
                pressed = true;
            }
        }

    } 
    else if (event.type == sf::Event::MouseButtonReleased) {
        pressed = false; // Сбрасываем состояние нажатия
    }

}