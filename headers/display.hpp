#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cstdint>

#pragma once

class Display {
public:
    Display();
    sf::RenderWindow window;
    sf::Sprite sprite;

    void create(const int width, const int height);
    void drawPixel(const int x, const int y);
    void update(uint32_t * grid);

private:
    sf::Texture texture;
    sf::Uint8* pixs;

    void init();
    inline int returnPixel(const int, const int);
};
