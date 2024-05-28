//
// Created by Cosmin on 14.04.2024.
//

#ifndef OOP_CAT_H
#define OOP_CAT_H
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Projectile.h"

class Cat : public Drawable {
protected:
    sf::Texture texture;
//    int health{100};
//    int cost;
public:
    Cat() = default;
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    void setPosition(sf::Vector2f);
    virtual void run() = 0;
    //int getCost() const;
};


#endif //OOP_CAT_H
