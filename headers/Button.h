//
// Created by Cosmin on 13.05.2024.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H

#include "SFML/Graphics.hpp"
#include "Drawable.h"

class Button : public Drawable{
    sf::RectangleShape body;
public:
    Button(sf::Vector2f, float, float, sf::Color);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
};


#endif //OOP_BUTTON_H
