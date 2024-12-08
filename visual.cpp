#include <SFML/Graphics.hpp>
#include "visual.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <filesystem>
// Функция для отрисовки квадрата
bool TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    sf::Texture texture;
    // Загружаем текстуру из файла
    if (!texture.loadFromFile(filename)) {
        std::cerr << "Error loading texture from file: " << filename << std::endl;
        return false; // Возвращаем false, если загрузка не удалась
    }

    // Сохраняем текстуру в контейнере
    textures[name] = std::move(texture); // Используем std::move для перемещения объекта
    return true;
}

// Получение текстуры по имени
const sf::Texture& TextureManager::getTexture(const std::string& name) {
    return textures.at(name); // Используйте at() для безопасного доступа
}


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

void drawImage(sf::RenderWindow& window, const std::string& textureName, float x, float y, float width, float height, TextureManager& textureManager) {
    sf::Sprite sprite;
    sprite.setTexture(textureManager.getTexture(textureName));
    sprite.setPosition(x, y);
    sprite.setScale(width / sprite.getLocalBounds().width, height / sprite.getLocalBounds().height); // Масштабируем спрайт
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
    backgroundTexture.loadFromFile((folder/"start.png").string());
    
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
    backgroundTexture.loadFromFile((folder / "level.png").string());

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
    std::filesystem::path folder = "Pictures";
    // Загружаем текстуру из файла
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile((folder / "game.png").string());

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
    backgroundTexture.loadFromFile((folder/"final.png").string());

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
    backgroundTexture.loadFromFile((folder/"defeat.png").string());

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