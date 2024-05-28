//
// Created by Cosmin on 14.05.2024.
//

#include "../headers/Projectile.h"

void Projectile::move() {
    sprite.move(static_cast<float>(speed), 0.f);
    std::cout << "poz : " << sprite.getPosition().x << '\n';
}

Projectile::Projectile(sf::Vector2f position, const sf::Texture& texture) {
    sprite.setTexture(texture); // Set the texture to the CircleShape

//    body.setRadius(20.f);
    sprite.setPosition(position);
    std::cout << sprite.getPosition().x << '\n';
//    body.setFillColor(sf::Color(128,128,128));

    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Projectile::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(sprite, states);
}

