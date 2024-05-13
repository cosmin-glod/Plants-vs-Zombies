//
// Created by Cosmin on 13.05.2024.
//

#include "../headers/Button.h"

template<typename T>
void Button<T>::draw(sf::RenderTarget &target, sf::RenderStates states) {
    target.draw(body, states);
}

template<typename T>
Button<T>::Button(sf::Vector2f size, float x, float y, sf::Color color, bool draggable_) : draggable{draggable_} {
    body.setSize(size);
    body.setPosition(x, y);
    body.setFillColor(color);
    body.setOutlineThickness(2.f);
    body.setOutlineColor(sf::Color(165, 42, 42));
}

template<typename T>
void Button<T>::spawnEntity() {
    if (draggable) {

    }
}

template<typename T>
void Button<T>::dragging(sf::Vector2f& mousePosition) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (body.getGlobalBounds().contains(mousePosition)) {
            isDragging = true;
            std::cout << "apasat\n";
        }
    }
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        isDragging = false;
        std::cout << "Released\n";
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