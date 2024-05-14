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
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;
    sf::RectangleShape getShape() const;
    virtual ~Drawable() = default;
};


#endif //OOP_DRAWABLE_H
