//
// Created by Cosmin on 04.04.2024.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <SFML/Graphics.hpp>
#include <vector>

class Game {
    sf::RenderWindow window;
    sf::Texture tileTexture;
    sf::Sprite tile;
    std::vector<std::vector<sf::Sprite>> background;
    std::vector<sf::RectangleShape> bar;

    int resources;

public:
    /// Constructori / Destructori
    Game();
    ~Game() = default;

    /// Functii accesorii
    [[nodiscard]] bool isRunning() const;

    /// Functii
    void run();

    void closeIfNeeded();
    void update();
    void render();
};


#endif //OOP_GAME_H
