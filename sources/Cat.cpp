//
// Created by Cosmin on 14.04.2024.
//

#include "../headers/Cat.h"
#include <iostream>

Cat::Cat(int i, int j) {
    std::cout << "Pisica instantiata\n";
    image.setPosition(150.f * float(j), 150.f * float(i) + 100.f);
}

void Cat::drawCat(sf::RenderWindow &window) {
    window.draw(image);
}


