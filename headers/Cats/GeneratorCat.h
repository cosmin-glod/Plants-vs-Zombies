//
// Created by Cosmin on 14.05.2024.
//

#ifndef OOP_GENERATORCAT_H
#define OOP_GENERATORCAT_H

#include "../Cat.h"

class GeneratorCat : public Cat {
private:
public:
    GeneratorCat();
    void run(std::vector<Projectile>&) override;
};


#endif //OOP_GENERATORCAT_H
