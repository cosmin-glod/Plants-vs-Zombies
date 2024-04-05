//
// Created by Cosmin on 04.04.2024.
//

#include "../Headers/Game.h"
#include <vector>

Game::Game(): window{sf::RenderWindow(sf::VideoMode(1500, 850), "Plants-vs-Zombies", sf::Style::Titlebar | sf::Style::Close)},
              background{std::vector<std::vector<sf::Sprite>>{5, std::vector<sf::Sprite>(10)}},
              resources{0} {
    /// Load tile texture
   tileTexture.loadFromFile("textures/background-tile.png");
   tile = sf::Sprite(tileTexture);

   /// Creating background matrix
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 10; ++j) {
            background[i][j] = tile;
            background[i][j].setPosition(sf::Vector2f(150.f * float(j), 150.f * float(i) + 100.f));
        }

    /// Creating the bar [3 cats, resources, state of game, score/high score]
    sf::RectangleShape aux;

    aux.setSize(sf::Vector2f (200.f, 100.f));
    aux.setPosition(sf::Vector2f (0.f, 0.f));
    aux.setFillColor(sf::Color::Blue);
    bar.push_back(aux);

    aux.setSize(sf::Vector2f (200.f, 100.f));
    aux.setPosition(sf::Vector2f (200.f, 0.f));
    aux.setFillColor(sf::Color::Yellow);
    bar.push_back(aux);

    aux.setSize(sf::Vector2f (200.f, 100.f));
    aux.setPosition(sf::Vector2f (400.f, 0.f));
    aux.setFillColor(sf::Color::Red);
    bar.push_back(aux);

    aux.setSize(sf::Vector2f (300.f, 100.f));
    aux.setPosition(sf::Vector2f (600.f, 0.f));
    aux.setFillColor(sf::Color::Magenta);
    bar.push_back(aux);

    aux.setSize(sf::Vector2f (300.f, 100.f));
    aux.setPosition(sf::Vector2f (1200.f, 0.f));
    aux.setFillColor(sf::Color::White);
    bar.push_back(aux);


}

void Game::update() {

}

void Game::render() {
    window.clear();

    /// Desenare background
    for (auto &i : background)
        for (auto &j : i)
            window.draw(j);

    /// Desenare bara de joc
    for (auto &partition : bar)
        window.draw(partition);

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
