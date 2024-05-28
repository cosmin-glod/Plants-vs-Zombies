//
// Created by Cosmin on 14.05.2024.
//

#include "../../headers/Cats/GeneratorCat.h"
#include "../../headers/Game.h"

std::vector<Whiskas> GeneratorCat::resources = std::vector<Whiskas>();

GeneratorCat::GeneratorCat() {
    sprite.setTexture(TextureManager::getTexture("textures/cats/generator-cat.png"));
};

void GeneratorCat::run() {
    sf::Time deltaTime = generateClock.getElapsedTime();
    if (deltaTime >= sf::seconds(whiskasOnceEverySeconds)) {
        resources.emplace_back(TextureManager::getTexture("textures/whiskas.png"), sprite.getPosition() + sf::Vector2f(25.f, 50.f));
        generateClock.restart();
    }
}

void GeneratorCat::displayWhiskas(sf::RenderWindow& target, sf::RenderStates states) {
    for (auto &whiskas : resources) {
        whiskas.draw(target, states);
    }
}

void GeneratorCat::collectWhiskas() {
    for (unsigned int i = 0; i < resources.size(); ++i) {
        if (resources[i].getSprite().getGlobalBounds().contains(Game::getMousePosition())) {
            resources.erase(resources.begin() + i);
            Game::increaseResources(25);
            break;
        }
    }
}
