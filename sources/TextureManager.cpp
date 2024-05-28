//
// Created by Cosmin on 28.05.2024.
//

#include "../headers/TextureManager.h"

std::map<std::string, sf::Texture> TextureManager::textures;

sf::Texture &TextureManager::getTexture(const std::string &filename) {
    auto it = textures.find(filename);
    if (it != textures.end()) {
        return it->second;
    } else {
        sf::Texture texture;
        if (!texture.loadFromFile(filename)) {
            throw std::runtime_error("Failed to load texture: " + filename);
        }
        textures[filename] = texture;
        return textures[filename];
    }
}
