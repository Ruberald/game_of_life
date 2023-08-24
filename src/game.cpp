#include "game.hpp"
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cstdint>
#include <cstring>
#include <iostream>

Game::Game(const int width, const int height) {
    this->display.create(width, height);
    this->h_cells = width/10;
    this->v_cells = height/10;
    auto size = this->h_cells * this->v_cells;
    this->Grid = new uint32_t[size];
    std::fill(this->Grid, this->Grid + size, 0x00000000);
    //memset(this->Grid, 0x00000000, sizeof(uint32_t));
}

void Game::run() {
    while (this->display.window.isOpen()) {
        sf::Event event;

        while (this->display.window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                this->display.window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    this->drawCell(event.mouseButton.x, event.mouseButton.y);
                }
            }
            else if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Enter) {
                    this->tick();
                }
            }
        }

        this->update();
        this->display.window.display();
    }
}

void Game::update() {
    this->display.update(this->Grid);
}


inline int Game::returnCell(const int x, const int y) {
    return (y/10 * this->h_cells + x/10);
}

void Game::drawCell(const int x, const int y) {
    //this->display.drawPixel(x, y);
    _drawCell(this->returnCell(x, y));
}

void Game::tick() {
    //check for neighbouring cells
    for (int activeCell : this->activeGrid) {
        switch(this->checkNeighbourCells(activeCell, true)) {
            case 0:
            case 1:
                std::cout << activeCell << " dies of under\n";
                this->toBeCleared.push_back(activeCell);
                break;
            case 2:
            case 3:
                std::cout << activeCell << " lives\n";
                break;
            default:
                std::cout << activeCell << " dies of over\n";
                this->toBeCleared.push_back(activeCell);
        }
    }

    for (int cell: this->toBeCleared) {
        this->clearCell(cell);
    }
    toBeCleared.clear();

    for (int cell: this->toBeDrawn) {
        this->_drawCell(cell);
    }
    toBeDrawn.clear();
}

void Game::_drawCell(int cell) {
    this->Grid[cell] = 0xFF0000FF;
    this->activeGrid.push_back(cell);
}

void Game::clearCell(const int cell) {
    this->Grid[cell] = 0x00000000;
    this->activeGrid.remove(cell);
}

void Game::deadToAlive(int cell) {
    switch(checkNeighbourCells(cell, false)) {
        case 3:
            if(std::find(toBeDrawn.begin(), toBeDrawn.end(), cell) == std::end(toBeDrawn))
                this->toBeDrawn.push_back(cell);
            break;
    }
}

int Game::checkNeighbourCells(int cell, bool active) {
    int count {0};
    int tempCell;

    tempCell = cell + 1; //right cell
    if(tempCell >= 0 || (tempCell % h_cells) == 0) {
        if(Grid[tempCell] == 0xFF0000FF) ++count;
        else if(active == true) deadToAlive(tempCell);
    }

    tempCell = cell - 1; //left cell
    if(tempCell >= 0) {
        if(Grid[tempCell] == 0xFF0000FF) ++count;
        else if(active == true) deadToAlive(tempCell);
    }

    tempCell = cell + this->h_cells; //bottom cell
    if(tempCell >= 0) {
        if(Grid[tempCell] == 0xFF0000FF) ++count;
        else if(active == true) deadToAlive(tempCell);
    }

    tempCell = cell - this->h_cells; //top cell
    if(tempCell >= 0) {
        if(Grid[tempCell] == 0xFF0000FF) ++count;
        else if(active == true) deadToAlive(tempCell);
    }

    tempCell = cell - this->h_cells + 1; //top right cell
    if(tempCell >= 0 || (tempCell % h_cells) == 0) {
        if(Grid[tempCell] == 0xFF0000FF) ++count;
        else if(active == true) deadToAlive(tempCell);
    }

    tempCell = cell + this->h_cells + 1; //bottom right cell
    if(tempCell >= 0 || (tempCell % h_cells) == 0) {
        if(Grid[tempCell] == 0xFF0000FF) ++count;
        else if(active == true) deadToAlive(tempCell);
    }

    tempCell = cell - this->h_cells - 1; //top left cell
    if(tempCell >= 0) {
        if(Grid[tempCell] == 0xFF0000FF) ++count;
        else if(active == true) deadToAlive(tempCell);
    }

    tempCell = cell + this->h_cells - 1; //bottom right cell
    if(tempCell >= 0) {
        if(Grid[tempCell] == 0xFF0000FF) ++count;
        else if(active == true) deadToAlive(tempCell);
    }

    return count;
}
