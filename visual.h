#ifndef VISUAL_H
#define VISUAL_H
// Функция для отрисовки квадрата
void drawSquare(sf::RenderWindow& window, sf::RectangleShape& circle);
void drawCircle(sf::RenderWindow& window, sf::CircleShape& circle);

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
