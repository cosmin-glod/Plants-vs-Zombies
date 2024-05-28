//
// Created by Cosmin on 13.05.2024.
//

#include "../../headers/Cats/ShooterCat.h"
#include "../../headers/Game.h"

std::vector<Projectile> ShooterCat::projectiles = std::vector<Projectile>();

ShooterCat::ShooterCat() {
    sprite.setTexture(TextureManager::getTexture("textures/cats/shooter-cat.png"));
}

void ShooterCat::run() {
    // Shoots once every fireSpeed seconds;
    sf::Time deltaTime = fireClock.getElapsedTime();
    if (deltaTime >= sf::seconds(projectilesOnceEverySeconds)) {
        projectiles.emplace_back(
            sprite.getPosition() + sf::Vector2f (100.f, 30.f),
            TextureManager::getTexture("textures/projectile.png"));
        fireClock.restart();
    }
//    projectiles.emplace_back(sprite.getPosition(), TextureManager::getTexture("textures/projectile.png"));
}

void ShooterCat::displayProjectiles(sf::RenderTarget &target, sf::RenderStates states) {
    for (auto &projectile : projectiles)
        projectile.draw(target, states);
}

void ShooterCat::moveProjectiles() {
    for (unsigned int i = 0; i < projectiles.size(); ++i) {
        projectiles[i].move();
        std::cout << projectiles[i].getSprite().getPosition().x << '\n';
        if (projectiles[i].getSprite().getPosition().x >= 500.f) {
            projectiles.erase(projectiles.begin() + i);
            --i;
        }
    }
}

void ShooterCat::checkProjectilesCollisions(std::vector<Enemy>& enemies) {
    for (unsigned int i = 0; i < enemies.size(); ++i) {
        for (unsigned int j = 0; j < projectiles.size(); ++j) {
            if (enemies[i].getSprite().getGlobalBounds().intersects(projectiles[j].getSprite().getGlobalBounds())) {
                projectiles.erase(projectiles.begin() + j);
                enemies[i].gotHit();
                if (!enemies[i].isAlive())
                    enemies.erase(enemies.begin() + i);
            }
        }
    }
}
