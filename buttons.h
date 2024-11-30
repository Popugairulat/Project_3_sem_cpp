#ifndef BUTTONS_H
#define BUTTONS_H

#include <SFML/Graphics.hpp>

// Здесь будут функции, связанные с кнопками
class Button {
private:
    float x, y;
    float height, width;
    const std::string text;

public:
    Button(float x, float y, float width, float height,const std::string& text);
    sf::RectangleShape createSquare();
    void draw_button(sf::RenderWindow& window);
};
#endif // BUTTONS_H
