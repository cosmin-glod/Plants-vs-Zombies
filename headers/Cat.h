//
// Created by Cosmin on 14.04.2024.
//

#ifndef OOP_CAT_H
#define OOP_CAT_H
#include <SFML/Graphics.hpp>

class Cat {
private:
    static std::vector<sf::Texture> textures;
protected:
    int hp;
    sf::Sprite image;
public:
    Cat(int, int);
    void drawCat(sf::RenderWindow&);
};


#endif //OOP_CAT_H
