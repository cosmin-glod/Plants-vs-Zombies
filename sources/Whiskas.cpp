//
// Created by Cosmin on 15.05.2024.
//

#include "../headers/Whiskas.h"

void Whiskas::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(sprite, states);
}

void Whiskas::move() {
    sprite.move(0, speed);
}

Whiskas::Whiskas(sf::Texture& texture, sf::Vector2f position, float speed_) : speed{speed_} {
    sprite.setTexture(texture);
    sprite.setPosition(position);
}
