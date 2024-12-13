#include "global.h"
#include <filesystem>

// Предположим, что desktop.width уже определен где-то в вашем коде
// Например, вы можете использовать sf::VideoMode::getDesktopMode().width для получения ширины экрана
sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

int WIDTH = static_cast<int>(desktop.width * 0.9);
int HEIGHT = (WIDTH * 943 - WIDTH * 943 % 1880) / 1880;
