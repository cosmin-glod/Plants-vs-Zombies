//
// Created by Cosmin on 20.06.2024.
//

#include "../headers/ObjectPool.h"


void ObjectPool::run() {
    for (auto &linie : pool) {
        for (auto &c : linie) {
            if (c != nullptr && !dynamic_cast<WallCat*>(c.get()))
                c->run();
        }
    }
}

void ObjectPool::enemyCollision(std::vector<Enemy>& enemies) {

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (pool[i][j]) {

                for (auto &enemy: enemies) {
                    if (enemy.getSprite().getGlobalBounds().intersects(pool[i][j]->getSprite().getGlobalBounds())) {
//                std::cout << "am intrat\n";
                        pool[i][j]->gotHit();
//                std::cout << cats[i]->getHealth() << '\n';
                        enemy.cannotMoveAnymore();
                        if (!pool[i][j]->isAlive()) {
//                    std::cout << cats[j]->getY() << ' ' << cats[j]->getX() << '\n';
                            pool[i][j].reset();
                            --j;
                        }
                    }
                }

            }
        }
    }
}

void ObjectPool::draw(sf::RenderTarget& target, sf::RenderStates states) {
    for (auto &linie : pool) {
        for (auto &c : linie) {
            if (c != nullptr)
                c->draw(target, states);
        }
    }
}
