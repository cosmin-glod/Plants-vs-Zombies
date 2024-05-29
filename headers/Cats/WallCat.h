//
// Created by Cosmin on 14.05.2024.
//

#ifndef OOP_WALLCAT_H
#define OOP_WALLCAT_H

#include "../Cat.h"

class WallCat : public Cat {
private:
public:
    explicit WallCat(sf::Vector2f);
    void run() override {};
};


#endif //OOP_WALLCAT_H
