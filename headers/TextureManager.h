#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "Exception.h"

class TextureManager {
public:
    static sf::Texture& getTexture(const std::string& filename);

private:
    static std::map<std::string, sf::Texture> textures;
};

#endif // RESOURCE_MANAGER_H
