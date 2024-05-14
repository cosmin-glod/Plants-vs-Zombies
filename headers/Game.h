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
#include "Cats/ShooterCat.h"
#include "Cats/GeneratorCat.h"
#include "Cats/WallCat.h"
#include "Button.h"
#include "Projectile.h"

class Game {
    sf::RenderWindow window;
    static int resources;
    static int score;
    static int highScore;

    std::vector<sf::RectangleShape> background_tiles;
    std::vector<Enemy> enemies;
    std::vector<std::unique_ptr<Cat>> cats;
    std::vector<Projectile> projectiles;

    Button<ShooterCat> shooterCatButton;
    Button<GeneratorCat> generatorCatButton;
    Button<WallCat> wallCatButton;

    Drawable resourcesBox;
    Drawable enemyCountBox;
    Drawable scoreBox;

    sf::Font font;
    sf::Text scoreText;

    std::vector<std::vector<bool>> grid;

    sf::Clock spawnTimer;

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
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
    void handleButtonDrag();

    void closeIfNeeded();
    void update();
    void render();
    void updateMousePosition();
};


#endif //OOP_GAME_H
