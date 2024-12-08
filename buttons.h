#ifndef BUTTONS_H
#define BUTTONS_H
#include <filesystem>
#include <SFML/Graphics.hpp>
// Здесь будут функции, связанные с кнопками
class Button {
public:
    Button(sf::RenderWindow& window, float x, float y, float width, float height, const std::string& text, const std::filesystem::path& folder, const std::filesystem::path& file);

    void draw_button();
    void get_pressed(sf::Event event);

    sf::RenderWindow& window;
    float x, y, width, height;
    std::string text;
    std::filesystem::path folder;
    std::filesystem::path file;
    bool pressed;

    sf::RectangleShape createSquare();
};
#endif // BUTTONS_H
