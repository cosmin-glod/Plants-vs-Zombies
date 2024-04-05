//
// Created by Cosmin on 04.04.2024.
//

#include "../Headers/Game.h"
#include <vector>

Game::Game(): window{sf::RenderWindow(sf::VideoMode(1500, 850), "Plants-vs-Zombies", sf::Style::Titlebar | sf::Style::Close)},
              background{std::vector<std::vector<sf::Sprite>>{5, std::vector<sf::Sprite>(10)}},
              resources{0}{
   tileTexture.loadFromFile("textures/background-tile.png");
   tile = sf::Sprite(tileTexture);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 10; ++j) {
            background[i][j] = tile;
            background[i][j].setPosition(sf::Vector2f(150.f * float(j), 150.f * float(i) + 100.f));
        }
}

void Game::update() {

}

void Game::render() {
    window.clear();

    for (auto &i : background)
        for (auto &j : i)
            window.draw(j);

    sf::RectangleShape s(sf::Vector2f(1500.f, 100.f));
    s.setFillColor(sf::Color::Yellow);
    window.draw(s);

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

void Game::run() {
    while (isRunning()) {
        closeIfNeeded();

        update();
        render();
    }
}
