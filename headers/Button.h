//
// Created by Cosmin on 13.05.2024.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H

#include "SFML/Graphics.hpp"
#include "Drawable.h"
#include "Cats/ShooterCat.h"

template<typename T>
class Button : public Drawable{
    T entity;
    bool draggable;
    bool isDragging{false};
public:
    Button(sf::Vector2f, float, float, sf::Color, bool);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;

    void spawnEntity();
    void dragging(sf::Vector2f&);
};

template class Button<ShooterCat>;
#endif //OOP_BUTTON_H
