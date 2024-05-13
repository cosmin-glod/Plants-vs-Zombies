//
// Created by Cosmin on 13.05.2024.
//

#ifndef OOP_DRAWABLE_H
#define OOP_DRAWABLE_H

#include <SFML/Graphics.hpp>

class Drawable {
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;
    virtual ~Drawable() = default;
};


#endif //OOP_DRAWABLE_H
