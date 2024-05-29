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
#include "Projectile.h"
#include "Button.h"
#include "TextureManager.h"
#include "exception.h"

class Game {
    static sf::RenderWindow window;
    static int resources;
    static int score;
    static int highScore;
    static bool isMousePressed;

    std::vector<sf::Sprite> background_tiles;
    std::vector<Enemy> enemies;
    std::vector<std::shared_ptr<Cat>> cats;

    Button<ShooterCat> shooterCatButton;
    Button<GeneratorCat> generatorCatButton;
    Button<WallCat> wallCatButton;

    Drawable resourcesBox;
    Drawable enemyCountBox;
    Drawable scoreBox;

    sf::Font font;

    sf::Text scoreText;
    sf::Text resourcesText;
    sf::Text enemyCountText;

    std::vector<std::vector<bool>> grid;

    sf::Clock spawnTimer;

    static float spawnOnceSeconds;
    static int numberOfDificultyStages;
    sf::Time stageTime;
    sf::Clock stageTimer;
    static float nextDificultyStage;

    static sf::Vector2i mousePosWindow;
    static sf::Vector2f mousePosView;

public:

    /// Constructori / Destructori
    Game();
    ~Game() = default;

    [[nodiscard]] static bool isRunning() ;
    static void setHighScore(const int&);

    /// Functii
    void run();
    static void closeWindow();
    static sf::Vector2f getMousePosition();

    /// Spawners
    void spawnEnemy();
    static void handleDragAndDrop();
    void handleButtonRelease();

    void handleEvents();
    void update();
    void render();
    static void updateMousePosition();

    static void updateHighScore(std::ostream&);
    [[maybe_unused]] static void increaseScore();
    static void increaseResources(int);
    static void decreaseResources(int);

};


#endif //OOP_GAME_H
