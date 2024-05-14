//
// Created by Cosmin on 13.05.2024.
//

#include "../headers/Drawable.h"

sf::RectangleShape Drawable::getShape() const {
    return body;
}

void Drawable::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(body, states);
}

void Drawable::setter(sf::Vector2f size, sf::Vector2f position, sf::Color color) {
    body.setSize(size);
    body.setPosition(position);
    body.setFillColor(color);
    body.setOutlineColor(sf::Color(165, 42, 42));
    body.setOutlineThickness(2.f);
}
