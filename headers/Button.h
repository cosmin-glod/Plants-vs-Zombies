//
// Created by Cosmin on 13.05.2024.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H

#include "SFML/Graphics.hpp"
#include "Drawable.h"
#include "Cats/ShooterCat.h"
#include "Cats/GeneratorCat.h"
#include "Cats/WallCat.h"

template<typename T>
class Button : public Drawable{
    bool draggable;
    bool isDragging{false};
    static std::unique_ptr<Cat> entity;
    sf::Font font;
    sf::Text costText;
public:
    Button(sf::Vector2f, float, float, sf::Color, int, bool);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;

    //void spawnEntity(sf::Vector2f&);
    void dragAndDrop(std::vector<std::vector<bool>>&, std::vector<std::unique_ptr<Cat>>&, sf::Vector2f&);
};


template class Button<ShooterCat>;
template class Button<GeneratorCat>;
template class Button<WallCat>;
#endif //OOP_BUTTON_H
