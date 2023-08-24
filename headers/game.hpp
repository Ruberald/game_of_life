#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cstdint>
#include <list>
#include <string>
#include "display.hpp"

#pragma once

class Game {
public:
    Game(const int width, const int height);
    void run();

private:
    Display display;
    int h_cells, v_cells;
    uint32_t * Grid;
    std::list<int> activeGrid;
    std::list<int> toBeCleared;
    std::list<int> toBeDrawn;

    void update();
    inline int returnCell(const int x, const int y);
    void drawCell(const int x, const int y);
    void tick();
    void _drawCell(int cell);
    void clearCell(const int cell);
    void deadToAlive(int cell);
    int checkNeighbourCells(int cell, bool active);
};
