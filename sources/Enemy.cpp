//
// Created by Cosmin on 14.04.2024.
//

#include "../headers/Enemy.h"


Enemy::Enemy(int l) {
    line = l;

    body.setSize(sf::Vector2f (50.f, 130.f));
    body.setFillColor(sf::Color(214, 208, 100));
    body.setPosition(1450.f, 110.f + float(line) * 150.f);
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) {
    // Draw the body onto the target
    target.draw(body, states);
}

void Enemy::move() {
    body.move(-float(speed), 0.f);
}

