#ifndef VISUAL_H
#define VISUAL_H
// Функция для отрисовки квадрата
void drawSquare(sf::RenderWindow& window, int x, int y);
void drawCircle(sf::RenderWindow& window, int x, int y);
void drawImage(sf::RenderWindow& window, const std::string& filename, int x, int y, float scaleX, float scaleY);
void drawPopup(sf::RenderWindow& window, const std::string& message);

enum class GameState {
    Start,
    Level,
    Game,
    Final,
    Rating
};
void renderStart(sf::RenderWindow& window);
void renderLevel(sf::RenderWindow& window);
void renderGame(sf::RenderWindow& window);
void renderFinal(sf::RenderWindow& window);
void renderRating(sf::RenderWindow& window);
#endif // VISUAL_H
