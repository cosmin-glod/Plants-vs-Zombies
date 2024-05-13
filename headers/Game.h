//
// Created by Cosmin on 04.04.2024.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Cat.h"
#include "Button.h"

class Game {
    sf::RenderWindow window;
    static int resources;
    static int score;
    static int highScore;

    std::vector<sf::RectangleShape> background_tiles;
    std::vector<Enemy> enemies;
    std::vector<Drawable*> entities;

    sf::Clock spawnTimer;
public:

    /// Constructori / Destructori
    Game();
    ~Game() = default;

    [[nodiscard]] bool isRunning() const;
    static void setHighScore(const int&);

    /// Functii
    void run();

    /// Spawners
    void spawnEnemy();

    void closeIfNeeded();
    void update();
    void render();
};


#endif //OOP_GAME_H
