//
// Created by Cosmin on 13.05.2024.
//

#include "../headers/Button.h"

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(body, states);
}

Button::Button(sf::Vector2f size, float x, float y, sf::Color color) {
    body.setSize(size);
    body.setPosition(x, y);
    body.setFillColor(color);
    body.setOutlineThickness(2.f);
    body.setOutlineColor(sf::Color(165, 42, 42));
}
