//
// Created by Cosmin on 13.05.2024.
//

#include "../headers/Drawable.h"

sf::Sprite Drawable::getSprite() {
    return sprite;
}

void Drawable::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(sprite, states);
}

void Drawable::setter(sf::Texture& texture, sf::Vector2f position) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
}
