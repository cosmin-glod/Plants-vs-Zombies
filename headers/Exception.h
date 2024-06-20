//
// Created by Cosmin on 29.05.2024.
//

#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

#include <stdexcept>
#include <iostream>
#include <string>

class GeneralException : public std::runtime_error {
public:
    explicit GeneralException(const std::string& err);
};

class MissingTexture : public GeneralException {
public:
    explicit MissingTexture(const std::string& err);
};

class MissingFont : public GeneralException {
public:
    explicit MissingFont(const std::string& err);
};

class InvalidPosition : public GeneralException {
public:
    explicit InvalidPosition(const std::string& err);
};

class OccupiedPosition : public GeneralException {
public:
    explicit OccupiedPosition(const std::string& err);
};

#endif //OOP_EXCEPTION_H