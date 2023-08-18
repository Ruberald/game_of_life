#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Game of Life!");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
    return 0;
}
