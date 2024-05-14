//
// Created by Cosmin on 14.04.2024.
//

#ifndef OOP_CAT_H
#define OOP_CAT_H
#include <SFML/Graphics.hpp>
#include "Drawable.h"

class Cat : public Drawable {
protected:
    int health{100};
public:
    explicit Cat(sf::Color);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    void setPosition(sf::Vector2f);
    virtual void run() = 0;
};


#endif //OOP_CAT_H
