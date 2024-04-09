//
// Created by Cosmin on 04.04.2024.
//

#include "../headers/Game.h"
#include <vector>
#include <string>

Game::Game(const int& highScore_): window{sf::RenderWindow(sf::VideoMode(1500, 850), "Plants-vs-Zombies", sf::Style::Titlebar | sf::Style::Close)},
              background{std::vector<std::vector<sf::Sprite>>{5, std::vector<sf::Sprite>(10)}},
              resources{0},
              score{0},
              highScore{highScore_}
              {

    /// Bar height = 100, Map height = 750;

    /// Load tile texture
    tileTexture.loadFromFile("textures/bg/background-tile.png");
    sf::Sprite sprite(tileTexture);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 10; ++j) {
            background[i][j] = sprite;
            background[i][j].setPosition(sf::Vector2f(150.f * float(j), 150.f * float(i) + 100.f));
        }

    /// Creating the bar [3 cats, resources, state of game, score/high score]

    /// 3 small slots for picking the cats :))
    slotTexture.loadFromFile("textures/bg/slot.png");
    sprite = sf::Sprite{slotTexture};
    for (int i = 0; i < 3; ++i) {
        sprite.setPosition(sf::Vector2f(200.f * float(i), 0.f));
        bar.push_back(sprite);
    }

    /// 3 big slots for resources, state of game, score/high score
    bigSlotTexture.loadFromFile("textures/bg/slot_long.png");
    sprite = sf::Sprite{bigSlotTexture};
    for (int i = 0; i < 3; ++i) {
        sprite.setPosition(sf::Vector2f(600.f + 300.f * float(i), 0.f));
        bar.push_back(sprite);
    }

    /// Shooter Cat
    shooterCat.loadFromFile("textures/cats-icons/shooter-cat-icon.png");
    sprite = sf::Sprite{shooterCat};
    sprite.setPosition(4, 4);
    bar.push_back(sprite); /// Adding shooter cat

    /// Score/ Hight score
    font.loadFromFile("fonts/yoster.ttf");

    text.setFont(font);
    text.setString("Score: " + std::to_string(score) +
                    "\nHigh score: " + std::to_string(highScore));
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold);
    text.setPosition(1220, 20);

}

void Game::update() {

}

void Game::render() {
    window.clear(sf::Color::White);

    /// Desenare background
    for (auto &i : background)
        for (auto &j : i)
            window.draw(j);

    /// Desenare bara de joc
    for (auto &partition : bar)
        window.draw(partition);

    /// Desenare pisici
    for (auto &cat : cats) {
        window.draw(cat);
    }


    /// Desenare score / high score
    window.draw(text);

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

        //update();
        render();
    }
}
