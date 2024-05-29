//
// Created by Cosmin on 13.05.2024.
//

#include "../headers/Button.h"

template<typename T>
std::shared_ptr<Cat> Button<T>::entity = nullptr;

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
Button<T>::Button(sf::Texture& texture, sf::Vector2f position, int cost_) : cost{cost_} {
    sprite.setTexture(texture);
    sprite.setPosition(position);

    font.loadFromFile("fonts/yoster.ttf");

    costText.setFont(font);
    costText.setScale(0.7f, 0.7f);
    costText.setString(std::to_string(cost));
    costText.setPosition(position + sf::Vector2f (75.f, 70.f));
}

template<typename T>
void Button<T>::drag(sf::Vector2f& mousePosition) {
    entity->setPosition(mousePosition);
}

template<typename T>
void Button<T>::instantiate(sf::Vector2f &mousePosition) {
    dragging = true;
    entity = std::make_shared<T>(mousePosition);
}

template<typename T>
void Button<T>::place(sf::Vector2f &mousePosition, std::vector<std::shared_ptr<Cat>>& cats, std::vector<std::vector<bool>>& grid) {
        sf::Vector2f tilePos;
        int x = static_cast<int>(mousePosition.x) / 150;
        int y = static_cast<int>(mousePosition.y - 100.f) / 150;

//        std::cout << x << ' ' << y << '\n';
        if (x < 0 || y < 0 || x >= 10 || y >= 5)
            throw InvalidPosition("Tile position (" + std::to_string(x) + ", " + std::to_string(y) + ") is invalid !");
        if (!grid[y][x]) {
            tilePos.x = static_cast<float>(x) * 150.f + 55.f;
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