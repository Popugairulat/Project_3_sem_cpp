#include <SFML/Graphics.hpp>
#include "visual.h"
#include <iostream>
#include <filesystem>
// Функция для отрисовки квадрата
void drawSquare(sf::RenderWindow& window,  int x, int y) {
    sf::RectangleShape square(sf::Vector2f(50.0f, 50.0f)); // Объявление переменной square
    square.setFillColor(sf::Color::Green);
    square.setPosition(x, y);
    window.draw(square); // Рисуем квадрат
}

void drawCircle(sf::RenderWindow& window,  int x, int y) {
    sf::CircleShape circle(10); // Radius of 50 pixels circle.setFillColor(sf::Color::Green); // Fill color
    circle.setOutlineThickness(5); // Outline thickness circle.setOutlineColor(sf::Color::Red); // Outline color
    circle.setPosition(x, y);
    window.draw(circle); // Рисуем круг
}


void drawImage(sf::RenderWindow& window, const std::string& filename, int x, int y, float width, float length) {

    // Создаем текстуру и загружаем изображение
    sf::Texture texture;
    texture.loadFromFile(filename);

    // Создаем спрайт и устанавливаем текстуру
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Устанавливаем позицию спрайта
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    sprite.setScale(width /texture.getSize().x, length / texture.getSize().y);

    // Рисуем спрайт
    window.draw(sprite);

}

void drawPopup(sf::RenderWindow& window, const std::string& message) {
    // Создаем прямоугольник для всплывающего окна
    sf::RectangleShape popup(sf::Vector2f(300.0f, 200.0f));
    popup.setFillColor(sf::Color(100, 100, 100, 200)); // Полупрозрачный цвет
    popup.setPosition(250.0f, 200.0f); // Позиция всплывающего окна

    // Создаем текст для сообщения
    sf::Font font;
    sf::Text text(message, font, 20);
    text.setFillColor(sf::Color::White);
    text.setPosition(260.0f, 250.0f); // Позиция текста

    // Рисуем всплывающее окно и текст
    window.draw(popup);
    window.draw(text);
}

void renderStart(sf::RenderWindow& window) {
    std::filesystem::path folder="Pictures";
    // Загружаем текстуру из файла
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(folder/"start.png");
    
    // Создаем спрайт и устанавливаем текстуру
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    //Подгон картинки по размеру окна
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;
    float textureWidth = backgroundTexture.getSize().x;
    float textureHeight = backgroundTexture.getSize().y;
    float scaleX = windowWidth / textureWidth;
    float scaleY = windowHeight / textureHeight;
    backgroundSprite.setScale(scaleX, scaleY);

    // Рисуем фон
    window.draw(backgroundSprite);
}






void renderLevel(sf::RenderWindow& window) {
    window.clear();
    // Загружаем текстуру из файла
    sf::Texture backgroundTexture;
    std::filesystem::path folder="Pictures";
    backgroundTexture.loadFromFile(folder/"level.png");

    // Создаем спрайт и устанавливаем текстуру
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    //Подгон картинки по размеру окна
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;
    float textureWidth = backgroundTexture.getSize().x;
    float textureHeight = backgroundTexture.getSize().y;
    float scaleX = windowWidth / textureWidth;
    float scaleY = windowHeight / textureHeight;
    backgroundSprite.setScale(scaleX, scaleY);

    // Рисуем фон
    window.draw(backgroundSprite);
}

void renderGame(sf::RenderWindow& window) {
    window.clear();

    // Загружаем текстуру из файла
    sf::Texture backgroundTexture;
    std::filesystem::path folder="Pictures";
    backgroundTexture.loadFromFile(folder/"game.png");

    // Создаем спрайт и устанавливаем текстуру
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    //Подгон картинки по размеру окна
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;
    float textureWidth = backgroundTexture.getSize().x;
    float textureHeight = backgroundTexture.getSize().y;
    float scaleX = windowWidth / textureWidth;
    float scaleY = windowHeight / textureHeight;
    backgroundSprite.setScale(scaleX, scaleY);

    // Рисуем фон
    window.draw(backgroundSprite);
}

void renderFinal(sf::RenderWindow& window) {
    window.clear();
    std::filesystem::path folder="Pictures";
    // Загружаем текстуру из файла
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(folder/"final.png");

    // Создаем спрайт и устанавливаем текстуру
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    //Подгон картинки по размеру окна
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;
    float textureWidth = backgroundTexture.getSize().x;
    float textureHeight = backgroundTexture.getSize().y;
    float scaleX = windowWidth / textureWidth;
    float scaleY = windowHeight / textureHeight;
    backgroundSprite.setScale(scaleX, scaleY);

    // Рисуем фон
    window.draw(backgroundSprite);
}

void renderDefeat(sf::RenderWindow& window) {
    window.clear();
    std::filesystem::path folder="Pictures";
    // Загружаем текстуру из файла
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(folder/"defeat.png");

    // Создаем спрайт и устанавливаем текстуру
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    //Подгон картинки по размеру окна
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;
    float textureWidth = backgroundTexture.getSize().x;
    float textureHeight = backgroundTexture.getSize().y;
    float scaleX = windowWidth / textureWidth;
    float scaleY = windowHeight / textureHeight;
    backgroundSprite.setScale(scaleX, scaleY);

    // Рисуем фон
    window.draw(backgroundSprite);
}