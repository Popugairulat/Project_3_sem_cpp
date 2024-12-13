#ifndef BUTTONS_H
#define BUTTONS_H
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "visual.h"
// Здесь будут функции, связанные с кнопками
class Button {
public:
    Button( float x, float y, float width, float height, const std::string& text);

    void draw_button(sf::RenderWindow& window, TextureManager& textureManager);
    void get_pressed(sf::Event event);

    float x, y, width, height;
    std::string text;
    bool pressed;
};
#endif // BUTTONS_H
