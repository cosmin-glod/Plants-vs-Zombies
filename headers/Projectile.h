//
// Created by Cosmin on 14.05.2024.
//

#ifndef OOP_PROJECTILE_H
#define OOP_PROJECTILE_H

#include "CircleShape.h"

class Projectile : public CircleShape {
private:
    int speed{4};
public:
    explicit Projectile(sf::Vector2f);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    void move() override;
};


#endif //OOP_PROJECTILE_H
