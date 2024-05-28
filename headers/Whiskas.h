//
// Created by Cosmin on 15.05.2024.
//

#ifndef OOP_WHISKAS_H
#define OOP_WHISKAS_H

#include "Drawable.h"

class Whiskas : public Drawable {
private:
    sf::Color color{sf::Color(255,90,54)};
    float speed;
public:
    explicit Whiskas(sf::Texture&, sf::Vector2f, float speed_ = 0);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    void move();
};


#endif //OOP_WHISKAS_H
