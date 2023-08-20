#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#pragma once

class Display {
public:
    Display();
    sf::RenderWindow window;
    sf::Sprite sprite;

    void create(const int width, const int height);
    void update();

private:
    sf::Texture texture;
    sf::Uint8* pixels;
    const int ** Grid;

    void init();
};
