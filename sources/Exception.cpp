//
// Created by Cosmin on 29.05.2024.
//

#include "../headers/Exception.h"

GeneralException::GeneralException(const std::string& err) : std::runtime_error(err) {
    if (!err.empty()) {
        std::cerr << err << '\n';
    }
}

MissingFont::MissingFont(const std::string& err) : GeneralException(err) {}

MissingTexture::MissingTexture(const std::string& err) : GeneralException(err) {}

InvalidPosition::InvalidPosition(const std::string &err) : GeneralException(err) {}