#include "global.h"
#include <filesystem>

// �����������, ��� desktop.width ��� ��������� ���-�� � ����� ����
// ��������, �� ������ ������������ sf::VideoMode::getDesktopMode().width ��� ��������� ������ ������
sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

int WIDTH = static_cast<int>(desktop.width * 0.9);
int HEIGHT = (WIDTH * 943 - WIDTH * 943 % 1880) / 1880;
