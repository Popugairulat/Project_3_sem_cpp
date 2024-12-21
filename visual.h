#ifndef VISUAL_H
#define VISUAL_H
// Функция для отрисовки квадрата
#include <SFML/Graphics.hpp> // Для sf::Texture
#include <string>
#include <unordered_map>
#include <iostream>

class TextureManager {
public:
    bool loadTexture(const std::string& name, const std::string& filename);
    const sf::Texture& getTexture(const std::string& name);

private:
    std::unordered_map<std::string, sf::Texture> textures; // Хранение текстур
};

class Animation {
public:
    Animation(TextureManager& textureManager, const std::vector<std::string>& textureNames, float frameTime);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window, float x, float y);
    void setAnimating(bool animating);

private:
    std::vector<const sf::Texture*> textures; // Используем указатели на текстуры
    float frameTime; // Время между кадрами
    int currentFrame;
    float elapsedTime;
    bool isAnimating;
};

class Ripple {
public:
    Ripple(sf::Vector2f position);
    void update();
    void draw(sf::RenderWindow& window);
    bool isFinished() const;

private:
    sf::CircleShape circle;
    float radius;
    float maxRadius;
    bool growing;
};


void drawImage(sf::RenderWindow& window, const std::string& textureName, float x, float y, float width, float height, TextureManager& textureManager);
void drawPopup(sf::RenderWindow& window, int WIDTH, const std::string& message);

enum class GameState {
    Start,
    Level,
    Game,
    Final,
    Rating,
    Settings
};
void renderStart(sf::RenderWindow& window);
void renderLevel(sf::RenderWindow& window);
void renderGame(sf::RenderWindow& window);
void renderFinal(sf::RenderWindow& window);
void renderRating(sf::RenderWindow& window);
void renderSettings(sf::RenderWindow& window);
class TextRenderer {
public:
    TextRenderer(const std::string& fontFile);
    void drawText(sf::RenderWindow& window, std::string& text, float x, float y, unsigned int size, sf::Color color);

private:
    sf::Font font;
};
void drawNumbers(sf::RenderWindow& window, int numbers_of_coins[8], TextRenderer textRenderer, int HEIGHT, unsigned int size);

#endif // VISUAL_H