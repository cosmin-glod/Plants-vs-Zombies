//
// Created by Cosmin on 14.05.2024.
//

#ifndef OOP_WALLCAT_H
#define OOP_WALLCAT_H

#include "../Cat.h"

class WallCat : public Cat {
private:
    sf::Color color{sf::Color(12, 182, 209)};
public:
    WallCat();
    void run() override;
};


#endif //OOP_WALLCAT_H
