//
// Created by Cosmin on 14.04.2024.
//

#include "../headers/Cat.h"

void Cat::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(body, states);
}

Cat::Cat(sf::Color color) {
    body.setSize(sf::Vector2f (100.f, 100.f));
    body.setFillColor(color);
}
