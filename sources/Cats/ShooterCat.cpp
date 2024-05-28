//
// Created by Cosmin on 13.05.2024.
//

#include "../../headers/Cats/ShooterCat.h"
#include "../../headers/Game.h"

std::vector<Projectile> ShooterCat::projectiles = std::vector<Projectile>();

ShooterCat::ShooterCat() : Cat(100) {
    body.setFillColor(color);
}

void ShooterCat::run() {
    /// Shoots once every fireSpeed seconds;
    sf::Time deltaTime = fireClock.getElapsedTime();
    if (deltaTime >= sf::seconds(projectilesPerSeconds)) {
        projectiles.emplace_back(body.getPosition() + sf::Vector2f (100.f, 30.f));
        fireClock.restart();
    }
}

void ShooterCat::displayProjectiles(sf::RenderTarget &target, sf::RenderStates states) {
    for (auto &projectile : projectiles)
        projectile.draw(target, states);
}

void ShooterCat::moveProjectiles() {
    for (unsigned int i = 0; i < projectiles.size(); ++i) {
        projectiles[i].move();
        if (projectiles[i].getShape().getPosition().x >= 1480.f)
            projectiles.erase(projectiles.begin() + i);
    }
}

void ShooterCat::checkProjectilesCollisions(std::vector<Enemy>& enemies) {
    for (unsigned int i = 0; i < enemies.size(); ++i) {
        for (unsigned int j = 0; j < projectiles.size(); ++j) {
            if (enemies[i].getShape().getGlobalBounds().intersects(projectiles[j].getShape().getGlobalBounds())) {
                projectiles.erase(projectiles.begin() + j);
                enemies[i].gotHit();
                if (!enemies[i].isAlive())
                    enemies.erase(enemies.begin() + i);
            }
        }
    }
}
