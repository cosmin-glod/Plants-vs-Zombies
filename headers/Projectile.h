//
// Created by Cosmin on 14.05.2024.
//

#ifndef OOP_PROJECTILE_H
#define OOP_PROJECTILE_H

#include "Drawable.h"
#include "TextureManager.h"

class Projectile : public Drawable {
private:
    int speed{4};
    sf::Sprite sprite;
public:
    explicit Projectile(sf::Vector2f, const sf::Texture&);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;
    void move();
};


#endif //OOP_PROJECTILE_H
