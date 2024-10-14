#include <SFML/Graphics.hpp>
#include "functions.h"
#include "buttons.h"
#include "visual.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simple Game");

    // Инициализация игрока - хз нужно ли?
    sf::RectangleShape player = createPlayer();

    // Основной игровой цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Обновление состояния игры updatePlayerPosition(player);

        window.clear(sf::Color::Black);
        window.draw(player);
        window.display();
    }

    return 0;
}
