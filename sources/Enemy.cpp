//
// Created by Cosmin on 14.04.2024.
//

#include "../headers/Enemy.h"
#include "../headers/Game.h"


Enemy::Enemy(sf::Texture& texture, int l, float speed_) : line{l}, speed{speed_}{

    sprite.setTexture(texture);
    sprite.setPosition(1450.f, 110.f + float(line) * 150.f);
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) {
    // Draw the body onto the target
    target.draw(sprite, states);
}

void Enemy::move() {
    if (canMove)
        sprite.move(-float(speed), 0.f);
}

bool Enemy::isAlive() const {
    return hp > 0;
}

void Enemy::gotHit() {
    --hp;
    Game::increaseScore();
}

void Enemy::cannotMoveAnymore() {
    canMove = false;
}

void Enemy::nowCanMove() {
    canMove = true;
}

Enemy::Enemy(sf::Texture &t, int l, float h, float s) : line{l}, hp{h}, speed{s} {
    sprite.setTexture(t);
    sprite.setPosition(1450.f, 110.f + float(line) * 150.f);
}