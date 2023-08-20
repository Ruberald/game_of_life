#include "display.hpp"

Display::Display() {

}

void Display::create(const int width, const int height) {
    this->window.create(sf::VideoMode(width, height), "Game of Life!");
    this->texture.create(width/10, height/10);
    this->sprite.setTexture(texture);
    this->sprite.setScale(10, 10);
    this->pixels = new sf::Uint8[width/10 * height/10 * 4];
    this->Grid[width/10][height/10];
}

void Display::update() {
    this->pixels[20] = 0;
    this->pixels[21] = 0;
    this->pixels[22] = 0;
    this->pixels[23] = 0xff;
    this->texture.update(this->pixels);
    
    this->window.clear(sf::Color::White);
    this->window.draw(this->sprite);
}
