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
#include "ObjectPool.h"

template<typename T>
class Button : public Drawable{
    static std::unique_ptr<T> entity;
    [[maybe_unused]] static bool dragging;
    sf::Font font;
    static int cost;
    sf::Text costText;
public:
    Button(sf::Texture&, sf::Vector2f);
    void draw(sf::RenderTarget& target, sf::RenderStates states) override;

    static void drag(const sf::Vector2f&);
    static void place(sf::Vector2f&, ObjectPool&);
    static void instantiate(sf::Vector2f&);
    static bool isDragging();
    static void displayEntity(sf::RenderTarget&, sf::RenderStates);
    static void deleteEntity();
    static int getCost();
};

#endif //OOP_BUTTON_H
