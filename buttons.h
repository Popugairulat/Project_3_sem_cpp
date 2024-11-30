#ifndef BUTTONS_H
#define BUTTONS_H
#include <filesystem>
#include <SFML/Graphics.hpp>

// Здесь будут функции, связанные с кнопками
class Button {
private:
    float x, y;
    float  width, height;
    const std::string text;
    const std::filesystem::path file;

public:
    bool pressed;
    Button(float x, float y, float width, float height, const std::string& text, const std::filesystem::path& file);
    sf::RectangleShape createSquare();
    void draw_button(sf::RenderWindow& window);
    void get_pressed(sf::Event event);
};
#endif // BUTTONS_H
