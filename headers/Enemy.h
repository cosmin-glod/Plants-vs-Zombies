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
    float hp{3};
    float speed;
    sf::Time spawnTime;
public:
    /// Constructori / Destructori
    explicit Enemy(int, float);

    void move();

    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    bool isAlive() const;
    void gotHit();
};

#endif //OOP_ENEMY_H
