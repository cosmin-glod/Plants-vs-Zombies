//
// Created by Cosmin on 13.05.2024.
//

#include "../headers/Button.h"

template<typename T>
std::unique_ptr<Cat> Button<T>::entity = nullptr;

template<typename T>
bool Button<T>::dragging = false;

template<typename T>
void Button<T>::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(body, states);
    target.draw(costText, states);
}

template<typename T>
void Button<T>::displayEntity(sf::RenderTarget &target, sf::RenderStates states) {
    if (entity != nullptr)
        target.draw(entity->getShape(), states);
}

template<typename T>
Button<T>::Button(sf::Vector2f size, float x, float y, sf::Color color, int cost_) : cost{cost_} {
    body.setSize(size);
    body.setPosition(x, y);
    body.setFillColor(color);
    body.setOutlineThickness(2.f);
    body.setOutlineColor(sf::Color(165, 42, 42));

    font.loadFromFile("fonts/yoster.ttf");

    costText.setFont(font);
    costText.setScale(0.7f, 0.7f);
    costText.setString(std::to_string(cost));
    costText.setPosition(x + 75.f, y + 70.f);
}

template<typename T>
void Button<T>::drag(sf::Vector2f& mousePosition) {
    entity->setPosition(mousePosition);
}

template<typename T>
void Button<T>::instantiate(sf::Vector2f &mousePosition) {
    dragging = true;
    entity = std::make_unique<T>();
    entity->setPosition(mousePosition);
}

template<typename T>
void Button<T>::place(sf::Vector2f &mousePosition, std::vector<std::unique_ptr<Cat>>& cats, std::vector<std::vector<bool>>& grid) {
        sf::Vector2f tilePos;
        int x = static_cast<int>(mousePosition.x) / 150;
        int y = static_cast<int>(mousePosition.y - 100.f) / 150;

        if (!grid[y][x]) {
            tilePos.x = static_cast<float>(x) * 150.f + 75.f;
            tilePos.y = static_cast<float>(y) * 150.f + 175.f;

            entity->setPosition(tilePos);
            cats.emplace_back(std::move(entity));
            grid[y][x] = true;
        }

        dragging = false;
        entity.reset();
}

template<typename T>
bool Button<T>::isDragging() {
    return dragging;
}

template class Button<ShooterCat>;
template class Button<GeneratorCat>;
template class Button<WallCat>;