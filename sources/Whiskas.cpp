//
// Created by Cosmin on 15.05.2024.
//

#include "../headers/Whiskas.h"

void Whiskas::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(body, states);
}

void Whiskas::move() {
    body.move(0, speed);
}

Whiskas::Whiskas(sf::Vector2f position, float speed_) : speed{speed_} {
    body.setFillColor(color);
    body.setPosition(position);
    body.setRadius(25.f);
}
