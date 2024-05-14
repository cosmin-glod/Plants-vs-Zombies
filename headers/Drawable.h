//
// Created by Cosmin on 13.05.2024.
//

#ifndef OOP_DRAWABLE_H
#define OOP_DRAWABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <cmath>

class Drawable {
protected:
    sf::RectangleShape body;
public:
    Drawable() = default;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
    virtual sf::RectangleShape getShape() const;
    virtual ~Drawable() = default;
    void setter(sf::Vector2f, sf::Vector2f, sf::Color);
};

#endif //OOP_DRAWABLE_H
