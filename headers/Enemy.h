//
// Created by Cosmin on 14.04.2024.
//

#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H
#include <random>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "TextureManager.h"

class Enemy : public Drawable {
protected:
    int line;
    float hp;
    float speed;
    sf::Time spawnTime;
    bool canMove{true};
public:
    /// Constructori / Destructori
    explicit Enemy(sf::Texture&, int, float);
    Enemy(sf::Texture&, int, float, float);

    void move();

    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    bool isAlive() const;
    void gotHit();
    void cannotMoveAnymore();
    void nowCanMove();
};

class EnemyFactory : public Enemy {
public:
    static Enemy EasyEnemy(int l) { return Enemy(TextureManager::getTexture("textures/box1.png"), l, 9.f, 0.5f); }
    static Enemy MediumEnemy(int l) { return Enemy(TextureManager::getTexture("textures/box2.png"), l, 12.f, 0.3f); }
    static Enemy HardEnemy(int l) { return Enemy(TextureManager::getTexture("textures/box3.png"), l, 15.f, 0.2f); }
};


#endif //OOP_ENEMY_H
