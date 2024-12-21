#include <SFML/Graphics.hpp>
#include "visual.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <filesystem>
// Загрузка картинок

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
const sf::Texture& TextureManager::getTexture(const std::string& name) {
    return textures.at(name); // Используйте at() для безопасного доступа
}

//Класс для анимации изображений (смены картинок с определенной частотой)
Animation::Animation(TextureManager& textureManager, const std::vector<std::string>& textureNames, float frameTime)
    : frameTime(frameTime), currentFrame(0), elapsedTime(0.0f), isAnimating(true) {
    for (const auto& name : textureNames) {
        textures.push_back(&textureManager.getTexture(name)); // Сохраняем указатели на текстуры
    }
}
void Animation::update(float deltaTime) {
    if (isAnimating) {
        elapsedTime += deltaTime;
        if (elapsedTime >= frameTime) {
            currentFrame = (currentFrame + 1) % textures.size();
            elapsedTime = 0.0f;
        }
    }
}
void Animation::draw(sf::RenderWindow& window, float x, float y) {
    if (!textures.empty()) {
        sf::Sprite sprite;
        sprite.setTexture(*textures[currentFrame]); // Разыменовываем указатель
        sprite.setScale(150 / sprite.getLocalBounds().width, 150 / sprite.getLocalBounds().height); // Масштабируем спрайт
        sprite.setPosition(x, y);
        window.draw(sprite);
    }
}
void Animation::setAnimating(bool animating) {
    isAnimating = animating;
}

// Класс для анимации касания (смены кружочков разного радиуса разной прозрачности)
Ripple::Ripple(sf::Vector2f position)
    : radius(0), maxRadius(25), growing(true) {
    circle.setRadius(radius); // Устанавливаем начальный радиус
    circle.setFillColor(sf::Color(255, 255, 255, 128)); // Полупрозрачный белый
    circle.setOrigin(maxRadius, maxRadius); // Устанавливаем центр круга в его центр
    circle.setPosition(position); // Устанавливаем позицию круга
}
void Ripple::update() {
    if (growing) {
        radius += 2; // Увеличиваем радиус
        if (radius >= maxRadius) {
            growing = false; // Останавливаем рост
        }
    }
    circle.setRadius(radius); // Устанавливаем радиус
    // Обновляем центр круга в зависимости от нового радиуса
    circle.setOrigin(radius, radius);
    // Увеличиваем прозрачность в зависимости от радиуса
    int alpha = static_cast<int>(255 - (radius / maxRadius) * 255); // Прозрачность от 0 до 255
    circle.setFillColor(sf::Color(255, 255, 255, alpha)); // Устанавливаем цвет с изменяющейся прозрачностью
}
void Ripple::draw(sf::RenderWindow& window) {
    window.draw(circle);
}
bool Ripple::isFinished() const {
    return !growing && radius >= maxRadius;
}

//Отрисовка картинки с нужными параметрами
void drawImage(sf::RenderWindow& window, const std::string& textureName, float x, float y, float width, float height, TextureManager& textureManager) {
    sf::Sprite sprite;
    sprite.setTexture(textureManager.getTexture(textureName));
    sprite.setPosition(x, y);
    sprite.setScale(width / sprite.getLocalBounds().width, height / sprite.getLocalBounds().height); // Масштабируем спрайт
    window.draw(sprite);
}

//Отрисовка экранов






void renderSettings(sf::RenderWindow& window, const std::string& textureName, TextureManager& textureManager) {
    window.clear();
    // Загружаем текстуру из файла
    sf::Texture backgroundTexture = textureManager.getTexture(textureName);

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

void drawPopup(sf::RenderWindow& window, int WIDTH, const std::string& message) {
    // Создаем прямоугольник для всплывающего окна
    sf::RectangleShape popup(sf::Vector2f(WIDTH / 6*4, (WIDTH * 943 - WIDTH * 943 % 1880) / 1880));
    popup.setFillColor(sf::Color(0, 0, 0, 200)); // Полупрозрачный цвет
    popup.setPosition( WIDTH/6 ,0); // Позиция всплывающего окна

    // Создаем текст для сообщения
    sf::Font font;
    font.loadFromFile("Roboto-Black.ttf");
    sf::Text text(message, font, 40);
    sf::Color lightBrown(195, 176, 145);
    text.setFillColor(lightBrown);
    text.setString(message);

    text.setPosition(WIDTH / 5, WIDTH / 5- WIDTH / 6); // Позиция текста

    // Рисуем всплывающее окно и текст
    window.draw(popup);
    window.draw(text);
}
TextRenderer::TextRenderer(const std::string& fontFile) {
    if (!font.loadFromFile(fontFile)) {
        std::cerr << "Ошибка загрузки шрифта из файла: " << fontFile << std::endl;
    }
}

void TextRenderer::drawText(sf::RenderWindow& window, std::string& text, float x, float y, unsigned int size, sf::Color color) {
    sf::Text sfText;
    sfText.setFont(font);
    sfText.setString(text);
    sfText.setCharacterSize(size);
    sfText.setFillColor(color);
    sfText.setPosition(x, y);
    window.draw(sfText);
}
void drawNumbers(sf::RenderWindow& window, int numbers_of_coins[8], TextRenderer textRenderer, int HEIGHT, unsigned int size) {
    for (int i = 0; i < 4; ++i) {
        textRenderer.drawText(window, std::to_string(numbers_of_coins[i]), HEIGHT / 4.5, i * HEIGHT / 10 + HEIGHT / 15, size, sf::Color(0, 164, 228));
        ;
    }
    for (int i = 5; i < 9; ++i) {
        textRenderer.drawText(window, std::to_string(numbers_of_coins[i-1]), HEIGHT / 4.5, i * HEIGHT / 10 + HEIGHT / 15, size, sf::Color(0, 164, 228));
    }


}