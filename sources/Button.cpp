//
// Created by Cosmin on 13.05.2024.
//

#include "../headers/Button.h"

template<typename T>
void Button<T>::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(body, states);
    if (entity != nullptr)
        target.draw(entity->getShape(), states);
}

template<typename T>
Button<T>::Button(sf::Vector2f size, float x, float y, sf::Color color, bool draggable_) : draggable{draggable_}, entity{nullptr} {
    body.setSize(size);
    body.setPosition(x, y);
    body.setFillColor(color);
    body.setOutlineThickness(2.f);
    body.setOutlineColor(sf::Color(165, 42, 42));
}

template<typename T>
void Button<T>::dragAndDrop(std::vector<std::vector<bool>>& grid, std::vector<std::unique_ptr<Cat>> &cats, sf::Vector2f& mousePosition) {
    if (draggable) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//            std::cout << "Pressed\n";
            if (body.getGlobalBounds().contains(mousePosition)) {
                if (!isDragging) {
                    isDragging = true;
                    entity = std::make_unique<T>();
                    entity->setPosition(mousePosition);
                }
            }
            if (isDragging) {
                entity->setPosition(mousePosition);
            }
        }
        else if (isDragging) {
            //std::cout << "Released\n";
            isDragging = false;

            sf::Vector2f tilePos;
            //std::cout << mousePosition.x << ' ' << mousePosition.y << '\n';
            if (mousePosition.y >= 100.f) {
                int x = int(mousePosition.x) / 150;
                int y = int(mousePosition.y - 100.f) / 150;
                if (!grid[y][x]) {
                    tilePos.x = float(x) * 150.f + 75.f;
                    tilePos.y = float(y) * 150.f + 175.f;
                    entity->setPosition(sf::Vector2f(tilePos));
                    cats.push_back(std::move(entity));
                    grid[y][x] = true;
                }
            }
            //std::cout << cats.size() << '\n';
            entity = nullptr;
        }
    }
}


//void handleEvent(sf::Event event, sf::RenderWindow& window) {
//    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//        if (shape.getGlobalBounds().contains(mousePosition)) {
//            isDragging = true;
//            offset = shape.getPosition() - mousePosition;
//        }
//    } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
//        isDragging = false;
//    } else if (event.type == sf::Event::MouseMoved && isDragging) {
//        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//        shape.setPosition(mousePosition + offset);
//    }
//}
//
//void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
//target.draw(shape, states);
//}