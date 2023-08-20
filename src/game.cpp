#include "game.hpp"
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>

Game::Game(const int width, const int height) {
    this->display.create(width, height);
}

void Game::run() {
    while (this->display.window.isOpen()) {
        sf::Event event;

        while (this->display.window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                this->display.window.close();
            }
        }

        this->update();
        this->display.window.display();
    }
}

void Game::update() {
    this->display.update();
}
