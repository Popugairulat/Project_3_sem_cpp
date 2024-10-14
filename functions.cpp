#include <SFML/Graphics.hpp>
#include "functions.h"

void updatePlayerPosition(sf::RectangleShape& player) {
    const float speed = 5.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.move(-speed, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.move(speed, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.move(0.0f, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        player.move(0.0f, speed);
    }
}

sf::RectangleShape createPlayer() {
    sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(375.0f, 275.0f);
    return player;
}
