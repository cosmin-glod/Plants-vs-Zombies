#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <vector>
#include <memory>
#include <iostream>
#include <typeinfo>
#include "Cat.h"
#include "Cats/WallCat.h"
#include "Enemy.h"

class ObjectPool {
private:
    size_t rows, cols;
    std::vector< std::vector< std::unique_ptr<Cat> > > pool;

public:
    explicit ObjectPool(size_t r, size_t c) : rows(r), cols(c) {
        pool.resize(r);
        for (size_t i = 0; i < r; ++i) {
            pool[i].resize(c);
            for (size_t j = 0; j < c; ++j)
                pool[i][j] = nullptr;
        }
    }

    template<typename T>
    void create(std::unique_ptr<T> c, int x, int y) {
        if (pool[x][y] == nullptr) {
            pool[x][y] = std::move(c);
        } else {
            throw OccupiedPosition("Tile position (" + std::to_string(y) + ", " + std::to_string(x) + ") is occupied!\n");
        }
    }

    void release(int x, int y) {
        pool[x][y].reset();
    }

    void run();
    void enemyCollision(std::vector<Enemy> &enemies);
    void draw(sf::RenderTarget& target, sf::RenderStates states);
};

#endif // OBJECT_POOL_H
