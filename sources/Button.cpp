//
// Created by Cosmin on 13.05.2024.
//

#include "../headers/Button.h"

template<typename T>
std::unique_ptr<T> Button<T>::entity = nullptr;

template<> int Button<ShooterCat>::cost = 100;
template<> int Button<GeneratorCat>::cost = 50;
template<> int Button<WallCat>::cost = 250;

template<typename T>
bool Button<T>::dragging = false;

template<typename T>
void Button<T>::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(sprite, states);
    target.draw(costText, states);
}

template<typename T>
void Button<T>::displayEntity(sf::RenderTarget &target, sf::RenderStates states) {
    if (entity != nullptr)
        target.draw(entity->getSprite(), states);
}

template<typename T>
Button<T>::Button(sf::Texture& texture, sf::Vector2f position) {
    sprite.setTexture(texture);
    sprite.setPosition(position);

    font.loadFromFile("fonts/yoster.ttf");

    costText.setFont(font);
    costText.setScale(0.7f, 0.7f);
    costText.setString(std::to_string(cost));
    costText.setPosition(position + sf::Vector2f (75.f, 70.f));
}

template<typename T>
void Button<T>::drag(const sf::Vector2f& mousePosition) {
    entity->setPosition(mousePosition);
}

template<typename T>
void Button<T>::instantiate(sf::Vector2f &mousePosition) {
    dragging = true;
    entity = std::make_unique<T>(mousePosition);
}

template<typename T>
void Button<T>::place(sf::Vector2f &mousePosition, ObjectPool& cats) {
        sf::Vector2f tilePos;
        int j = static_cast<int>(mousePosition.x) / 150;
        int i = static_cast<int>(mousePosition.y - 100.f) / 150;

//        std::cout << x << ' ' << y << '\n';
        if (i < 0 || j < 0 || i >= 5 || j >= 10)
            throw InvalidPosition("Tile position (" + std::to_string(i) + ", " + std::to_string(j) + ") is invalid !\n");

        tilePos.x = static_cast<float>(j) * 150.f + 55.f;
        tilePos.y = static_cast<float>(i) * 150.f + 175.f;

        entity->setPosition(tilePos);
        cats.create(std::move(entity), i, j);
        deleteEntity();
}

template<typename T>
bool Button<T>::isDragging() {
    return dragging;
}

template<typename T>
void Button<T>::deleteEntity() {
    dragging = false;
    entity.reset();
}

template<typename T>
int Button<T>::getCost() {
    return cost;
}


template class Button<ShooterCat>;
template class Button<GeneratorCat>;
template class Button<WallCat>;