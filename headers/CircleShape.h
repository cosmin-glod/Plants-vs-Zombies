//
// Created by Cosmin on 15.05.2024.
//

#ifndef OOP_CIRCLESHAPE_H
#define OOP_CIRCLESHAPE_H

#include <SFML/Graphics.hpp>

class CircleShape {
protected:
    sf::CircleShape body;
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;
    virtual void move() = 0;
    sf::CircleShape getShape() const;
};


#endif //OOP_CIRCLESHAPE_H
