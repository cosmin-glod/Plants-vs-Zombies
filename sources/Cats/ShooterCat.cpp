//
// Created by Cosmin on 13.05.2024.
//

#include "../../headers/Cats/ShooterCat.h"

ShooterCat::ShooterCat() : Cat(sf::Color(202, 209, 12)) { }

void ShooterCat::run(std::vector<Projectile>& projectiles) {
    /// Shoots once every fireSpeed seconds;
    sf::Time deltaTime = fireClock.getElapsedTime();
    if (deltaTime >= sf::seconds(projectilesPerSeconds)) {
        projectiles.emplace_back(body.getPosition() + sf::Vector2f (100.f, 30.f));
        fireClock.restart();
    }
}
