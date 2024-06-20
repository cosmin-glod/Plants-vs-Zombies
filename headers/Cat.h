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
    int health{200};
public:
    Cat() = default;
    explicit Cat(sf::Vector2f);
    Cat(sf::Vector2f, int);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    void setPosition(sf::Vector2f);
    virtual void run() = 0;

    bool isAlive() const;
    void gotHit();

    float getX() const;
    float getY() const;

//    [[maybe_unused]] int getHealth() const;
};


#endif //OOP_CAT_H
