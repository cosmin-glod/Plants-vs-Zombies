//
// Created by Cosmin on 13.05.2024.
//

#ifndef OOP_SHOOTERCAT_H
#define OOP_SHOOTERCAT_H

#include "../Cat.h"
#include "../Projectile.h"

class ShooterCat : public Cat {
private:
    float projectilesPerSeconds{5};
    sf::Clock fireClock;
public:
    ShooterCat();
    void run(std::vector<Projectile>&) override;
};


#endif //OOP_SHOOTERCAT_H
