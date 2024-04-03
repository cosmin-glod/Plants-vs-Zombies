#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include <Helper.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Plants vs. Zombies", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev{};

    while (window.isOpen()) {

        while (window.pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                default:
                    break;
            }
        }
        /// Update


        /// Render
        window.clear(sf::Color::Black); /// Clear old frame

        /// Draw

        /// Display
        window.display();
    }
    return 0;
}
