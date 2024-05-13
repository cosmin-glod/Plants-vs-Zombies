//
// Created by Cosmin on 14.04.2024.
//

#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H
#include <random>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Drawable.h"

class Enemy : public Drawable {
protected:
    int line;
    int hp{100};
    int power{10};
    int speed{4};
    sf::Time spawnTime;
public:
    sf::RectangleShape body;
    /// Constructori / Destructori
    explicit Enemy(int);

    void move();

    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
};

#endif //OOP_ENEMY_H
