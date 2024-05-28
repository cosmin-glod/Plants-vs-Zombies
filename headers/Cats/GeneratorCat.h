//
// Created by Cosmin on 14.05.2024.
//

#ifndef OOP_GENERATORCAT_H
#define OOP_GENERATORCAT_H

#include "../Cat.h"
#include "../Whiskas.h"

class GeneratorCat : public Cat {
private:
    sf::Color color{sf::Color(12, 209, 28)};
    sf::Clock generateClock;
    float whiskasOnceEverySeconds{15};
    static std::vector<Whiskas> resources;
public:
    GeneratorCat();
    void run() override;
    static void displayWhiskas(sf::RenderWindow&, sf::RenderStates);
    static void collectWhiskas();
};


#endif //OOP_GENERATORCAT_H
