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



void drawSquare(sf::RenderWindow& window, int x, int y);
void drawCircle(sf::RenderWindow& window, int x, int y);
void drawImage(sf::RenderWindow& window, const std::string& textureName, float x, float y, float width, float height, TextureManager& textureManager);
void drawPopup(sf::RenderWindow& window, const std::string& message);

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
#endif // VISUAL_H
