//
// Created by Cosmin on 04.04.2024.
//

#include "../Headers/Game.h"

Game::Game() :
    window{sf::RenderWindow(sf::VideoMode(1600, 900), /// Width and Height
                            "Plants-vs-Zombies", /// Window name
                            sf::Style::Default)} {}

void Game::update() {

}

void Game::render() {
    window.clear();
    window.display();
}

bool Game::isRunning() const {
    return window.isOpen();
}

void Game::closeIfNeeded() {
    /// Fereastra se inchide cand apasam X-ul ferestrei sau Esc
    sf::Event ev{};
    while (window.pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    window.close();
            default:
                break;
        }
    }
}
