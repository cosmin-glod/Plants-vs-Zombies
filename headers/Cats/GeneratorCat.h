//
// Created by Cosmin on 14.05.2024.
//

#ifndef OOP_GENERATORCAT_H
#define OOP_GENERATORCAT_H

#include "../Cat.h"
#include "../Whiskas.h"

class GeneratorCat : public Cat {
private:
    sf::Clock generateClock;
    float whiskasOnceEverySeconds{7};
    static std::vector<Whiskas> resources;
public:
    explicit GeneratorCat(sf::Vector2f);
    void run() override;
    static void displayWhiskas(sf::RenderWindow&, sf::RenderStates);
    static void collectWhiskas();
};


#endif //OOP_GENERATORCAT_H
