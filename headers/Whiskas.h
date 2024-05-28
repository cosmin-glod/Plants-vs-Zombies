//
// Created by Cosmin on 15.05.2024.
//

#ifndef OOP_WHISKAS_H
#define OOP_WHISKAS_H

#include "CircleShape.h"

class Whiskas : public CircleShape {
private:
    sf::Color color{sf::Color(255,90,54)};
    float speed;
public:
    explicit Whiskas(sf::Vector2f, float speed_ = 0);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    void move() override;
};


#endif //OOP_WHISKAS_H
