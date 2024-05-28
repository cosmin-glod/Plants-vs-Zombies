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
    sf::Sprite sprite;
public:
    Drawable() = default;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
    sf::Sprite getSprite();
    virtual ~Drawable() = default;
    void setter(sf::Texture&, sf::Vector2f);
};

#endif //OOP_DRAWABLE_H
