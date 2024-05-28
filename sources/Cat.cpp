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

//int Cat::getCost() const {
//    return cost;
//}
