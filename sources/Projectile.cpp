//
// Created by Cosmin on 14.05.2024.
//

#include "../headers/Projectile.h"

void Projectile::move() {
    body.move(float(speed), 0.f);
}

Projectile::Projectile(sf::Vector2f position) {
    body.setRadius(20.f);
    body.setPosition(position);
    body.setFillColor(sf::Color(128,128,128));
}

void Projectile::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(body, states);
}

sf::CircleShape Projectile::getShape() const {
    return body;
}
