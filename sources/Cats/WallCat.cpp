//
// Created by Cosmin on 14.05.2024.
//

#include "../../headers/Cats/WallCat.h"

WallCat::WallCat(sf::Vector2f position) : Cat(position, 2000) {
    sprite.setTexture(TextureManager::getTexture("textures/cats/wall-cat.png"));
}