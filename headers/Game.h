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
    sf::Texture slotTexture;
    sf::Texture bigSlotTexture;

    sf::Texture shooterCat;

    sf::Font font;
    sf::Text text;

    std::vector<std::vector<sf::Sprite>> background;
    std::vector<sf::Sprite> bar;
    std::vector<sf::Sprite> cats;

    int resources;
    int score;
    int highScore;

public:
    /// Constructori / Destructori
    Game(const int& highScore_);
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
