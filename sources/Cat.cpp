//
// Created by Cosmin on 14.04.2024.
//

#include "../headers/Cat.h"

void Cat::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(sprite, states);
}

void Cat::setPosition(sf::Vector2f position) {
    sprite.setPosition(position + sf::Vector2f (-50.f, -50.f));
}

Cat::Cat(sf::Vector2f position) : Drawable(position) {}

bool Cat::isAlive() const {
    return health > 0;
}

void Cat::gotHit() {
    --health;
}

//int Cat::getHealth() const {
//    return health;
//}

Cat::Cat(sf::Vector2f position, int health_) : Drawable(position), health{health_} {}

float Cat::getX() const {
    return sprite.getPosition().x;
}

float Cat::getY() const {
    return sprite.getPosition().y;
}

//int Cat::getCost() const {
//    return cost;
//}
