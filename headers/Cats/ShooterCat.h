//
// Created by Cosmin on 13.05.2024.
//

#ifndef OOP_SHOOTERCAT_H
#define OOP_SHOOTERCAT_H

#include "../Cat.h"
#include "../Projectile.h"
#include "../Enemy.h"

class ShooterCat : public Cat {
private:
    sf::Color color{sf::Color(202, 209, 12)};
    float projectilesPerSeconds{1.5};
    sf::Clock fireClock;
    static std::vector<Projectile> projectiles;
public:
    ShooterCat();
    void run() override;
    static void displayProjectiles(sf::RenderTarget &target, sf::RenderStates states);
    static void moveProjectiles();
    static void checkProjectilesCollisions(std::vector<Enemy>&);
};


#endif //OOP_SHOOTERCAT_H
