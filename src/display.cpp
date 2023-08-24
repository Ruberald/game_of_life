#include "display.hpp"
#include <SFML/Config.hpp>
#include <cstdint>
#include <cstring>

Display::Display() {

}

void Display::create(const int width, const int height) {
    this->window.create(sf::VideoMode(width, height), "Game of Life!");
    this->texture.create(width/10, height/10);
    this->sprite.setTexture(texture);
    this->sprite.setScale(10, 10);
    this->pixs = new sf::Uint8[width/10 * height/10 * 4];
}

void Display::update(uint32_t * grid) {
    sf::Uint8 * pixels = reinterpret_cast<sf::Uint8 *>(grid);
    this->texture.update(pixels);
    
    this->window.clear(sf::Color::White);
    this->window.draw(this->sprite);
}

inline int Display::returnPixel(const int x, const int y) {
    return 4 * (y/10 * this->window.getSize().x/10 + x/10);
}

void Display::drawPixel(const int x, const int y) {
    sf::Uint8 * pixel = &this->pixs[returnPixel(x, y)];

    *pixel = 0;
    *(pixel + 1) = 0;
    *(pixel + 2) = 0;
    *(pixel + 3) = 0xFF;
}
