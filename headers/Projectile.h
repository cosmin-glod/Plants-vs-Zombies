//
// Created by Cosmin on 14.05.2024.
//

#ifndef OOP_PROJECTILE_H
#define OOP_PROJECTILE_H

#include "Drawable.h"

class Projectile {
private:
    sf::CircleShape body;
    int speed{4};
public:
    explicit Projectile(sf::Vector2f);
    void draw(sf::RenderTarget& target, sf::RenderStates states);
    void move();
    sf::CircleShape getShape() const;
};


#endif //OOP_PROJECTILE_H
